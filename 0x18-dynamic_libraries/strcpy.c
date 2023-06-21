#include <stddef.h>
#include <stdio.h>
#include <ctype.h>
#include "main.h"

char *_strcpy(char *dest, char *src) {
    char *originalDest = dest;
    while (*src != '\0') {
        *dest = *src;
        dest++;
        src++;
    }
    *dest = '\0';
    return originalDest;
}
