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
    Params:
        - Needle;
        - Haystack;
*/
int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        printf("Not enough params.\n");
        return 1;
    }

    printf("Distance: %d\n", levenshtein_recursive(argv[2], argv[3]));
    return 0;
}