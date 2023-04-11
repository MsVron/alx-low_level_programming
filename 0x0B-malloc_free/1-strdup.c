#include <stdlib.h>

/**
 * _strdup - returns a pointer to a newly allocated space in memory,
 *           which contains a copy of the string given as a parameter.
 * @str: string to be duplicated.
 *
 * Return: pointer to the duplicated string or NULL if str is NULL or if
 *         insufficient memory was available.
 */

char *_strdup(char *str)
{
	int i = 0, l = 0;
	char *s;

	if (str == NULL)
		return (NULL);

	/*calculate size of str*/
	while (str[l] != '\0')
		l++;

	s = malloc((l + 1) * sizeof(char));
	if (s == NULL)
		return (NULL);

	while (str[i] != '\0')
	{
		s[i] = str[i];
		i++;
	}

	return (s);
}
