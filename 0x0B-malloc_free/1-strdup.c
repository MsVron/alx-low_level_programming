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
    char *dup_str;
    unsigned int len = 0, i;

    if (str == NULL)
        return (NULL);

    /* calculate length of str */
    while (str[len])
        len++;

    dup_str = malloc(sizeof(char) * (len + 1));

    if (dup_str == NULL)
        return (NULL);

    /* copy str to dup_str */
    for (i = 0; i <= len; i++)
        dup_str[i] = str[i];

    return (dup_str);
}
