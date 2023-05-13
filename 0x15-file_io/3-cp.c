#include "main.h"

/**
 *file_exists - Checks if a file exists.
 *@filename: The path to the file to check.
 *
 *Returns 1 if the file exists, or 0 if it does not.
 */
int file_exists(const char *filename)
{
	FILE *file = fopen(filename, "r");
	if (file == NULL)
	{
		return 0;
	}

	fclose(file);
	return 1;
}

/**
 *cp - Copy the contents from one file to another.
 *@file_from: The source file.
 *@file_to: The destination file.
 *
 *Returns 0 on success, or -1 on failure.
 */
int cp(const char *file_from, const char *file_to)
{
	/*Check if the source file exists */
	if (!file_exists(file_from))
	{
		fprintf(stderr, "Error: Source file %s does not exist\n", file_from);
		return -1;
	}

	/*Open the files */
	FILE *file_from_fd = fopen(file_from, "r");
	if (file_from_fd == NULL)
	{
		fprintf(stderr, "Error: Can't read from file %s\n", file_from);
		return -1;
	}

	FILE *file_to_fd = fopen(file_to, "w");
	if (file_to_fd == NULL)
	{
		fprintf(stderr, "Error: Can't write to file %s\n", file_to);
		fclose(file_from_fd);
		return -1;
	}

	/*Copy contents from file_from to file_to */
	char buffer[1024];
	size_t bytes_read;
	while ((bytes_read = fread(buffer, 1, sizeof(buffer), file_from_fd)) > 0)
	{
		fwrite(buffer, 1, bytes_read, file_to_fd);
	}

	/*Close the files */
	if (fclose(file_from_fd) != 0)
	{
		fprintf(stderr, "Error: Can't close file %s\n", file_from);
		return -1;
	}

	if (fclose(file_to_fd) != 0)
	{
		fprintf(stderr, "Error: Can't close file %s\n", file_to);
		return -1;
	}

	return 0;
}

/**
 *main - Entry point of the program.
 *@argc: The number of command-line arguments.
 *@argv: An array of strings containing the command-line arguments.
 *
 *Return: 0 on success, or an error code on failure.
 */
int main(int argc, char *argv[])
{
	/*Check the number of arguments */
	if (argc != 3)
	{
		fprintf(stderr, "Usage: cp file_from file_to\n");
		return 97;
	}

	/*Copy the file */
	if (cp(argv[1], argv[2]) < 0)
	{
		return 99;
	}

	return 0;
}
