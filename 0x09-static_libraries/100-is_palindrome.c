#include "main.h"

/**
 * _strlen_recursion - Computes the length of a string recursively
 *
 * @s: The string to compute the length of
 *
 * Return: The length of the string
 */
int _strlen_recursion(char *s)
{
	if (*s != '\0')
		return (1 + _strlen_recursion(s + 1));
	else
		return (0);
}

/**
 * palindrome - Checks if a substring is a palindrome recursively
 *
 * @s: The string to check
 * @i: The starting index of the substring to check
 * @j: The ending index of the substring to check
 *
 * Return: 1 if the substring is a palindrome, 0 otherwise
 */
int palindrome(char *s, int i, int j)
{
	if (j <= i)
		return (1);

	if (*(s + i) != *(s + j))
		return (0);

	return (palindrome(s, i + 1, j - 1));
}

/**
 * is_palindrome - Checks if a string is a palindrome recursively
 *
 * @s: The string to check
 *
 * Return: 1 if the string is a palindrome, 0 otherwise
 */
int is_palindrome(char *s)
{
	int i = 0;
	int j = _strlen_recursion(s) - 1;

	return (palindrome(s, i, j));
}
