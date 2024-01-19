#include "search_algos.h"

/**
 * linear_skip - Searches for a value in a sorted skip list of integers
 * @list: Pointer to the head of the skip list to search in
 * @value: Value to search for
 *
 * Return: Pointer to the first node where value is located,
 * or NULL if not found
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *express;

	if (!list)
		return (NULL);

	express = list->express;
	printf("Value checked at index [%lu] = [%d]\n", (unsigned int long)express->index, express->n);

	while (express && express->n < value)
	{
		list = express;
		express = express->express;
		if (express)
			printf("Value checked at index [%lu] = [%d]\n", (unsigned int long)express->index, express->n);
	}

	printf("Value found between indexes [%lu] and [%lu]\n", (unsigned int long)list->index, express ? express->index : list->index);

	while (list && list->n < value)
	{
		printf("Value checked at index [%lu] = [%d]\n", (unsigned int long)list->index, list->n);
		list = list->next;
	}

	if (list && list->n == value)
	{
		printf("Value checked at index [%lu] = [%d]\n", (unsigned int long)list->index, list->n);
		return (list);
	}

	return (NULL);
}
