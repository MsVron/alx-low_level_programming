#include "main.h"

/**
 * append_text_to_file - Appends text_content to the end of a file.
 * @filename: The name of the file.
 * @text_content: The text content to append to the file.
 *
 * Return: 1 on success, -1 on failure.
 *         If filename is NULL, return -1.
 *         If text_content is NULL or file cannot be written, return -1.
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int file_descriptor, bytes_written;
	ssize_t text_length = 0;

	if (filename == NULL)
		return (-1);

	if (text_content != NULL)
	{
		/* Calculate the length of the text_content */
		while (text_content[text_length])
			text_length++;

		file_descriptor = open(filename, O_WRONLY | O_APPEND);
		if (file_descriptor == -1)
			return (-1);

		bytes_written = write(file_descriptor, text_content, text_length);
		if (bytes_written == -1 || bytes_written != text_length)
		{
			close(file_descriptor);
			return (-1);
		}

		close(file_descriptor);
	}

	return (1);
}
