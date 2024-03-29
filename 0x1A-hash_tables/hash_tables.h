#ifndef HASH_TABLES_H
#define HASH_TABLES_H

/**
 * struct hash_node_s - Node of a hash table
 *
 * @key: The key, string
 * The key is unique in the HashTable
 * @value: The value corresponding to a key
 * @next: A pointer to the next node of the List
 */
typedef struct hash_node_s
{
     char *key;
     char *value;
     struct hash_node_s *next;
} hash_node_t;

/**
 * struct hash_table_s - Hash table data structure
 *
 * @size: The size of the array
 * @array: An array of size @size
 * Each cell of this array is a pointer to the first node of a linked list,
 * because we want our HashTable to use a Chaining collision handling
 */
typedef struct hash_table_s
{
     unsigned long int size;
     hash_node_t **array;
} hash_table_t;

/*Function Prototypes */

/**
 *shash_table_create - Creates a sorted hash table
 *@size: The size of the hash table
 *
 *Return: A pointer to the created hash table, or NULL on failure
 */
shash_table_t* hash_table_create(unsigned long int size);

/**
 *shash_table_set - Adds an element to the sorted hash table
 *@ht: The hash table
 *@key: The key to add
 *@value: The value to associate with the key
 *
 *Return: 1 on success, 0 on failure
 */
int shash_table_set(shash_table_t *ht, const char *key, const char *value);

/**
 *shash_table_get - Retrieves a value associated with a key
 *@ht: The hash table
 *@key: The key to search for
 *
 *Return: The value associated with the key, or NULL if key not found
 */
char *shash_table_get(const shash_table_t *ht, const char *key);

/**
 *shash_table_print - Prints the elements of a sorted hash table
 *@ht: The hash table
 */
void shash_table_print(const shash_table_t *ht);

/**
 *shash_table_print_rev - Prints the elements of a sorted hash table in reverse
 *@ht: The hash table
 */
void shash_table_print_rev(const shash_table_t *ht);

/**
 *shash_table_delete - Deletes a sorted hash table
 *@ht: The hash table
 */
void shash_table_delete(shash_table_t *ht);


#endif /*HASH_TABLES_H */
