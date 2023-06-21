#include <stddef.h>
#include <stdio.h>
#include <ctype.h>
#include "main.h"

int _isalpha(int c) {
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}
