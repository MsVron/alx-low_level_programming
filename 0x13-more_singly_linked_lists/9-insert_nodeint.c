#include "lists.h"

/**
 *insert_nodeint_at_index - Inserts a new node at a given position.
 *@head: A pointer to a pointer to the first node of the list.
 *@idx: The index of the list where the new node should be added.
 *@n: The value to be assigned to the new node.
 *
 *Return: If the function fails or if it is not possible to add the new node
 *       at index idx, return NULL. 
 *Otherwise, return a pointer to the new node.
 */
listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
	listint_t *new, *temp = *head;
	unsigned int node_idx = 0;

	new = malloc(sizeof(listint_t));
	if (!new)
		return (NULL);

	new->n = n;
	new->next = NULL;

	if (idx == 0)
	{
		new->next = *head;
		*head = new;
		return (new);
	}

	while (temp)
	{
		if (node_idx == idx - 1)
		{
			new->next = temp->next;
			temp->next = new;
			return (new);
		}

		node_idx++;
		temp = temp->next;
	}

	free(new);
	return (NULL);
}
