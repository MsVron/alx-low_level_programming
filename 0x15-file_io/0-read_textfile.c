#include "main.h"

/**
 *read_textfile - Reads a text file and prints it to the POSIX standard output.
 *@filename: The name of the file to read.
 *@letters: The number of letters to read and print.
 *
 *Return: The actual number of letters read and printed, or 0 on failure.
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	if (filename == NULL)
		return 0;

	FILE *file;
	char *buffer;
	ssize_t bytesRead, bytesWritten;

	file = fopen(filename, "r");
	if (file == NULL)
		return 0;

	buffer = malloc(sizeof(char) * (letters + 1));
	if (buffer == NULL)
	{
		fclose(file);
		return 0;
	}

	bytesRead = fread(buffer, sizeof(char), letters, file);
	if (ferror(file) != 0 || bytesRead == 0)
	{
		fclose(file);
		free(buffer);
		return 0;
	}

	buffer[bytesRead] = '\0';

	bytesWritten = write(STDOUT_FILENO, buffer, (size_t)bytesRead);
	if (bytesWritten == -1 || (size_t)bytesWritten != (size_t)bytesRead)
	{
		fclose(file);
		free(buffer);
		return 0;
	}

	fclose(file);
	free(buffer);

	return bytesRead;
}
