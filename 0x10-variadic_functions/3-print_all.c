#include "variadic_functions.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * print_all - prints anything
 * @format: list of types of arguments passed to the function
 * c: char
 * i: integer
 * f: float
 * s: char * (if the string is NULL, print (nil) instead
 * any other char should be ignored
 */
void print_all(const char * const format, ...)
{
	va_list args;
	const char *p = format;
	char c;
	int i;
	double d;
	char *s;

	va_start(args, format);

	while (p && *p)
	{
		switch (*p++)
		{
			case 'c':
				c = va_arg(args, int);
				printf("%c", c);
				break;
			case 'i':
				i = va_arg(args, int);
				printf("%d", i);
				break;
			case 'f':
				d = va_arg(args, double);
				printf("%f", d);
				break;
			case 's':
				s = va_arg(args, char *);
				if (!s)
					s = "(nil)";
				printf("%s", s);
				break;
			default:
				continue;
		}

		if (*p)
			printf(", ");
	}

	va_end(args);
	printf("\n");
}
