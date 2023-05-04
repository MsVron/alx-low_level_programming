#include "lists.h"

/**
 *print_listint_safe - prints a listint_t linked list.
 *@head: A pointer to the head node of the list.
 *
 *Return: The number of nodes in the list.
 */
size_t print_listint_safe(const listint_t *head)
{
	size_t count = 0;
	hash_table_t *ht = NULL;

	ht = hash_table_create(1024, hash_djb2);

	if (!ht)
		exit(98);

	while (head)
	{
		if (hash_table_set(ht, (void*) head, sizeof(head), "1"))
		{
			printf("[%p] %d\n", (void*) head, head->n);
			count++;
		}
		else
		{
			printf("->[%p] %d\n", (void*) head, head->n);
			count++;
			break;
		}

		head = head->next;
	}

	hash_table_delete(ht);
	return (count);
}
