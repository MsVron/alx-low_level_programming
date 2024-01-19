#include "search_algos.h"

/**
 * linear_skip - Searches for a value in a sorted skip list of integers
 * @list: Pointer to the head of the skip list to search in
 * @value: Value to search for
 *
 * Return: Pointer to the first node where value is located, or NULL if not found
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *express, *prev;

	if (!list)
		return (NULL);

	express = list->express;
	prev = list;

	while (express && express->n < value)
	{
		printf("Value checked at index [%lu] = [%d]\n", (unsigned long) express->index, express->n);
		prev = express;
		express = express->express;
	}

	printf("Value found between indexes [%lu] and [%lu]\n", (unsigned long) prev->index, express ? (unsigned long) express->index : (unsigned long) prev->index);

	while (prev && prev->index <= (express ? express->index : prev->index))
	{
		printf("Value checked at index [%lu] = [%d]\n", (unsigned long) prev->index, prev->n);

		if (prev->n == value)
			return (prev);

		prev = prev->next;
	}

	return (NULL);
}
