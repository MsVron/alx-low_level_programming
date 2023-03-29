#include <stdio.h>
#include <string.h>

/**
 * _strcat - concatenates two strings.
 * @dest: pointer to destination string.
 * @src: pointer to source string.
 *
 * Return: a pointer to the resulting string dest.
 */
char *_strcat(char *dest, char *src)
{
	char *result = dest;

	/* Find the end of dest string */
	while (*dest != '\0')
	{
		dest++;
	}

	/* Append src to dest */
	while (*src != '\0')
	{
		*dest = *src;
		dest++;
		src++;
	}

	/* Add a terminating null byte to the end of dest */
	*dest = '\0';

	return result;
}
