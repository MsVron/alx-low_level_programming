/**
 * _strlen_recursion - Computes the length of a string recursively
 *
 * @s: The string to compute the length of
 *
 * Return: The length of the string
 */
int _strlen_recursion(char *s)
{
	if (*s == '\0')
		return (0);

	return (1 + _strlen_recursion(s + 1));
}

/**
 * is_palindrome - Checks if a string is a palindrome recursively
 *
 * @s: The string to check
 *
 * Return: 1 if s is a palindrome, 0 otherwise
 */
int is_palindrome(char *s)
{
	int len = _strlen_recursion(s);

	/* Base case: a string of length 0 or 1 is a palindrome */
	if (len <= 1)
		return (1);

	/* Recursive case: compare the first and last characters */
	if (*s == *(s + len - 1))
		return (is_palindrome(s + 1) && is_palindrome(s, len - 2));

	/* If the first and last characters are different, it's not a palindrome */
	return (0);
}
