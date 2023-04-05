#include <stdio.h>

/**
 * _print_rev_recursion - Prints a string in reverse recursively
 * @s: The string to be printed
 *
 * Return: void
 */
void _print_rev_recursion(char *s)
{
	if (*s == '\0') /* Base case */
		return;

	/* Recursively call the function with the next character */
	_print_rev_recursion(s + 1);

	/* Print the current character */
	putchar(*s);
}
