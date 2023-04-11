#include <stdio.h>
#include "main.h"

/**
 * _pow_recursion - Computes the value of x raised to the power of y, recursive
 * @x: The base number
 * @y: The exponent
 *
 * Return: The value of x raised to the power of y, or -1 if y is negative
 */

int _pow_recursion(int x, int y)
{
	if (y < 0) /* Error case */
		return (-1);

	if (y == 0) /* Base case */
		return (1);

	return (x * _pow_recursion(x, y - 1));
}
