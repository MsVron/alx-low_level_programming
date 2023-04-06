#include "main.h"

/**
 * _sqrt_helper - Helper function for _sqrt_recursion
 * @n: The number to find the square root of
 * @i: The current integer to be squared and compared to n
 *
 * Return: The natural square root of n, or -1 if n has no natural square root
 */
int _sqrt_helper(int n, int i)
{
	if (i * i == n)
		return (i);
	if (i * i > n)
		return (-1);
	return (_sqrt_helper(n, i + 1));
}

/**
 * _sqrt_recursion - Calculates the natural square root of a number
 * @n: The number to find the square root of
 *
 * Return: The natural square root of n, or -1 if n has no natural square root
 */
int _sqrt_recursion(int n)
{
	return (_sqrt_helper(n, 1));
}
