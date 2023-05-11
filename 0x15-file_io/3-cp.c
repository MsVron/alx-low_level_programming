#include "main.h"
#include <stdarg.h>

/**
 * print_error - Prints an error message to the POSIX standard error.
 * @msg: The error message to print.
 * @...: Additional arguments for the format string.
 */
void print_error(const char *msg, ...)
{
	va_list args;
	va_start(args, msg);

	vdprintf(STDERR_FILENO, msg, args);
	va_end(args);
}

/**
 *copy_file - Copies the content of a file to another file.
 *@fd_from: The source file descriptor.
 *@fd_to: The destination file descriptor.
 *
 *Return: 0 on success, or the appropriate exit code on failure.
 */
int copy_file(int fd_from, int fd_to)
{
	int bytes_read, bytes_written;
	char buffer[BUFFER_SIZE];

	while ((bytes_read = read(fd_from, buffer, BUFFER_SIZE)) > 0)
	{
		bytes_written = write(fd_to, buffer, bytes_read);
		if (bytes_written != bytes_read)
		{
			print_error("Error: Can't write to file descriptor %d\n", fd_to);
			return (99);
		}
	}

	if (bytes_read == -1)
	{
		print_error("Error: Can't read from file descriptor %d\n", fd_from);
		return (98);
	}

	return (0);
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
	int fd_from, fd_to, ret;
	struct stat st;

	fd_from = open(file_from, O_RDONLY);
	if (fd_from == -1)
	{
		print_error("Error: Can't read from file %s\n", file_from);
		return (98);
	}

	fd_to = open(file_to, O_WRONLY | O_CREAT | O_TRUNC,
		S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
	if (fd_to == -1)
	{
		print_error("Error: Can't write to %s\n", file_to);
		close(fd_from);
		return (99);
	}

	ret = copy_file(fd_from, fd_to);

	if (fstat(fd_from, &st) == 0)
		fchmod(fd_to, st.st_mode &(S_IRWXU | S_IRWXG | S_IRWXO));

	if (close(fd_from) == -1)
	{
		print_error("Error: Can't close fd %d\n", fd_from);
		close(fd_to);
		return (100);
	}

	if (close(fd_to) == -1)
	{
		print_error("Error: Can't close fd %d\n", fd_to);
		return (100);
	}

	return (ret);
}

/**
 *main - Entry point of the program.
 *@argc: The number of command-line arguments.
 *@argv: An array containing the command-line arguments.
 *
 *Return: 0 on success, or the appropriate exit code on failure.
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
