#include <stdlib.h>

/**
 * _realloc - Reallocate a memory block using malloc and free
 *
 * @ptr: Pointer to the memory previously allocated with malloc
 * @old_size: Size, in bytes, of the allocated space for ptr
 * @new_size: New size, in bytes, of the new memory block
 *
 * Return: A pointer to the reallocated memory block, NULL if the function fails
 * If new_size == old_size do not do anything and return ptr
 * If ptr is NULL, then the call is equivalent to malloc(new_size),
 * for all values of old_size and new_size
 * If new_size is equal to zero, and ptr is not NULL, then the call is
 * equivalent to free(ptr) and return NULL
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *new_ptr;
	unsigned int i;

	if (new_size == old_size)
		return (ptr);

	if (new_size == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}

	if (ptr == NULL)
	{
		new_ptr = malloc(new_size);
		if (new_ptr == NULL)
			exit(98);
		return (new_ptr);
	}

	new_ptr = malloc(new_size);
	if (new_ptr == NULL)
		exit(98);

	if (new_size > old_size)
		for (i = 0; i < old_size; i++)
			new_ptr[i] = ((char *)ptr)[i];
	else
		for (i = 0; i < new_size; i++)
			new_ptr[i] = ((char *)ptr)[i];

	free(ptr);
	return (new_ptr);
}
