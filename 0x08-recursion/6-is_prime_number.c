#include "main.h"
#include <stdio.h>

/**
 * is_prime_helper - Helper function for is_prime_number
 *
 * @n: The integer to check
 * @divisor: The current divisor to check
 *
 * Return: 1 if n is prime, 0 otherwise
 */
int is_prime_helper(int n, int divisor);

/**
 * is_prime_number - Checks if an integer is a prime number recursively
 *
 * @n: The integer to check
 *
 * Return: 1 if n is prime, 0 otherwise
 */
int is_prime_number(int n)
{
	if (n <= 1) /* 1 and negative numbers are not prime */
		return (0);

	if (n == 2) /* 2 is the only even prime number */
		return (1);

	if (n % 2 == 0) /* All even numbers (except 2) are not prime */
		return (0);

	return (is_prime_helper(n, 3));
}

/**
 * is_prime_helper - Helper function for is_prime_number
 *
 * @n: The integer to check
 * @divisor: The current divisor to check
 *
 * Return: 1 if n is prime, 0 otherwise
 */
int is_prime_helper(int n, int divisor)
{
	if (n % divisor == 0) /* n is divisible by divisor, so it's not prime */
		return (0);

	if (divisor * divisor > n) /* n is not divisible by any integer up to its square root, so it's prime */
		return (1);

	return (is_prime_helper(n, divisor + 2)); /* Try the next odd divisor */
}
