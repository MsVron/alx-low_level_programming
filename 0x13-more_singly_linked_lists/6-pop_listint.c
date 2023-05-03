#include "lists.h"

/**
 *pop_listint - deletes the head node of a listint_t list
 *and returns the head node's data (n)
 *@head: pointer to the pointer to the head of the list
 *
 *Return: the head node's data (n), or 0 if the list is empty
 */
int pop_listint(listint_t **head)
{
	int n;
	listint_t *temp;

	if (*head == NULL)
		return (0);

	temp = *head;
	n = temp->n;
	*head = temp->next;
	free(temp);

	return (n);
}
