#include "main.h"
#include <stdio.h>
#include <string.h>

/**
 * is_palindrome - Checks if a string is a palindrome recursively
 *
 * @s: The string to check
 *
 * Return: 1 if the string is a palindrome, 0 otherwise
 */
int is_palindrome(char *s)
{
    int len = strlen(s);

    /* An empty string is a palindrome */
    if (len == 0)
        return (1);

    /* A string with one character is a palindrome */
    if (len == 1)
        return (1);

    /* Check if the first and last characters are the same */
    if (*s == *(s + len - 1))
        /* Recursively check if the substring between the first and last characters is a palindrome */
        return (is_palindrome(s + 1) && is_palindrome(s + len - 1 - 1));

    /* If the first and last characters are not the same, the string is not a palindrome */
    return (0);
}
