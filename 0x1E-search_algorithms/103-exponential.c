#include <stdio.h>
#include <stdlib.h>
#include "search_algos.h"

/**
 * exponential_search - Searches for a value
 * in a sorted array using exponential search
 * @array: Pointer to the first element of the array
 * @size: Number of elements in the array
 * @value: Value to search for
 *
 * Return: Index where value is located, or -1 if not found or array is NULL
 */
int exponential_search(int *array, size_t size, int value)
{
	size_t bound;
	size_t low, high;

	bound = 1;

	if (array == NULL || size == 0)
		return (-1);

	while (bound < size && array[bound] < value)
	{
		printf("Value checked array[%lu] = [%d]\n",
				(unsigned long)bound, array[bound]);
		bound *= 2;
	}

	low = bound / 2;
	high = (bound < size - 1) ? bound : size - 1;

	printf("Value found between indexes [%lu] and [%lu]\n",
			(unsigned long)low, (unsigned long)high);
	return (binary_search1(array, low, high, value));
}

/**
 * binary_search1 - Searches for a value in a sorted array using binary search
 * @array: Pointer to the first element of the array
 * @low: The starting index of the array
 * @high: The ending index of the array
 * @value: Value to search for
 *
 * Return: Index where value is located, or -1 if not found
 */
int binary_search1(int *array, size_t low, size_t high, int value)
{
	size_t mid;

	while (low <= high)
	{
		print_subarray(array, low, high);
		mid = (low + high) / 2;

		if (array[mid] == value)
			return (mid);
		else if (array[mid] < value)
			low = mid + 1;
		else
			high = mid - 1;
	}

	return (-1);
}

/**
 * print_subarray - Prints the subarray being searched
 * @array: Pointer to the first element of the array
 * @low: The starting index of the subarray
 * @high: The ending index of the subarray
 */
void print_subarray(int *array, size_t low, size_t high)
{
	size_t i;

	printf("Searching in array: ");
	for (i = low; i < high; i++)
		printf("%d, ", array[i]);
	printf("%d\n", array[high]);
}
