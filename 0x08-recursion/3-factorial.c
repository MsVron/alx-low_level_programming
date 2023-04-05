#include <stdio.h>
#include "main.h"

/**
 * factorial - Computes the factorial of a given number recursively
 * @n: The number whose factorial is to be computed
 *
 * Return: The factorial of the number, or -1 if the number is negative
 */

int factorial(int n)
{
	if (n < 0) /* Error case */
		return (-1);

	if (n == 0) /* Base case */
		return (1);

	return (n * factorial(n - 1));
    /* Recursive */
}
