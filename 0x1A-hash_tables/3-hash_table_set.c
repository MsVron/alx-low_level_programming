include "main.h"

/**
 * hash_table_set - adds an element to the hash table
 * @ht: hash table to add/update the key/value to
 * @key: key string (cannot be empty)
 * @value: value string (can be empty)
 *
 * Return: 1 if successful, 0 otherwise
 */
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
    hash_node_t *new_node, *temp;
    unsigned long int index;

    if (ht == NULL || key == NULL || *key == '\0')
        return 0;

    index = key_index((const unsigned char *)key, ht->size);
    temp = ht->array[index];

    /* Check if key already exists in the hash table */
    while (temp != NULL)
    {
        if (strcmp(temp->key, key) == 0)
        {
            /* Update value and return */
            free(temp->value);
            temp->value = strdup(value);
            return 1;
        }
        temp = temp->next;
    }

    /* Create a new node and add it at the beginning of the list */
    new_node = malloc(sizeof(hash_node_t));
    if (new_node == NULL)
        return 0;

    new_node->key = strdup(key);
    new_node->value = strdup(value);
    new_node->next = ht->array[index];
    ht->array[index] = new_node;

    return 1;
}
