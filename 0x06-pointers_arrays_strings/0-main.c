#include <stdio.h>

/**
 * strcat - Concatenates two strings.
 * @dest: Pointer to the destination string.
 * @src: Pointer to the source string.
 *
 * Return: Pointer to the resulting string dest.
 */
char *strcat(char *dest, char *src)
{
    char *result = dest;

    /* Find the end of dest string */
    int i = 0;
    while (dest[i] != '\0') {
        i++;
    }

    /* Append src to dest */
    int j = 0;
    while (src[j] != '\0') {
        dest[i] = src[j];
        i++;
        j++;
    }

    /* Add a terminating null byte to the end of dest */
    dest[i] = '\0';

    return result;
}
