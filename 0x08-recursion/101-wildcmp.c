#include "main.h"

/**
 * wildcmp - Compares two strings and returns 1 if identical, otherwise 0
 * @s1: First string
 * @s2: Second string, may contain wildcard *
 *
 * Return: 1 if identical, 0 otherwise
 */

int wildcmp(char *s1, char *s2)
{
    /* If both strings are empty, they are identical */
    if (*s1 == '\0' && *s2 == '\0')
        return (1);

    /* If the current characters match, compare the next characters */
    if (*s1 == *s2)
        return (wildcmp(s1 + 1, s2 + 1));

    /* If the wildcard is encountered in s2, move past it and compare */
    if (*s2 == '*')
    {
        /* If the wildcard is at the end of s2, it matches any remaining s1 */
        if (*(s2 + 1) == '\0')
            return (1);

        /* Otherwise, recursively try every s1 after matching the wildcard */
        while (*s1 != '\0')
        {
            if (wildcmp(s1, s2 + 1))
                return (1);
            s1++;
        }
    }

    /* If no match was found, the strings are not identical */
    return (0);
}
