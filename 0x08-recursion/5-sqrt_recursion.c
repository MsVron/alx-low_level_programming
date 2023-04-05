#include <stdio.h>
#include "main.h"

/**
 * _sqrt_recursion - Computes the natural square root of a number recursively
 * @n: The number whose square root is to be computed
 *
 * Return: The natural square root of n, or -1 if n does not have a natural square root
 */

int _sqrt_recursion(int n)
{
	if (n < 0) /* Error case */
		return (-1);

	if (n == 0 || n == 1) /* Base case */
		return (n);

	return (_sqrt_helper(n, 1, n)); /* Call helper function with lower bound = 1 and upper bound = n */
}
