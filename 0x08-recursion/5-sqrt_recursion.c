#include <stdio.h>
#include "main.h"

int _sqrt_helper(int n, int i);

int _sqrt_recursion(int n)
{
    return _sqrt_helper(n, 1);
}

int _sqrt_helper(int n, int i)
{
    // Base case
    if (i * i == n)
        return i;

    // Terminating case
    if (i * i > n)
        return -1;

    // Recursive case
    return _sqrt_helper(n, i + 1);
}
