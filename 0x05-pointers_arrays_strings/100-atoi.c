#include "main.h"

/**
 * _atoi - converts a string to an integer
 * @s: the string to convert
 *
 * Return: the integer value of the string
 */
int _atoi(char *s)
{
    int sign = 1;
    int result = 0;
    int i = 0;

    /* skip leading white space */
    while (s[i] == ' ')
    {
        i++;
    }

    /* check for sign */
    if (s[i] == '-')
    {
        sign = -1;
        i++;
    }
    else if (s[i] == '+')
    {
        i++;
    }

    /* convert digits to integer */
    while (s[i] >= '0' && s[i] <= '9')
    {
        result = (result * 10) + (s[i] - '0');
        i++;
    }

    return result * sign;
}
