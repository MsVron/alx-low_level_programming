#ifndef SEARCH_ALGOS_H
#define SEARCH_ALGOS_H

#include <stddef.h>
#include <stdlib.h>
#include <math.h>

/* Function prototypes */
int linear_search(int *array, size_t size, int value);
int binary_search(int *array, size_t size, int value);
size_t min(size_t a, size_t b);
int jump_search(int *array, size_t size, int value);
int interpolation_search(int *array, size_t size, int value);
int exponential_search(int *array, size_t size, int value);
int binary_search1(int *array, size_t low, size_t high, int value, size_t mid);
void print_subarray(int *array, size_t low, size_t high);
int advanced_binary_recursive(int *array, size_t low, size_t high, int value);
int advanced_binary(int *array, size_t size, int value);

#endif /* SEARCH_ALGOS_H */
