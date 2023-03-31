#include "main.h"

/**
 * infinite_add - Adds two numbers stored as strings
 * @n1: First number
 * @n2: Second number
 * @r: Buffer to store the result
 * @size_r: Size of the buffer
 *
 * Return: Pointer to the buffer, or 0 if the buffer is too small
 */
char *infinite_add(char *n1, char *n2, char *r, int size_r)
{
    int l1 = 0, l2 = 0, big, add, re = 0, n1_int, n2_int;

    /* Find length of the strings */
    while (*(n1 + l1))
        l1++;
    while (*(n2 + l2))
        l2++;

    /* Check if the buffer is large enough */
    if (l1 + 1 > size_r || l2 + 1 > size_r || size_r <= 0)
        return (0);

    /* Initialize variables */
    big = l1 >= l2 ? l1 : l2;
    *(r + big + 1) = '\0';
    l1--, l2--, size_r--;

    /* Add digits from right to left */
    while (big >= 0)
    {
        n1_int = l1 >= 0 ? *(n1 + l1--) - '0' : 0;
        n2_int = l2 >= 0 ? *(n2 + l2--) - '0' : 0;
        add = n1_int + n2_int + re;
        if (add >= 10)
            re = 1;
        else
            re = 0;
        *(r + big--) = add % 10 + '0';
        size_r--;
        if (size_r < 0)
            return (0);
    }

    /* Add carry digit if necessary */
    if (re)
    {
        if (size_r < 1)
            return (0);
        *(--r) = re + '0';
    }

    /* Remove leading zeros */
    while (*r == '0' && *(r+1) != '\0')
        r++;

    return (r);
}
