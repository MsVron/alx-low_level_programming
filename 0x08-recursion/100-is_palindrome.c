#include "main.h"

/**
 * is_palindrome - Checks if a string is a palindrome recursively
 *
 * @s: The string to check
 *
 * Return: 1 if s is a palindrome, 0 otherwise
 */
int is_palindrome(char *s)
{
    int len = 0, i;

    /* Get the length of the string */
    while (*(s + len) != '\0')
        len++;

    /* Base case: a string of length 0 or 1 is a palindrome */
    if (len <= 1)
        return (1);

    /* Recursive case: compare the first and last characters */
    if (*s == *(s + len - 1))
        return (is_palindrome(s + 1) && is_palindrome(s + len - 1 - 1));

    /* If the first and last characters are different, it's not a palindrome */
    return (0);
}
