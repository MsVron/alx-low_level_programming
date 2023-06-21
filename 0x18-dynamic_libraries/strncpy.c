#include <stddef.h>
#include <stdio.h>
#include <ctype.h>
#include "main.h"

char *_strncpy(char *dest, char *src, int n) {
    char *originalDest = dest;
    while (*src != '\0' && n > 0) {
        *dest = *src;
        dest++;
        src++;
        n--;
    }
    while (n > 0) {
        *dest = '\0';
        dest++;
        n--;
    }
    return originalDest;
}
