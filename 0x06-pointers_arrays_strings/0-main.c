#include <stdio.h>

/**
 * _strcat - Concatenates two strings.
 * @dest: Pointer to destination string.
 * @src: Pointer to source string.
 * @n: Maximum number of characters to concatenate from the source string.
 *
 * Return: A pointer to the resulting string dest.
 */
char *_strcat(char *dest, const char *src, size_t n)
{
	size_t dest_len = 0;

	while (dest[dest_len] != '\0')
		dest_len++;

	for (size_t i = 0; i < n && src[i] != '\0'; i++)
		dest[dest_len + i] = src[i];

	dest[dest_len + n] = '\0';

	return dest;
}
