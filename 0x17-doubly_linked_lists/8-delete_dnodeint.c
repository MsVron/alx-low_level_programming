#include "lists.h"

/**
 *delete_dnodeint_at_index - Deletes the node at a given index
 *@head: Pointer to a pointer to the head of the list
 *@index: Index of the node to be deleted (starting from 0)
 *Return: 1 if it succeeded, -1 if it failed
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *current, *temp;
	unsigned int i;

	if (head == NULL || *head == NULL)
		return (-1);

	current = *head;

	/*Special case: deleting the first node */
	if (index == 0)
	{
		*head = current->next;
		if (*head != NULL)
			(*head)->prev = NULL;
		free(current);
		return (1);
	}

	/*Traverse the list to the desired position */
	for (i = 0; i < index && current != NULL; i++)
		current = current->next;

	/*Check if it's not possible to delete the node */
	if (current == NULL)
		return (-1);

	/*Adjust the links of the surrounding nodes */
	temp = current;
	current->prev->next = current->next;
	if (current->next != NULL)
		current->next->prev = current->prev;
	free(temp);

	return (1);
}
