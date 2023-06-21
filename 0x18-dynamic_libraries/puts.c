#include <stddef.h>
#include <stdio.h>
#include <ctype.h>
#include "main.h"

void _puts(char *s) {
    while (*s != '\0') {
        _putchar(*s);
        s++;
    }
    _putchar('\n');
}
