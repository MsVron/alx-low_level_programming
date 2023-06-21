#include <stddef.h>
#include <stdio.h>
#include <ctype.h>
#include "main.h"

unsigned int _strspn(char *s, char *accept) {
    unsigned int count = 0;
    while (*s != '\0') {
        int found = 0;
        char *temp = accept;
        while (*temp != '\0') {
            if (*s == *temp) {
                found = 1;
                break;
            }
            temp++;
        }
        if (found == 0) {
            break;
        }
        count++;
        s++;
    }
    return count;
}
