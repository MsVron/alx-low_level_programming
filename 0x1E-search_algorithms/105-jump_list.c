#include "search_algos.h"

/**
 * jump_list - Searches for a value in a sorted list using Jump search
 * @list: Pointer to the head of the list to search in
 * @size: Number of nodes in the list
 * @value: Value to search for
 *
 * Return: Pointer to the first node where value is located,
 * or NULL if not found
 */
listint_t *jump_list(listint_t *list, size_t size, int value)
{
	size_t jump, prev, next;

	if (!list || size == 0)
		return (NULL);

	jump = (size_t)sqrt(size);
	prev = 0;
	next = jump;

	while (next < size && list[next].n < value)
	{
		printf("Value checked at index [%lu] = [%d]\n",
				(unsigned int long)next, list[next].n);
		prev = next;
		next += jump;
	}

	printf("Value found between indexes [%lu] and [%lu]\n",
			(unsigned int long)prev, (unsigned int long)next);

	while (prev <= next && prev < size)
	{
		printf("Value checked at index [%lu] = [%d]\n",
				(unsigned int long)prev, list[prev].n);

		if (list[prev].n == value)
			return (&list[prev]);

		prev++;
	}

	return (NULL);
}
