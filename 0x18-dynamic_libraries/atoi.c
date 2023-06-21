#include <stddef.h>
#include <stdio.h>
#include <ctype.h>
#include "main.h"

int _atoi(void) {
    char input[100];
    printf("Enter a number: ");
    scanf("%s", input);

    int result = 0;
    int sign = 1;
    char *s = input;

    if (*s == '-') {
        sign = -1;
        s++;
    }

    while (*s != '\0') {
        if (*s >= '0' && *s <= '9') {
            result = result * 10 + (*s - '0');
        } else {
            break;
        }
        s++;
    }

    return result * sign;
}
