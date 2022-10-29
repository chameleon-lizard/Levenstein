#include <cstdio>
#include <cstring>
#include "levenshtein.h"

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
    else if (strncmp(argv[1], "Iterative", strlen("Iterative")) == 0)
    {
        printf("Distance: %d\n", levenshtein_wagner_fisher(argv[2], argv[3]));
    } else {
    	printf("None of available algorithmgs chosen\n");
    }

    return 0;
}

