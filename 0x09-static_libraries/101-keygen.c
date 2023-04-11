#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <limits.h>
#include <ctype.h>
#include <string.h>

/**
 * _atoi - convert a string to an integer.
 *
 * @s: the string to convert.
 *
 * Return: the integer value of the string.
 */
int _atoi(char *s)
{
    int sign = 1, value = 0, max_int = INT_MAX / 10, min_int = INT_MIN / 10;
    char *p = s;

    /* skip leading whitespace */
    while (isspace(*p))
    {
        p++;
    }

    /* handle sign */
    if (*p == '-')
    {
        sign = -1;
        p++;
    }
    else if (*p == '+')
    {
        sign = 1;
        p++;
    }

    /* process digits */
    while (isdigit(*p))
    {
        int digit = *p - '0';

        /* check for integer overflow */
        if (value > max_int || (value == max_int && digit > 7))
        {
            return (sign == 1) ? INT_MAX : INT_MIN;
        }

        /* check for integer underflow */
        if (value < min_int || (value == min_int && digit > 8))
        {
            return (sign == 1) ? INT_MAX : INT_MIN;
        }

        value = value * 10 + digit;
        p++;
    }

    return sign * value;
}
