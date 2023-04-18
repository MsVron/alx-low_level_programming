#include "dog.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * new_dog - create a new dog
 *
 * @name: name of the dog
 * @age: age of the dog
 * @owner: owner of the dog
 *
 * Return: pointer to the new dog
 */

dog_t *new_dog(char *name, float age, char *owner)
{
	dog_t *dog;
	char *new_name, *new_owner;
	int name_len, owner_len, i;

	/* Check if name and owner are not NULL */
	if (name == NULL || owner == NULL)
		return (NULL);

	/* Allocate memory for dog */
	dog = malloc(sizeof(dog_t));
	if (dog == NULL)
		return (NULL);

	/* Get the length of name and owner */
	for (name_len = 0; name[name_len]; name_len++)
		;
	for (owner_len = 0; owner[owner_len]; owner_len++)
		;

	/* Allocate memory for new_name and new_owner */
	new_name = malloc(sizeof(char) * (name_len + 1));
	if (new_name == NULL)
	{
		free(dog);
		return (NULL);
	}
	new_owner = malloc(sizeof(char) * (owner_len + 1));
	if (new_owner == NULL)
	{
		free(new_name);
		free(dog);
		return (NULL);
	}

	/* Copy name and owner to new_name and new_owner */
	for (i = 0; i <= name_len; i++)
		new_name[i] = name[i];
	for (i = 0; i <= owner_len; i++)
		new_owner[i] = owner[i];

	/* Initialize dog */
	dog->name = new_name;
	dog->age = age;
	dog->owner = new_owner;

	return (dog);
}
