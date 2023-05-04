#include "lists.h"

/**
 *hash_table_create - creates a hash table
 *@size: size of the array
 *@hash_func: pointer to the hash function to use
 *
 *Return: pointer to the newly created hash table
 */
hash_table_t *hash_table_create(unsigned long int size, unsigned long int(*hash_func)(const char *))
{
	hash_table_t *ht;
	unsigned long int i;

	ht = malloc(sizeof(hash_table_t));
	if (ht == NULL)
		return (NULL);

	ht->size = size;
	ht->array = malloc(sizeof(hash_node_t *) *size);
	if (ht->array == NULL)
	{
		free(ht);
		return (NULL);
	}

	for (i = 0; i < size; i++)
		ht->array[i] = NULL;

	ht->hash_func = hash_func;

	return (ht);
}

/**
 *hash_djb2 - implementation of the djb2 hash algorithm
 *@str: string to hash
 *
 *Return: hash value
 */
unsigned long int hash_djb2(const char *str)
{
	unsigned long int hash = 5381;
	int c;

	while ((c = *str++))
		hash = ((hash << 5) + hash) + c; /*hash *33 + c */

	return (hash);
}

/**
 *hash_table_set - adds an element to a hash table
 *@ht: pointer to the hash table
 *@key: key to use
 *@value: value to store
 *
 *Return: 1 if successful, 0 otherwise
 */
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	unsigned long int index;
	hash_node_t *new_node, *current;

	if (ht == NULL || key == NULL || value == NULL || strcmp(key, "") == 0)
		return (0);

	index = ht->hash_func(key) % ht->size;

	current = ht->array[index];
	while (current != NULL)
	{
		if (strcmp(current->key, key) == 0)
		{
			free(current->value);
			current->value = strdup(value);
			if (current->value == NULL)
				return (0);
			return (1);
		}

		current = current->next;
	}

	new_node = malloc(sizeof(hash_node_t));
	if (new_node == NULL)
		return (0);

	new_node->key = strdup(key);
	if (new_node->key == NULL)
	{
		free(new_node);
		return (0);
	}

	new_node->value = strdup(value);
	if (new_node->value == NULL)
	{
		free(new_node->key);
		free(new_node);
		return (0);
	}

	new_node->next = ht->array[index];
	ht->array[index] = new_node;

	return (1);
}
