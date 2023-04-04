#include <stdio.h>

/**
 * print_diagsums - Prints the sum of the two diagonals of a square matrix of integers
 * @a: Pointer to the matrix
 * @size: Size of the matrix
 */
void print_diagsums(int *a, int size)
{
    int i, j;
    int sum1 = 0, sum2 = 0;

    /* Traverse through the matrix and add the diagonal elements */
    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size; j++)
        {
            if (i == j)
                sum1 += *((a + i * size) + j); /* Sum of primary diagonal */
            if (i == size - j - 1)
                sum2 += *((a + i * size) + j); /* Sum of secondary diagonal */
        }
    }
    printf("%d, %d\n", sum1, sum2);
}
