#ifndef MAIN_H
#define MAIN_H

/* Required headers */
#include <stdlib.h>
#include <stdio.h>

/* Struct definitions */

/**
 * struct hash_node_s - Node of a hash table
 * @key: The key string
 * @value: The value corresponding to the key
 * @next: Pointer to the next node in case of collisions
 */
typedef struct hash_node_s
{
    char *key;
    char *value;
    struct hash_node_s *next;
} hash_node_t;

/**
 * struct hash_table_s - Hash table data structure
 * @size: The size of the hash table array
 * @array: Array of pointers to the hash nodes
 */
typedef struct hash_table_s
{
    unsigned long int size;
    hash_node_t **array;
} hash_table_t;

/* Function prototypes */
hash_table_t *hash_table_create(unsigned long int size);
unsigned long int hash_djb2(const unsigned char *str);

#endif /* MAIN_H */
