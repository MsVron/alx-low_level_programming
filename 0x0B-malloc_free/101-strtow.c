#include <stdlib.h>
#include <string.h>

/**
 * strtow - Splits a string into words.
 * @str: The string to split.
 *
 * Return: Pointer to an array of strings (words), or NULL if fails.
 */
char **strtow(char *str)
{
	int i, j, k, len = 0, wc = 0;
	char **w, *p;

	if (str == NULL || *str == '\0')
		return (NULL);

	for (i = 0; str[i]; i++)
		if (str[i] != ' ' && (str[i + 1] == ' ' || str[i + 1] == '\0'))
			wc++;

	if (wc == 0)
		return (NULL);

	w = malloc(sizeof(char *) * (wc + 1));

	if (w == NULL)
		return (NULL);

	for (i = 0, k = 0; k < wc; k++)
        {
		while (str[i] == ' ')
			i++;

		for (j = i; str[j] != ' ' && str[j] != '\0'; j++)
			len++;

		w[k] = malloc(sizeof(char) * (len + 1));

		if (w[k] == NULL)
		{
			for (k--; k >= 0; k--)
				free(w[k]);

			free(w);
			return (NULL);
		}

		p = w[k];

		while (*str != ' ' && *str != '\0')
		{
			*p = *str;
			p++;
			str++;
		}

		*p = '\0';
		len = 0;
	}

	w[k] = NULL;

	return (w);
}
