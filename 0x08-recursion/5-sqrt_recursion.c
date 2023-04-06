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

/**
 * _sqrt_helper - Helper function for _sqrt_recursion
 * @n: The number whose square root is to be computed
 * @low: The lower bound of the square root
 * @high: The upper bound of the square root
 *
 * Return: The natural square root of n, or -1 if n does not have a natural square root
 */

int _sqrt_helper(int n, int low, int high)
{
	int mid = (low + high) / 2;

	if (mid * mid == n) /* Base case */
		return (mid);

	if (low >= high) /* Error case */
		return (-1);

	if (mid * mid > n) /* Recursive case - search the lower half */
		return (_sqrt_helper(n, low, mid - 1));
	else /* Recursive case - search the upper half */
		return (_sqrt_helper(n, mid + 1, high));
}
