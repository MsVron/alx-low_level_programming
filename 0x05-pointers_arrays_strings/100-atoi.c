#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <limits.h>
#include <ctype.h>
#include <string.h>

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
			// Check for integer overflow
			if (res > INT_MAX / 10 || (res == INT_MAX / 10 && s[i] - '0' > INT_MAX % 10))
			{
				fprintf(stderr, "Error: Integer overflow\n");
				exit(EXIT_FAILURE);
			}
			res = res * 10 + (s[i] - '0');
		}
		else if (res > 0)
		{
			break;
		}
		i++;
	}

	// Check for integer overflow
	if (res == INT_MIN && sign == -1)
	{
		return INT_MIN;
	}
	else if (res == INT_MAX && sign == 1)
	{
		return INT_MAX;
	}
	else if (sign == -1)
	{
		return -res;
	}
	else
	{
		return res;
	}
}
