#include "lists.h"

/**
 *insert_dnodeint_at_index - Inserts a new node at a given position
 *@h: Pointer to a pointer to the head of the list
 *@idx: Index where the new node should be inserted (starting from 0)
 *@n: Value to be stored in the new node
 *Return: Address of the new node, or NULL if it failed
 */
dlistint_t* insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
	dlistint_t *new_node, *current;
	unsigned int i;

	if (h == NULL)
		return NULL;

	/*Special case: inserting at the beginning */
	if (idx == 0)
		return add_dnodeint(h, n);

	/*Traverse the list to the desired position */
	current = *h;
	for (i = 0; i < idx - 1 && current != NULL; i++)
		current = current->next;

	/*Check if it's not possible to add the new node */
	if (current == NULL)
		return NULL;

	/*Create the new node and assign its values */
	new_node = malloc(sizeof(dlistint_t));
	if (new_node == NULL)
		return NULL;
	new_node->n = n;

	/*Adjust the links of the surrounding nodes */
	new_node->next = current->next;
	if (current->next != NULL)
		current->next->prev = new_node;
	current->next = new_node;
	new_node->prev = current;

	return new_node;
}
