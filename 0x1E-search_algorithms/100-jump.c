#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "search_algos.h"

/**
 * jump_search - Searches for a value in a sorted array using jump search
 * @array: Pointer to the first element of the array
 * @size: Number of elements in the array
 * @value: Value to search for
 *
 * Return: Index where value is located, or -1 if not found or array is NULL
 */

int jump_search(int *array, size_t size, int value)
{
	size_t step;
	size_t prev;
	size_t i;

	if (array == NULL)
		return (-1);

	step = sqrt(size);
	prev = 0;

	printf("Value checked array[%lu] = [%d]\n", (unsigned long)prev, array[prev]);
	while (array[min(step, size) - 1] < value)
	{
		prev = step;
		step += sqrt(size);
		if (prev >= size)
			return (-1);
		printf("Value checked array[%lu] = [%d]\n",
				(unsigned long)prev, array[prev]);
	}

	printf("Value found between indexes [%lu] and [%lu]\n",
			(unsigned long)prev, (unsigned long)min(step, size));

	for (i = prev; i < min(step, size); i++)
	{
		printf("Value checked array[%lu] = [%d]\n", (unsigned long)i, array[i]);
		if (array[i] == value)
			return (i);
	}

	return (-1);
}

/**
 * min - Returns the minimum of two numbers
 * @a: First number
 * @b: Second number
 *
 * Return: Minimum of a and b
 */
size_t min(size_t a, size_t b)
{
	return ((a < b) ? a : b);
}
