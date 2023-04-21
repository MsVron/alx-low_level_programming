#include "variadic_functions.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * print_char - prints a char
 * @args: the va_list of arguments
 *
 * Return: void
 */
void print_char(va_list args)
{
	char c = va_arg(args, int);
	printf("%c", c);
}

/**
 * print_int - prints an int
 * @args: the va_list of arguments
 *
 * Return: void
 */
void print_int(va_list args)
{
	int i = va_arg(args, int);
	printf("%d", i);
}

/**
 * print_float - prints a float
 * @args: the va_list of arguments
 *
 * Return: void
 */
void print_float(va_list args)
{
	double d = va_arg(args, double);
	printf("%f", d);
}

/**
 * print_string - prints a string
 * @args: the va_list of arguments
 *
 * Return: void
 */
void print_string(va_list args)
{
	char *s = va_arg(args, char *);

	if (!s)
		s = "(nil)";
	printf("%s", s);
}

/**
 * print_all - prints anything
 * @format: list of types of arguments passed to the function
 * c: char
 * i: integer
 * f: float
 * s: char * (if the string is NULL, print (nil) instead
 * any other char should be ignored
 *
 * Return: void
 */
void print_all(const char * const format, ...)
{
	va_list args;
	const char *p = format;

	va_start(args, format);

	while (p && *p)
	{
		switch (*p++)
		{
			case 'c':
				print_char(args);
				break;

			case 'i':
				print_int(args);
				break;

			case 'f':
				print_float(args);
				break;

			case 's':
				print_string(args);
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
