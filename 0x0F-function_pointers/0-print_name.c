#include "function_pointers.h"
#include <stdlib.h>

/**
 * print_name - prints a name
 * @name: pointer to a char array containing the name to print
 * @f: pointer to a function that takes a char pointer as argument
 *     and returns nothing
 *
 * Return: void
 */
void print_name(char *name, void (*f)(char *))
{
	/* check if name and function pointer are not NULL */
	if (name != NULL && f != NULL)
	{
		/* call function pointer with name as argument */
		f(name);
	}
}
