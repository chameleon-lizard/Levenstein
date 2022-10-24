#include <string.h>
#include <stdio.h>

// min(a, b, c) <-> min(a, min(b, c))
int min(int a, int b, int c)
{
    return a < b ? (a < c ? a : c) : (b < c ? b : c);
}

/*
    Naive recursive implementation:
    https://en.wikipedia.org/wiki/Levenshtein_distance#Recursive
*/
int levenshtein_recursive(char *needle, char *haystack)
{
    if (strlen(needle) == 0 && strlen(haystack) == 0)
    {
        return 0;
    }
    else if (strlen(needle) == 0)
    {
        return strlen(haystack);
    }
    else if (strlen(haystack) == 0)
    {
        return strlen(needle);
    }
    else if (needle[0] == haystack[0])
    {
        return levenshtein_recursive(needle + 1, haystack + 1);
    }
    else
    {
        return 1 + min(
                       levenshtein_recursive(needle + 1, haystack),
                       levenshtein_recursive(needle, haystack + 1),
                       levenshtein_recursive(needle + 1, haystack + 1));
    }
}

/* 
    Wagner-fischer algorythm modification with two matrix rows:
    https://en.wikipedia.org/wiki/Levenshtein_distance#Iterative_with_two_matrix_rows
*/
int levenshtein_wagner_fisher(char *needle, char *haystack)
{
    // Finding the lengths of the strings.
    size_t n = strlen(haystack) + 1;
    size_t m = strlen(needle) + 1;

    // Creating distance vectors.
    auto v1 = new int[n + 1];
    auto v2 = new int[n + 1];

    // Initializing the first vector with numbers meaning the edit distance
    // from empty haystack.
    for (auto i = 0; i < n + 1; i++)
    {
        v1[i] = i;
    }

    for (auto i = 0; i < m - 1; i++)
    {
        // Calculating the edit distances from previous vector to current.
        v2[0] = i + 1;

        // Using the specified formula to fill in the rest.
        for (auto j = 0; j < n - 1; j++)
        {
            v2[j+1] = min(
                            v1[j + 1] + 1,
                            v2[j] + 1,
                            needle[i] == haystack[j] ? v1[j] : v1[j] + 1
                        );
        }

        // Swapping v1 and v2.
        int temp = 0;
        for (auto i = 0; i < n + 1; i++)
        {
            temp = v1[i];
            v1[i] = v2[i];
            v2[i] = temp;
        }
    }

    int result = v1[n-1];

    // Cleanup.
    delete v1;
    delete v2;

    return result;
}


/*
    Params:
        - Name of function (e.g. "Recursive" or "Iterative");
        - Needle;
        - Haystack;
*/
int main(int argc, char *argv[])
{
    if (argc != 4)
    {
        printf("Not enough params.\n");
        return 1;
    }

    if (strncmp(argv[1], "Recursive", strlen("Recursive")) == 0)
    {
        printf("Distance: %d\n", levenshtein_recursive(argv[2], argv[3]));
    }
    else
    {
        printf("Distance: %d\n", levenshtein_wagner_fisher(argv[2], argv[3]));
    }

    return 0;
}