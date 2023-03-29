/**
 * _strncat - Concatenates two strings.
 *
 * @dest: Pointer to destination string.
 * @src: Pointer to source string.
 * @n: Maximum number of bytes from @src.
 *
 * Return: Pointer to the resulting string @dest.
 */
char *_strncat(char *dest, char *src, int n)
{
    int dest_size = 0, i;

    /* Find the size of the destination string */
    while (dest[dest_size])
        dest_size++;

    /**
     * Source string does not need to be null-terminated
     * if it contains n or more bytes
     */
    for (i = 0; i < n && src[i] != '\0'; i++)
        dest[dest_size + i] = src[i];
    
    /* Null terminate the resulting string @dest */
    dest[dest_size + i] = '\0';

    return (dest);
}
