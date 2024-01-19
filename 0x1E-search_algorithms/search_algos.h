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

#endif /* SEARCH_ALGOS_H */
