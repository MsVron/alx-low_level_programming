#include "main.h"

void print_error(const char *message) {
    fprintf(stderr, "Error: %s\n", message);
    exit(98);
}

void print_elf_header(const char *filename) {
    int fd = open(filename, O_RDONLY);
    if (fd == -1)
        print_error("Failed to open the file");

    Elf64_Ehdr elf_header;
    ssize_t bytes_read = read(fd, &elf_header, sizeof(Elf64_Ehdr));
    if (bytes_read == -1)
        print_error("Failed to read the ELF header");

    if (bytes_read != sizeof(Elf64_Ehdr))
        print_error("Invalid ELF header");

    /* Check ELF magic */
    if (elf_header.e_ident[0] != 0x7f || elf_header.e_ident[1] != 'E' ||
        elf_header.e_ident[2] != 'L' || elf_header.e_ident[3] != 'F')
        print_error("Not an ELF file");

    printf("Magic:   %c%c%c\n", elf_header.e_ident[1], elf_header.e_ident[2], elf_header.e_ident[3]);
    printf("Class:   %d-bit\n", elf_header.e_ident[4] == 1 ? 32 : 64);
    printf("Data:    %s\n", elf_header.e_ident[5] == 1 ? "Little endian" : "Big endian");
    printf("Version: %d\n", elf_header.e_ident[6]);
    printf("OS/ABI:  %d\n", elf_header.e_ident[7]);
    printf("ABI Version: %d\n", elf_header.e_ident[8]);
    printf("Type:    %d\n", elf_header.e_type);
    printf("Entry point address: 0x%lx\n", elf_header.e_entry);

    close(fd);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <elf_filename>\n", argv[0]);
        return 1;
    }

    print_elf_header(argv[1]);

    return 0;
}
