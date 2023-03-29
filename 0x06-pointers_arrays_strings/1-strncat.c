/**
 * _strncat - concatenate two strings, limiting the number of bytes to copy.
 *
 * @dest: pointer to the destination string
 * @src: pointer to the source string
 * @n: maximum number of bytes to concatenate
 *
 * Return: pointer to the resulting string @dest
 */
char *_strncat(char *dest, const char *src, size_t n)
{
    size_t dest_len = 0;
    
    // Find the end of dest string
    while (dest[dest_len] != '\0')
        dest_len++;

    // Append at most n bytes from src to dest
    for (size_t i = 0; i < n && src[i] != '\0'; i++)
        dest[dest_len + i] = src[i];

    // Add a terminating null byte to the end of dest
    dest[dest_len + n] = '\0';

    return dest;
}
