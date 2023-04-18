#include "dog.h"
#include <stdlib.h>

/**
 * new_dog - creates a new dog
 * @name: name of the dog
 * @age: age of the dog
 * @owner: owner of the dog
 *
 * Return: pointer to the new dog or NULL if fails
 */

dog_t *new_dog(char *name, float age, char *owner)
{
	dog_t *new_dog;
	char *copy_name, *copy_owner;
	unsigned int i, name_len, owner_len;

	new_dog = malloc(sizeof(dog_t));
	if (new_dog == NULL)
		return (NULL);

	for (name_len = 0; name[name_len] != '\0'; name_len++)
		;
	for (owner_len = 0; owner[owner_len] != '\0'; owner_len++)
		;

	copy_name = malloc(sizeof(char) * (name_len + 1));
	if (copy_name == NULL)
	{
		free(new_dog);
		return (NULL);
	}
	for (i = 0; i <= name_len; i++)
		copy_name[i] = name[i];

	copy_owner = malloc(sizeof(char) * (owner_len + 1));
	if (copy_owner == NULL)
	{
		free(new_dog);
		free(copy_name);
		return (NULL);
	}
	for (i = 0; i <= owner_len; i++)
		copy_owner[i] = owner[i];

	new_dog->name = copy_name;
	new_dog->age = age;
	new_dog->owner = copy_owner;

	return (new_dog);
}
