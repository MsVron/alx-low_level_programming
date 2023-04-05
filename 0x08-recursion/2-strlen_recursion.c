#include <stdio.h>
#include "math.h"

/**
 * _strlen_recursion - Computes the length of a string recursively
 * @s: The string whose length is to be computed
 *
 * Return: The length of the string
 */

int _strlen_recursion(char *s)
{
	if (*s == '\0') /* Base case */
		return (0);

    /* Recursively call the function with the next character */
	return (1 + _strlen_recursion(s + 1)); 
}
