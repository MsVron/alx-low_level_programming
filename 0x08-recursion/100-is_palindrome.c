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
    int len = 0;

    /* Helper function to get the length of the string */
    int get_length(char *s, int len)
    {
        if (*s == '\0')
            return len;
        else
            return get_length(s + 1, len + 1);
    }

    len = get_length(s, 0);

    /* Base case: a string of length 0 or 1 is a palindrome */
    if (len <= 1)
        return 1;

    /* Recursive case: compare the first and last characters */
    if (*s == *(s + len - 1))
        return is_palindrome(s + 1) && is_palindrome(s + len - 1 - 1);

    /* If the first and last characters are different, it's not a palindrome */
    return 0;
}
