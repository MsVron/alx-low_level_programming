/**
 * infinite_add - adds two numbers
 * @n1: first number
 * @n2: second number
 * @r: buffer to store result
 * @size_r: buffer size
 * Return: pointer to result, or 0 if result cannot be stored in r
 */
char *infinite_add(char *n1, char *n2, char *r, int size_r)
{
	int len1, len2, i, j, sum, carry;

	/* Find lengths of n1 and n2 */
	for (len1 = 0; n1[len1]; len1++)
		;
	for (len2 = 0; n2[len2]; len2++)
		;

	/* Check if result can fit in buffer */
	if (len1 > size_r - 1 || len2 > size_r - 1)
		return (0);

	/* Add digits from right to left */
	for (i = len1 - 1, j = len2 - 1, carry = 0; i >= 0 || j >= 0 || carry; i--, j--)
	{
		sum = carry;
		if (i >= 0)
			sum += n1[i] - '0';
		if (j >= 0)
			sum += n2[j] - '0';

		if (sum > 9)
		{
			carry = 1;
			sum -= 10;
		}
		else
			carry = 0;

		/* Store digit in buffer */
		r[i + j + 1] = sum + '0';
	}
	r[len1 + len2] = '\0';

	/* Reverse result in buffer */
	for (i = 0, j = len1 + len2 - 1; i < j; i++, j--)
	{
		char temp = r[i];
		r[i] = r[j];
		r[j] = temp;
	}

	return (r);
}
