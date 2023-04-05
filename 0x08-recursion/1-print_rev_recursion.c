#include "main.h"
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

	_print_rev_recursion(s + 1); /* Recursively call the function with the next character */

	putchar(*s); /* Print the current character */
}
