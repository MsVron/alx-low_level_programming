#include "main.h"

/**
 *print_error - Prints an error message to the POSIX standard error.
 *@msg: The error message to print.
 */
void print_error(const char *msg)
{
	dprintf(STDERR_FILENO, "%s\n", msg);
}

/**
 *open_source_file - Opens the source file for reading.
 *@file_from: The source file.
 *
 *Return: The file descriptor on success, or -1 on failure.
 */
int open_source_file(const char *file_from)
{
	int fd_from = open(file_from, O_RDONLY);
	if (fd_from == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", file_from);
	}

	return fd_from;
}

/**
 *open_dest_file - Opens the destination file for writing.
 *@file_to: The destination file.
 *
 *Return: The file descriptor on success, or -1 on failure.
 */
int open_dest_file(const char *file_to)
{
	int fd_to = open(file_to, O_WRONLY | O_CREAT | O_TRUNC,
		S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
	if (fd_to == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", file_to);
	}

	return fd_to;
}

/**
 *cp - Copies the content of a file to another file.
 *@file_from: The source file.
 *@file_to: The destination file.
 *
 *Return: 0 on success, or the appropriate exit code on failure.
 */
int cp(const char *file_from, const char *file_to)
{
	int fd_from, fd_to, result;

	fd_from = open_source_file(file_from);
	if (fd_from == -1)
	{
		return (98);
	}

	fd_to = open_dest_file(file_to);
	if (fd_to == -1)
	{
		close(fd_from);
		return (99);
	}

	result = copy_file_contents(fd_from, fd_to);

	if (close(fd_from) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close source file\n");
		result = 100;
	}

	if (close(fd_to) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close destination file\n");
		result = 100;
	}

	return (result);
}

/**

main - Entry point of the program.

@argc: The number of command-line arguments.

@argv: An array containing the command-line arguments.

Return: 0 on success, or the appropriate exit code on failure.
*/
int main(int argc, char *argv[])
{
	if (argc != 3)
	{
		print_error("Usage: cp file_from file_to");
		return (97);
	}

	exit(cp(argv[1], argv[2]));
}
