#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"

/**
 * string_nconcat - concatenates two strings
 * @s1: the first string to concatenate
 * @s2: the second string to concatenate
 * @n: the maximum number of bytes from s2 to concatenate
 *
 * Return: a pointer to the concatenated string, or NULL on failure
 */
char *string_nconcat(char *s1, char *s2, unsigned int n)
{
	char *concatenated_str;
	unsigned int s1_len, s2_len, i, j;

	if (s1 == NULL)
		s1 = "";
	if (s2 == NULL)
		s2 = "";

	s1_len = strlen(s1);
	s2_len = strlen(s2);

	if (n >= s2_len)
		n = s2_len;

	concatenated_str = malloc(s1_len + n + 1);

	if (concatenated_str == NULL)
		return (NULL);

	for (i = 0; i < s1_len; i++)
		concatenated_str[i] = s1[i];
	for (j = 0; j < n; j++)
		concatenated_str[i + j] = s2[j];
	concatenated_str[i + j] = '\0';

	return (concatenated_str);
}
