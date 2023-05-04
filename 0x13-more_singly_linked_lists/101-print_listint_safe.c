#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 *print_listint_safe - Prints a listint_t linked list
 *@head: Pointer to the head of the linked list
 *
 *Return: The number of nodes in the list
 */
size_t print_listint_safe(const listint_t *head)
{
	size_t count = 0;
	const listint_t *current = head,
		*check;

	while (current != NULL)
	{
		count++;
		printf("[%p] %d\n", (void *) current, current->n);

		check = current->next;
		while (check != NULL)
		{
			if (check == current)
			{
				printf("->[%p] %d\n", (void *) check, check->n);
				exit(98);
			}

			check = check->next;
		}

		current = current->next;
	}

	return (count);
}
