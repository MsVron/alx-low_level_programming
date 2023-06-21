#include <stddef.h>
#include <stdio.h>
#include <ctype.h>
#include "main.h"

char *_strpbrk(char *s, char *accept) {
    while (*s != '\0') {
        char *temp = accept;
        while (*temp != '\0') {
            if (*s == *temp) {
                return s;
            }
            temp++;
        }
        s++;
    }
    return NULL;
}
