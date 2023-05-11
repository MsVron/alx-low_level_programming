#include "main.h"

/**
 * create_file - Creates a file with the given filename and writes the
 *               text_content to it.
 * @filename: The name of the file to create.
 * @text_content: The text content to write to the file.
 *
 * Return: 1 on success, -1 on failure.
 *          If the file already exists, it is truncated.
 *          If filename is NULL, return -1.
 *          If text_content is NULL, create an empty file.
 */
int create_file(const char *filename, char *text_content)
{
    int file_descriptor;

    if (filename == NULL)
        return (-1);

    file_descriptor = open(filename, O_WRONLY | O_CREAT | O_TRUNC,
                           S_IRUSR | S_IWUSR);
    if (file_descriptor == -1)
        return (-1);

    if (text_content != NULL)
    {
        int bytes_written = write(file_descriptor, text_content,
                                  strlen(text_content));
        if (bytes_written == -1)
        {
            close(file_descriptor);
            return (-1);
        }
    }

    close(file_descriptor);

    return (1);
}
