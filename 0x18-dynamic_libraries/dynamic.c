#include <stddef.h>
#include <stdio.h>
#include <ctype.h>
#include "main.h"

#include <stddef.h>

int _putchar(char c) {
    return putchar(c);
}

int _islower(int c) {
    return c >= 'a' && c <= 'z';
}

int _isalpha(int c) {
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

int _abs(int n) {
    return n >= 0 ? n : -n;
}

int _isupper(int c) {
    return c >= 'A' && c <= 'Z';
}

int _isdigit(int c) {
    return c >= '0' && c <= '9';
}

int _strlen(char *s) {
    int length = 0;
    while (*s != '\0') {
        length++;
        s++;
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
    while (*src != '\0') {
        *dest = *src;
        dest++;
        src++;
    }
    *dest = '\0';
    return originalDest;
}

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
    while (*s1 != '\0' && *s2 != '\0' && *s1 == *s2) {
        s1++;
        s2++;
    }
    return *s1 - *s2;
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
    if (*s == c) {
        return s;
    }
    return NULL;
}

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
