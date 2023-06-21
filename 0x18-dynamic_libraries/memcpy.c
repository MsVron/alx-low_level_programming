#include <stddef.h>
#include <stdio.h>
#include <ctype.h>
#include "main.h"

char *_memcpy(char *dest, char *src, unsigned int n) {
    char *originalDest = dest;
    while (n > 0) {
        *dest = *src;
        dest++;
        src++;
        n--;
    }
    return originalDest;
}
