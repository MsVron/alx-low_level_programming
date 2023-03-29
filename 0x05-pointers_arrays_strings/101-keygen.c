#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

/**
 * _atoi - convert a string to an integer.
 *
 * @s: the string to convert.
 *
 * Return: the integer value of the string.
 */

int _atoi(char *s)
{
	int sign = 1, value = 0;
	char *p = s;

	/* skip leading whitespace */
	while (*p == ' ' || *p == '\t' || *p == '\n' || *p == '\r' || *p == '\f' || *p == '\v')
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
	while (*p >= '0' && *p <= '9')
	{
		value = value * 10 + (*p - '0');
		p++;
	}

	return sign * value;
}
