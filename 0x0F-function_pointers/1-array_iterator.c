#include "function_pointers.h"

/**
 * array_iterator - executes a function on each element of an array
 * @array: pointer to the array
 * @size: size of the array
 * @action: pointer to the function to execute
 *
 * Return: void
 */
void array_iterator(int *array, size_t size, void (*action)(int))
{
    /* check if array and action are not NULL */
    if (array != NULL && action != NULL)
    {
        /* execute the function on each element of the array */
        for (size_t i = 0; i < size; i++)
        {
            action(array[i]);
        }
    }
}
