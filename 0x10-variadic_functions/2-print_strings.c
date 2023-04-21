#include "variadic_functions.h"
#include <stdarg.h>
#include <stdio.h>

/**
 * print_strings - prints strings, followed by a new line.
 * @separator: the string to be printed between the strings.
 * @n: the number of strings passed to the function.
 *
 * Return: Nothing.
 */
void print_strings(const char *separator, const unsigned int n, ...)
{
	va_list args;
	unsigned int i;
	char *str;

	if (n == 0)
	{
		printf("\n");
		return;
	}

	va_start(args, n);

	str = va_arg(args, char *);
	if (str == NULL)
		printf("(nil)");
	else
		printf("%s", str);

	for (i = 1; i < n; i++)
	{
		str = va_arg(args, char *);
		if (str == NULL)
			printf("%s(nil)", separator);
		else
			printf("%s%s", separator, str);
	}

	va_end(args);

	printf("\n");
}
