#include <stddef.h>
#include <stdio.h>
#include <ctype.h>
#include "main.h"

char *_strstr(char *haystack, char *needle) {
    while (*haystack != '\0') {
        char *startHaystack = haystack;
        char *tempNeedle = needle;
        while (*haystack == *tempNeedle && *tempNeedle != '\0') {
            haystack++;
            tempNeedle++;
        }
        if (*tempNeedle == '\0') {
            return startHaystack;
        }
        haystack = startHaystack + 1;
    }
    return NULL;
}
