#include <stddef.h>
#include <stdio.h>
#include <ctype.h>
#include "main.h"

char *_strncat(char *dest, char *src, int n) {
    char *originalDest = dest;
    while (*dest != '\0') {
        dest++;
    }
    while (*src != '\0' && n > 0) {
        *dest = *src;
        dest++;
        src++;
        n--;
    }
    *dest = '\0';
    return originalDest;
}
