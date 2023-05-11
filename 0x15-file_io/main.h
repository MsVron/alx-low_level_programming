#ifndef MAIN_H
#define MAIN_H
#define BUFFER_SIZE 1024
#define ELF_MAGIC_SIZE 4

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <elf.h>
#include <stdint.h>
#include <errno.h>

ssize_t read_textfile(const char *filename, size_t letters);
int create_file(const char *filename, char *text_content);
int append_text_to_file(const char *filename, char *text_content);

void print_error(const char *message);
void print_elf_header(const char *filename);

/**
 * struct CustomElf64_Ehdr - Custom ELF 64-bit header
 *
 * @e_ident:     ELF identification bytes
 * @e_type:      Object file type
 * @e_machine:   Architecture
 * @e_version:   Object file version
 * @e_entry:     Entry point virtual address
 * @e_phoff:     Program header table file offset
 * @e_shoff:     Section header table file offset
 * @e_flags:     Processor-specific flags
 * @e_ehsize:    ELF header size in bytes
 * @e_phentsize: Program header table entry size
 * @e_phnum:     Number of program header table entries
 * @e_shentsize: Section header table entry size
 * @e_shnum:     Number of section header table entries
 * @e_shstrndx:  Section header table index of string table
 */
typedef struct
{
	unsigned char e_ident[ELF_MAGIC_SIZE];
	uint16_t e_type;
	uint16_t e_machine;
	uint32_t e_version;
	uint64_t e_entry;
	uint64_t e_phoff;
	uint64_t e_shoff;
	uint32_t e_flags;
	uint16_t e_ehsize;
	uint16_t e_phentsize;
	uint16_t e_phnum;
	uint16_t e_shentsize;
	uint16_t e_shnum;
	uint16_t e_shstrndx;
} CustomElf64_Ehdr;


#endif /* MAIN_H */
