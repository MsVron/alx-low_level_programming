/**
 * _strpbrk - searches a string for any of a set of bytes
 * @s: the string to search in
 * @accept: the set of bytes to search for
 *
 * Return: pointer to the byte in s that matches one of the bytes in accept, or NULL if no such byte is found
 */
char *_strpbrk(char *s, char *accept)
{
    char *p;

    while (*s != '\0')
    {
        for (p = accept; *p != '\0'; p++)
        {
            if (*s == *p)
                return (s);
        }
        s++;
    }

    return (NULL);
}
