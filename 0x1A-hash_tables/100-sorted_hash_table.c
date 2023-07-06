#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "hash_tables.h"

/**
 *shash_table_create - Creates a sorted hash table
 *@size: The size of the hash table
 *
 *Return: A pointer to the created hash table, or NULL on failure
 */

shash_table_t* shash_table_create(unsigned long int size)
{
	shash_table_t *ht = malloc(sizeof(shash_table_t));
	if (ht == NULL)
		return (NULL);

	ht->size = size;
	ht->array = malloc(size* sizeof(shash_node_t*));
	if (ht->array == NULL)
	{
		free(ht);
		return (NULL);
	}

	memset(ht->array, 0, size* sizeof(shash_node_t*));
	ht->shead = NULL;
	ht->stail = NULL;

	return (ht);
}

/**
 *shash_table_set - Adds an element to the sorted hash table
 *@ht: The hash table
 *@key: The key to add
 *@value: The value to associate with the key
 *
 *Return: 1 on success, 0 on failure
 */
int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
	if (ht == NULL || key == NULL || *key == '\0')
		return (0);

	unsigned long int index = key_index((unsigned char *) key, ht->size);

	shash_node_t *node = ht->array[index];
	shash_node_t *prev = NULL;

	while (node != NULL)
	{
		int cmp = strcmp(node->key, key);
		if (cmp == 0)
		{
			free(node->value);
			node->value = strdup(value);
			return (1);
		}
		else if (cmp > 0)
		{
			break;
		}

		prev = node;
		node = node->next;
	}

	shash_node_t *new_node = malloc(sizeof(shash_node_t));
	if (new_node == NULL)
		return (0);

	new_node->key = strdup(key);
	new_node->value = strdup(value);
	new_node->next = node;

	if (prev != NULL)
		prev->next = new_node;
	else
		ht->array[index] = new_node;

	if (node != NULL)
		node->sprev = new_node;
	else
		ht->stail = new_node;

	if (prev != NULL)
		new_node->sprev = prev;
	else
		new_node->sprev = NULL;

	new_node->snext = node;

	if (node != NULL)
		node->sprev = new_node;
	else
		ht->shead = new_node;

	return (1);
}

/**
 *shash_table_get - Retrieves a value associated with a key
 *@ht: The hash table
 *@key: The key to search for
 *
 *Return: The value associated with the key, or NULL if key not found
 */
char *shash_table_get(const shash_table_t *ht, const char *key)
{
	if (ht == NULL || key == NULL || *key == '\0')
		return (NULL);

	unsigned long int index = key_index((unsigned char *) key, ht->size);

	shash_node_t *node = ht->array[index];

	while (node != NULL)
	{
		int cmp = strcmp(node->key, key);
		if (cmp == 0)
			return (node->value);
		else if (cmp > 0)
			break;
		node = node->next;
	}

	return (NULL);
}

/**
 *shash_table_print - Prints the elements of a sorted hash table
 *@ht: The hash table
 */
void shash_table_print(const shash_table_t *ht)
{
	if (ht == NULL)
		return;

	shash_node_t *node = ht->shead;

	printf("{");
	while (node != NULL)
	{
		printf("'%s': '%s'", node->key, node->value);
		if (node->snext != NULL)
			printf(", ");
		node = node->snext;
	}

	printf("}\n");
}

/**
 *shash_table_print_rev - Prints the elements of a sorted hash table in reverse
 *@ht: The hash table
 */
void shash_table_print_rev(const shash_table_t *ht)
{
	if (ht == NULL)
		return;

	shash_node_t *node = ht->stail;

	printf("{");
	while (node != NULL)
	{
		printf("'%s': '%s'", node->key, node->value);
		if (node->sprev != NULL)
			printf(", ");
		node = node->sprev;
	}

	printf("}\n");
}

/**
 *shash_table_delete - Deletes a sorted hash table
 *@ht: The hash table
 */
void shash_table_delete(shash_table_t *ht)
{
	if (ht == NULL)
		return;

	shash_node_t *node, *temp;

	for (unsigned long int i = 0; i < ht->size; i++)
	{
		node = ht->array[i];
		while (node != NULL)
		{
			temp = node;
			node = node->next;
			free(temp->key);
			free(temp->value);
			free(temp);
		}
	}

	free(ht->array);
	free(ht);
}
