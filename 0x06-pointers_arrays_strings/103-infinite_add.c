/**
 * infinite_add - Adds two numbers
 * @n1: The first number to add
 * @n2: The second number to add
 * @r: The buffer to store the result
 * @size_r: The size of the buffer
 *
 * Return: A pointer to the result, or 0 if the buffer is too small
 */
char *infinite_add(char *n1, char *n2, char *r, int size_r)
{
    int i = 0, j = 0, k = 0, carry = 0, sum = 0, len1 = 0, len2 = 0;

    while (*(n1 + len1))
        len1++;
    while (*(n2 + len2))
        len2++;

    if (len1 + 1 > size_r || len2 + 1 > size_r)
        return (0);

    len1--;
    len2--;

    while (len1 >= 0 || len2 >= 0)
    {
        sum = carry;
        if (len1 >= 0)
            sum += *(n1 + len1--) - '0';
        if (len2 >= 0)
            sum += *(n2 + len2--) - '0';

        *(r + k++) = sum % 10 + '0';
        carry = sum / 10;
    }

    if (carry)
        *(r + k++) = carry + '0';

    if (k > size_r)
        return (0);

    *(r + k) = '\0';

    i = 0;
    j = k - 1;

    while (i < j)
    {
        *(r + i) ^= *(r + j);
        *(r + j) ^= *(r + i);
        *(r + i) ^= *(r + j);

        i++;
        j--;
    }

    return (r);
}
