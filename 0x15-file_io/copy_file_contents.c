#include "main.h"

/**
 *copy_file_contents - Copies the contents of the source file to the destination file.
 *@fd_from: The file descriptor of the source file.
 *@fd_to: The file descriptor of the destination file.
 *
 *Return: 0 on success, or the appropriate exit code on failure.
 */
int copy_file_contents(int fd_from, int fd_to)
{
	char buffer[BUFFER_SIZE];
	ssize_t bytes_read, bytes_written;

	while ((bytes_read = read(fd_from, buffer, BUFFER_SIZE)) > 0)
	{
		bytes_written = write(fd_to, buffer, bytes_read);
		if (bytes_written != bytes_read)
		{
			dprintf(STDERR_FILENO, "Error: Can't write to destination file\n");
			return (99);
		}
	}

	if (bytes_read == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from source file\n");
		return (98);
	}

	return (0);
}
