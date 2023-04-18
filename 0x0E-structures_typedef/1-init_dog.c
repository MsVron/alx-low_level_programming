/**
 * init_dog - initializes a variable of type struct dog
 *
 * @d: pointer to struct dog
 * @name: pointer to name string
 * @age: float age
 * @owner: pointer to owner string
 *
 * Return: void
 */
void init_dog(struct dog *d, char *name, float age, char *owner)
{
	if (d != NULL)
	{
		d->name = name;
		d->age = age;
		d->owner = owner;
	}
}
