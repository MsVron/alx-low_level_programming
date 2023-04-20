#include "function_pointers.h"

/**
 * int_index - searches for an integer
 * @array: pointer to the array of integers to search in
 * @size: size of the array
 * @cmp: pointer to the function to be used to compare values
 *
 * Return: index of the first element for which the cmp function does not return
 * 0, -1 if no element matches or if size is <= 0
 */
int int_index(int *array, int size, int (*cmp)(int))
{
	/* check if array and cmp are not NULL and size is not <= 0 */
	if (array != NULL && cmp != NULL && size > 0)
	{
		/* loop through array and call cmp function on each element */
		for (int i = 0; i < size; i++)
		{
			/* if cmp function returns non-zero value, return index */
			if (cmp(*(array + i)) != 0)
				return (i);
		}
	}
	/* if no element matches, return -1 */
	return (-1);
}
