#include "lists.h"

/**
 *free_listint2 - frees a listint_t list
 *@head: pointer to the pointer to the head of the list
 *
 *Description: This function frees a listint_t list and sets the head to NULL.
 */
void free_listint2(listint_t **head)
{
	if (head == NULL || *head == NULL)
		return;

	listint_t *current = *head;
	listint_t *next;

	while (current != NULL)
	{
		next = current->next;
		free(current);
		current = next;
	}

	*head = NULL;
}
