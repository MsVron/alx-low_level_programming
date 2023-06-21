#include <stddef.h>
#include <stdio.h>
#include <ctype.h>
#include "main.h"

char *_strcat(char *dest, char *src) {
    char *originalDest = dest;
    while (*dest != '\0') {
        dest++;
    }
    while (*src != '\0') {
        *dest = *src;
        dest++;
        src++;
    }
    *dest = '\0';
    return originalDest;
}
