#include "lists.h"

/**
 *add_nodeint_end - Adds a new node at the end of a listint_t list.
 *@head: A pointer to a pointer to the head of the listint_t list.
 *@n: The integer value to be added to the new node.
 *
 *Return: The address of the new element, or NULL if it failed.
 */
listint_t *add_nodeint_end(listint_t **head, const int n)
{
	listint_t *new_node, *temp;

	/*Create a new node */
	new_node = malloc(sizeof(listint_t));
	if (new_node == NULL)
		return (NULL);

	/*Set the new node's data and next pointer */
	new_node->n = n;
	new_node->next = NULL;

	/*If the list is empty, set the head to point to the new node */
	if (*head == NULL)
	{
		*head = new_node;
		return (new_node);
	}

	/*Find the last node in the list */
	temp = *head;
	while (temp->next != NULL)
		temp = temp->next;

	/*Set the last node's next pointer to the new node */
	temp->next = new_node;

	return (new_node);
}
