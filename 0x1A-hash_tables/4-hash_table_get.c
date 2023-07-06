include "main.h"

/**
 * hash_table_get - Retrieves the value associated with a given key in a hash table
 * @ht: The hash table
 * @key: The key to search for
 *
 * Return: The value associated with the key, or NULL if key is not found
 */
char *hash_table_get(const hash_table_t *ht, const char *key)
{
	unsigned long int index;
	hash_node_t *node;

	/* Check if hash table or key is NULL, or key is an empty string */
	if (ht == NULL || key == NULL || strcmp(key, "") == 0)
		return NULL;

	/* Get the index for the key */
	index = key_index((const unsigned char *)key, ht->size);
	node = ht->array[index];

	/* Traverse the linked list at the index to find the key */
	while (node != NULL)
	{
		if (strcmp(node->key, key) == 0)
			return node->value;
		node = node->next;
	}

	return NULL;
}
