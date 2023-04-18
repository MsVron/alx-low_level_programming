#include "dog.h"
#include <stdlib.h>

/**
 * free_dog - frees memory allocated for a dog_t struct
 * @d: pointer to struct of type dog_t to free
 *
 * Return: void
 */

void free_dog(dog_t *d)
{
	if (d == NULL)
		return;

	free(d->name);
	free(d->owner);
	free(d);
}
