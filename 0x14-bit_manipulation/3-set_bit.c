#include "main.h"

/**
 *set_bit - Sets the value of a bit to 1 at a given index.
 *@n: A pointer to the number to modify.
 *@index: The index of the bit to set.
 *
 *Return: 1 if it worked, or -1 if an error occurred.
 */
int set_bit(unsigned long int *n, unsigned int index)
{
	/*Check if index is out of range */
	if (index >= (sizeof(unsigned long int) *8))
		return (-1);

	/*Set the bit to 1 using OR */
	*n |= (1 << index);

	return (1);
}
=
