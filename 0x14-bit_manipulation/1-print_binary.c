#include "main.h"

/**
 *print_binary - prints the binary representation of a number
 *@n: the number to print in binary
 */
void print_binary(unsigned long int n)
{
	unsigned long int mask = 1UL << ((sizeof(unsigned long int) * 8) - 1);
	int flag = 0;

	while (mask > 0)
	{
		if ((n & mask) == mask)
		{
			flag = 1;
			putchar('1');
		}
		else if (flag == 1 || mask == 1)
		{
			putchar('0');
		}

		mask = mask >> 1;
	}
}
