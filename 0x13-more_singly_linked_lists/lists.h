#ifndef LISTS_H
#define LISTS_H
#include <stdlib.h>
#include <string.h>
#include <stdio.h>


/**
 *struct listint_s - singly linked list
 *@n: integer
 *@next: points to the next node
 *
 *Description: singly linked list node structure
 *for alx project
 */
typedef struct listint_s
{
	int n;
	struct listint_s *next;
}

listint_t;

typedef struct hash_table_s hash_table_t;

typedef struct hash_node_s {
    void *key;
    void *value;
    struct hash_node_s *next;
} hash_node_t;

size_t print_listint(const listint_t *h);
size_t listint_len(const listint_t *h);
listint_t *add_nodeint(listint_t **head, const int n);
listint_t *add_nodeint_end(listint_t **head, const int n);
void free_listint(listint_t *head);
void free_listint2(listint_t **head);
int pop_listint(listint_t **head);
listint_t *get_nodeint_at_index(listint_t *head, unsigned int index);
int sum_listint(listint_t *head);
listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n);
int delete_nodeint_at_index(listint_t **head, unsigned int index);
listint_t *reverse_listint(listint_t **head);
size_t print_listint_safe(const listint_t *head);
size_t free_listint_safe(listint_t **h);
listint_t *find_listint_loop(listint_t *head);
hash_table_t *hash_table_create(unsigned long int size, unsigned long int (*hash_func)(const char *key));
int hash_table_set(hash_table_t *ht, const char *key, const char *value);
char *hash_table_get(const hash_table_t *ht, const char *key);
void hash_table_print(const hash_table_t *ht);
void hash_table_delete(hash_table_t *ht);

#endif /*LISTS_H */
