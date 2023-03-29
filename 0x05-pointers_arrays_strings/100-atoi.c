#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <limits.h>
#include <ctype.h>
#include <string.h>

int _isdigit(char c)
{
    return (c >= '0' && c <= '9');
}

int _atoi(char *s)
{
    int i, sign, num;

    i = 0;
    sign = 1;
    num = 0;

    while (s[i] == ' ')
        i++;

    if (s[i] == '-')
    {
        sign = -1;
        i++;
    }

    for (; _isdigit(s[i]); i++)
    {
        if (num > INT_MAX / 10 || (num == INT_MAX / 10 && (s[i] - '0') > INT_MAX % 10))
        {
            if (sign == 1)
                return INT_MAX;
            else
                return INT_MIN;
        }

        num = (num * 10) + (s[i] - '0');
    }

    return (num * sign);
}
