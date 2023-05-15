#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#define BUFFER_SIZE 1024

#include "main.h"

void close_file(int file);

/**
 * main - Copies the contents of a file to another file.
 * @argc: The number of arguments supplied to the program.
 * @argv: An array of pointers to the arguments.
 *
 * Return: 0 on success.
 */

int main(int argc, char *argv[])
{
	int src_fd, dest_fd;
	ssize_t num_read, num_written;
	char *buffer;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	buffer = malloc(sizeof(char) * 1024);
	if (!buffer)
	{
		dprintf(STDERR_FILENO, "Error: Can't allocate memory for buffer\n");
		exit(99);
	}

	src_fd = open(argv[1], O_RDONLY);
	num_read = read(src_fd, buffer, 1024);
	dest_fd = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);

	do {
		if (src_fd == -1 || num_read == -1)
		{
			dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
			free(buffer);
			exit(98);
		}

		num_written = write(dest_fd, buffer, num_read);
		if (dest_fd == -1 || num_written == -1)
		{
			dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
			free(buffer);
			exit(99);
		}

		num_read = read(src_fd, buffer, 1024);
		dest_fd = open(argv[2], O_WRONLY | O_APPEND);
	} while (num_read > 0);

	free(buffer);
	close_file(src_fd);
	close_file(dest_fd);
	return 0;
}

/**
 * close_file - close open file
 * @file: file to close
 *
 * Return: nothing
 */

void close_file(int file)
{
	int result;

	result = close(file);
	if (result == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close file descriptor %d\n", file);
		exit(100);
	}
}
