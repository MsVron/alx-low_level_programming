#include "main.h"
#include <stdio.h>

/**
 * _sqrt_helper - Calculates the natural square root of a number.
 * @n: The number to find the square root of.
 * @i: The current guess for the square root.
 *
 * Return: The square root of n, or -1 if n doesn't have a natural square root.
 */
int _sqrt_helper(int n, int i)
{
    /* Base case */
    if (i * i == n)
        return i;

    /* Terminating case */
    if (i * i > n)
        return -1;

    /* Recursive case */
    return _sqrt_helper(n, i + 1);
}

/**
 * _sqrt_recursion - Wrapper function for _sqrt_helper.
 * @n: The number to find the square root of.
 *
 * Return: The square root of n, or -1 if n doesn't have a natural square root.
 */
int _sqrt_recursion(int n)
{
    return _sqrt_helper(n, 1);
}
