#include <stdlib.h>
#include <string.h>

/**
 * strtow - splits a string into words
 * @str: string to split
 *
 * Return: pointer to an array of strings (words)
 *         NULL if str == NULL or str == ""
 *         NULL if memory allocation fails
 */
char **strtow(char *str)
{
	char **words, *tmp;
	int i, j, count = 0, len = 0, start, end;

	if (str == NULL || *str == '\0')
		return (NULL);

	for (i = 0; str[i]; i++)
	{
		if (str[i] != ' ' && (i == 0 || str[i - 1] == ' '))
			count++;
	}

	words = malloc(sizeof(char *) * (count + 1));

	if (words == NULL)
		return (NULL);

	for (i = 0, j = 0; str[i]; i++)
	{
		if (str[i] != ' ' && (i == 0 || str[i - 1] == ' '))
		{
			start = i;
			while (str[i] && str[i] != ' ')
				i++;
			end = i - 1;
			len = end - start + 1;
			tmp = malloc(sizeof(char) * (len + 1));

			if (tmp == NULL)
			{
				free_words(words, j);
				return (NULL);
			}

			strncpy(tmp, &str[start], len);
			tmp[len] = '\0';
			words[j] = tmp;
			j++;
		}
	}

	words[j] = NULL;
	return (words);
}

/**
 * free_words - frees memory allocated for an array of strings
 * @words: array of strings
 * @count: number of strings in the array
 */
void free_words(char **words, int count)
{
	int i;

	for (i = 0; i < count; i++)
		free(words[i]);

	free(words);
}
