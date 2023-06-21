#include <stddef.h>
#include <stdio.h>
#include <ctype.h>
#include "main.h"

int _putchar(char c) {
    return putchar(c);
}

int _islower(int c) {
    return c >= 'a' && c <= 'z';
}

int _isalpha(int c) {
    return (_islower(c) || _isupper(c));
}

int _abs(int n) {
    return (n < 0) ? -n : n;
}

int _isupper(int c) {
    return c >= 'A' && c <= 'Z';
}

int _isdigit(int c) {
    return c >= '0' && c <= '9';
}

size_t _strlen(char *s) {
    size_t length = 0;
    while (s[length] != '\0') {
        length++;
    }
    return length;
}

void _puts(char *s) {
    while (*s != '\0') {
        _putchar(*s);
        s++;
    }
    _putchar('\n');
}

char *_strcpy(char *dest, char *src) {
    char *originalDest = dest;
    while ((*dest++ = *src++))
        ;
    return originalDest;
}

int _atoi(char *s) {
    int sign = 1;
    int result = 0;

    if (*s == '-') {
        sign = -1;
        s++;
    }

    while (*s >= '0' && *s <= '9') {
        result = result * 10 + (*s - '0');
        s++;
    }

    return sign * result;
}

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

int _strcmp(char *s1, char *s2) {
    while (*s1 && (*s1 == *s2)) {
        s1++;
        s2++;
    }

    return *(unsigned char *)s1 - *(unsigned char *)s2;
}

char *_memset(char *s, char b, unsigned int n) {
    char *originalS = s;

    while (n > 0) {
        *s = b;
        s++;
        n--;
    }

    return originalS;
}

char *_memcpy(char *dest, char *src, unsigned int n) {
    char *originalDest = dest;

    while (n > 0) {
        *dest = *src;
        dest++;
        src++;
        n--;
    }

    return originalDest;
}

char *_strchr(char *s, char c) {
    while (*s != '\0') {
        if (*s == c) {
            return s;
        }
        s++;
    }

    return NULL;
}

unsigned int _strspn(char *s, char *accept) {
    unsigned int count = 0;

    while (*s != '\0' && *accept != '\0' && *s == *accept) {
        count++;
        s++;
        accept++;
    }

    return count;
}

char *_strpbrk(char *s, char *accept) {
    while (*s != '\0') {
        char *currentAccept = accept;
        while (*currentAccept != '\0') {
            if (*s == *currentAccept) {
                return s;
            }
            currentAccept++;
        }
        s++;
    }

    return NULL;
}

char *_strstr(char *haystack, char *needle) {
    if (*needle == '\0') {
        return haystack;
    }

    while (*haystack != '\0') {
        char *h = haystack;
        char *n = needle;

        while (*n != '\0' && *h == *n) {
            h++;
            n++;
        }

        if (*n == '\0') {
            return haystack;
        }

        haystack++;
    }

    return NULL;
}
