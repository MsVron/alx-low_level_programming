#include <stdio.h>
#include <stdlib.h>
#include "search_algos.h"

/**
 * advanced_binary - Searches for a value in a sorted array using advanced
 * binary search
 * @array: Pointer to the first element of the array
 * @size: Number of elements in the array
 * @value: Value to search for
 *
 * Return: Index where value is located, or -1 if not found or array is NULL
 */
int advanced_binary(int *array, size_t size, int value)
{
	if (array == NULL || size == 0)
		return (-1);

	return (advanced_binary_recursive(array, 0, size - 1, value));
}

/**
 * advanced_binary_recursive - Recursive helper function
 * for advanced binary search
 * @array: Pointer to the first element of the array
 * @low: The starting index of the array
 * @high: The ending index of the array
 * @value: Value to search for
 *
 * Return: Index where value is located, or -1 if not found
 */
int advanced_binary_recursive(int *array, size_t low, size_t high, int value)
{
	size_t mid;
	size_t i;

	if (low > high)
		return (-1);

	printf("Searching in array: ");
	for (i = low; i < high; i++)
		printf("%d, ", array[i]);
	printf("%d\n", array[high]);

	mid = (low + high) / 2;

	if (array[mid] == value)
	{
		if (mid > 0 && array[mid - 1] == value)
			return (advanced_binary_recursive(array, low, mid, value));
		else
			return (mid);
	}
	else if (array[mid] < value)
		return (advanced_binary_recursive(array, mid + 1, high, value));
	else
		return (advanced_binary_recursive(array, low, mid - 1, value));
}
