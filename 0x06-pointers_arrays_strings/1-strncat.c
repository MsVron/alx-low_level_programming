/**
 * strncat - concatenate two strings, limiting the number of bytes from src
 *
 * @dest: pointer to destination string
 * @src: pointer to source string
 * @n: maximum number of bytes to concatenate from src
 *
 * Return: pointer to dest
 */
char *strncat(char *dest, char *src, int n)
{
        int dest_len = 0;
        int i;

        while (dest[dest_len] != '\0')
                dest_len++;

        for (i = 0; i < n && src[i] != '\0'; i++)
                dest[dest_len + i] = src[i];

        dest[dest_len + i] = '\0';

        return dest;
}
