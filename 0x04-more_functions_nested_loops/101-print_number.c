#include "main.h"

/**
 * print_number - Prints an integer to the standard output
 * @n: The integer to be printed
 *
 * Return: void
 */
void print_number(int n)
{
    int reversed = 0;
    int digit;
    int is_negative = 0;

    if (n < 0)
    {
        _putchar('-');
        n = -n;
        is_negative = 1;
    }

    while (n > 0)
    {
        digit = n % 10;
        reversed = reversed * 10 + digit;
        n /= 10;
    }

    if (reversed == 0)
    {
        _putchar('0');
    }
    else
    {
        while (reversed > 0)
        {
            digit = reversed % 10;
            _putchar('0' + digit);
            reversed /= 10;
        }
    }
}
