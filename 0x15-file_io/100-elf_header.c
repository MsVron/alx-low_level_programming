#include "main.h"
#define ELF_MAGIC 0x7f454c46

/*
 *main()
 *
 *The main() function is the entry point for the program. It parses the command-line arguments, opens the ELF file, reads the ELF header, and prints the ELF header information.
 *
 *Parameters:
 *
 *argc: The number of command-line arguments.
 *argv: An array of pointers to the command-line arguments.
 */
int main(int argc, char *argv[])
{
	/*Check the number of command-line arguments. */
	if (argc != 2)
	{
		/*Print an error message and exit. */
		fprintf(stderr, "Usage: elf_header elf_filename\n");
		exit(1);
	}

	/*Open the ELF file. */
	FILE * fp;
	fp = fopen(argv[1], "rb");
	if (fp == NULL)
	{
		/*Print an error message and exit. */
		perror("fopen");
		exit(1);
	}

	unsigned char elf_header[64];
	if (fread(elf_header, 1, 64, fp) != 64)
	{
		/*error */
		perror("fread");
		exit(1);
	}

	if (elf_header[0] != ELF_MAGIC)
	{
		/*error msg */
		fprintf(stderr, "Not an ELF file\n");
		exit(1);
	}

	/*ELF header information. */
	printf("ELF Header:\n");
	printf("  Magic:   0x%08x\n", elf_header[0] << 24 | elf_header[1] << 16 | elf_header[2] << 8 | elf_header[3]);
	printf("  Class:                             %d\n", elf_header[4] >> 4);
	printf("  Data:                              %d\n", elf_header[4] &0xf);
	printf("  Version:                           %d\n", elf_header[5]);
	printf("  OS/ABI:                            %d\n", elf_header[6] >> 4);
	printf("  ABI Version:                       %d\n", elf_header[6] &0xf);
	printf("  Type:                              %d\n", elf_header[7]);
	printf("  Entry point address:               0x%08x\n", elf_header[8] << 24 | elf_header[9] << 16 | elf_header[10] << 8 | elf_header[11]);

	fclose(fp);

	return (0);
}
