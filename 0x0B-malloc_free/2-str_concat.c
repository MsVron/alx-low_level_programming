#include <stdlib.h>
#include <stdio.h>

/**
 * str_concat - Concatenates two strings
 * @s1: The first string to concatenate
 * @s2: The second string to concatenate
 *
 * Return: Pointer to newly allocated space in memory containing concatenated
 * string, NULL on failure
 */
char *str_concat(char *s1, char *s2)
{
    char *concat_str;
    int s1_len = 0, s2_len = 0, i, j;

    if (s1 == NULL)
        s1 = "";
    if (s2 == NULL)
        s2 = "";

    while (s1[s1_len])
        s1_len++;

    while (s2[s2_len])
        s2_len++;

    concat_str = malloc(sizeof(char) * (s1_len + s2_len + 1));

    if (concat_str == NULL)
        return (NULL);

    for (i = 0; s1[i]; i++)
        concat_str[i] = s1[i];

    for (j = 0; s2[j]; j++)
        concat_str[i + j] = s2[j];

    concat_str[i + j] = '\0';

    return (concat_str);
}
