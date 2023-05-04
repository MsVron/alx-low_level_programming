#include <stdlib.h>
#include <stdio.h>
#include "lists.h"

int main(void)
{
    listint_t *head = NULL, *node = NULL, *temp = NULL;
    int i;

    /* Case 1: List of two nodes. The second node pointing to the first one (loop) */
    add_nodeint(&head, 1);
    node = add_nodeint(&head, 2);
    node->next = head;
    printf("Number of nodes: %lu\n", print_listint_safe(head)); /* Expected output: Number of nodes: 2 followed by an infinite loop */

    /* Case 2: List of one single node pointing to itself */
    head = NULL;
    node = add_nodeint(&head, 1);
    node->next = node;
    printf("Number of nodes: %lu\n", print_listint_safe(head)); /* Expected output: Number of nodes: 1 followed by an infinite loop */

    /* Case 3: List of 150 nodes. The last one pointing to the 121st node. */
    head = NULL;
    for (i = 0; i < 150; i++)
        add_nodeint(&head, i);
    temp = head;
    for (i = 0; i < 120; i++)
        temp = temp->next;
    node = add_nodeint(&head, 150);
    node->next = temp;
    printf("Number of nodes: %lu\n", print_listint_safe(head)); /* Expected output: Number of nodes: 150 followed by a loop from node 121 to 150 */

    /* Case 4: List of 150 nodes without any loop */
    head = NULL;
    for (i = 0; i < 150; i++)
        add_nodeint(&head, i);
    printf("Number of nodes: %lu\n", print_listint_safe(head)); /* Expected output: Number of nodes: 150 followed by the list of nodes */

    /* Case 5: List of nodes not aligned (in memory) */
    head = malloc(sizeof(listint_t));
    head->n = 1;
    head->next = malloc(sizeof(listint_t));
    head->next->n = 2;
    head->next->next = malloc(sizeof(listint_t));
    head->next->next->n = 3;
    head->next->next->next = NULL;
    printf("Number of nodes: %lu\n", print_listint_safe(head)); /* Expected output: Number of nodes: 3 followed by the list of nodes */
    free(head->next->next);
    free(head->next);
    free(head);

    return (0);
}
