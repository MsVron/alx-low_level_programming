#include <stdlib.h>
#include <stdio.h>

/**
 * argstostr - Concatenates all the arguments of your program
 * @ac: The number of arguments
 * @av: The arguments
 *
 * Return: Pointer to newly allocated space
 * in memory containing concatenated string,
 * NULL on failure
 */
char *argstostr(int ac, char **av)
{
        char *str;
        int i, j, k = 0, len = 0;

        if (ac == 0 || av == NULL)
                return (NULL);

        for (i = 0; i < ac; i++)
        {
        for (j = 0; av[i][j]; j++)
                len++;
        len++;
        }

        str = malloc(sizeof(char) * (len + 1));

        if (str == NULL)
                return (NULL);

        for (i = 0; i < ac; i++)
        {
                for (j = 0; av[i][j]; j++)
                {
                        str[k] = av[i][j];
                        k++;
                }
        str[k] = '\n';
        k++;
        }

        str[k] = '\0';

        return (str);
}
