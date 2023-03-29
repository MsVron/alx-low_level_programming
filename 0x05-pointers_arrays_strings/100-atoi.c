#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <limits.h>
#include <ctype.h>
#include <string.h>

/**
 * _isdigit - checks if a character is a digit
 * @c: character to check
 *
 * Return: 1 if c is a digit, 0 otherwise
 */
int _isdigit(int c)
{
    return (c >= '0' && c <= '9');
}

/**
 * _atoi - convert a string to an integer
 * @s: string to convert
 *
 * Return: integer value of string
 */
int _atoi(char *s)
{
    int res = 0;
    int sign = 1;
    int i = 0;

    while (s[i] != '\0')
    {
        if (s[i] == '-')
        {
            sign *= -1;
        }
        else if (_isdigit(s[i]))
        {
            int digit = s[i] - '0';

            /* Check for integer overflow before performing arithmetic operations */
            if (res > INT_MAX / 10 || (res == INT_MAX / 10 && digit > INT_MAX % 10))
            {
                return (sign == 1) ? INT_MAX : INT_MIN;
            }

            res = res * 10 + digit;
        }
        else if (res > 0)
        {
            break;
        }
        i++;
    }

    return (sign * res);
}
