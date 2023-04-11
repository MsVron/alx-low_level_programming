#include <stdio.h>

/**
 * main - Entry point
 * @argc: The number of arguments passed to the program
 * @argv: An array of pointers to the arguments
 *
 * Return: Always 0 (Success)
 */
int main(int argc, char *argv[])
{
    /* Print the first argument, which is the program name */
    (void)argc;
    printf("%s\n", argv[0]);
    return (0);
}
