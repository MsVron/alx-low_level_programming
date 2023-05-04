#include "main.h"

/**
 *flip_bits - returns the number of bits you would need to flip to get from
 *            one number to another.
 *@n: the first number.
 *@m: the second number.
 *
 *Return: the number of bits you would need to flip to get from one number to
 *        another.
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned long int flip = n ^ m;
	unsigned int count = 0;

	while (flip > 0)
	{
		if (flip & 1)
			count++;
		flip >>= 1;
	}

	return (count);
}
