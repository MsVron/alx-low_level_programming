/**
 * leet - Encodes a string into 1337.
 *
 * @str: The string to be encoded.
 *
 * Return: The resulting encoded string.
 */
char *leet(char *str)
{
    int i, j;
    char *leet_str = str;

    /* Encoding rules */
    char letters[] = "aAeEoOtTlL";
    char numbers[] = "44337011";

    /* Loop through each character of the string */
    for (i = 0; str[i] != '\0'; i++)
    {
        /* Loop through each letter of the encoding rules */
        for (j = 0; letters[j] != '\0'; j++)
        {
            /* If the current character matches a letter from the encoding rules */
            if (str[i] == letters[j])
            {
                /* Replace the letter with the corresponding number */
                leet_str[i] = numbers[j];
                break;
            }
        }
    }

    return leet_str;
}
