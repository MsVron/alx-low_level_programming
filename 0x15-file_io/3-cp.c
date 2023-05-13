#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#define BUFFER_SIZE 1024

/**
 *cp - Copy the contents from one file to another.
 *@file_from: The source file.
 *@file_to: The destination file.
 *
 *Returns 0 on success, or -1 on failure.
 */
int cp(const char *file_from, const char *file_to)
{
	int fd_from, fd_to, ret;
	char buffer[BUFFER_SIZE];
	ssize_t bytes_read, bytes_written;

	/*Open the source file */
	fd_from = open(file_from, O_RDONLY);
	if (fd_from == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", file_from);
		return 98;
	}

	/*Open the destination file */
	fd_to = open(file_to, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd_to == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to file %s\n", file_to);
		close(fd_from);
		return 99;
	}

	/*Copy contents from file_from to file_to */
	while ((bytes_read = read(fd_from, buffer, BUFFER_SIZE)) > 0)
	{
		bytes_written = write(fd_to, buffer, bytes_read);
		if (bytes_written == -1 || bytes_written != bytes_read)
		{
			dprintf(STDERR_FILENO, "Error: Can't write to file %s\n", file_to);
			close(fd_from);
			close(fd_to);
			return 99;
		}
	}

	/*Check for read error */
	if (bytes_read == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", file_from);
		close(fd_from);
		close(fd_to);
		return 98;
	}

	/*Close the files */
	ret = close(fd_from);
	if (ret == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd_from);
		return 100;
	}

	ret = close(fd_to);
	if (ret == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd_to);
		return 100;
	}

	return 0;
}

int main(int argc, char *argv[])
{
	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		return 97;
	}

	if (cp(argv[1], argv[2]) != 0)
		return 99;

	return 0;
}
