#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <elf.h>
#include "main.h"

#define BUF_SIZE 128

void display_error(char* message) {
    fprintf(stderr, "Error: %s\n", message);
    exit(98);
}

void display_elf_header(const char* filename) {
    int fd;
    Elf64_Ehdr elf_header;
    ssize_t num_bytes_read;

    fd = open(filename, O_RDONLY);
    if (fd == -1) {
        display_error("Failed to open file");
    }

    num_bytes_read = read(fd, &elf_header, sizeof(Elf64_Ehdr));
    if (num_bytes_read != sizeof(Elf64_Ehdr)) {
        display_error("Failed to read ELF header");
    }

    // Verify that the file is an ELF file
    if (memcmp(elf_header.e_ident, ELFMAG, SELFMAG) != 0) {
        display_error("File is not an ELF file");
    }

    printf("Magic: ");
    for (int i = 0; i < EI_NIDENT; i++) {
        printf("%02x ", elf_header.e_ident[i]);
    }
    printf("\n");

    printf("Class: ");
    switch (elf_header.e_ident[EI_CLASS]) {
        case ELFCLASS32:
            printf("ELF32\n");
            break;
        case ELFCLASS64:
            printf("ELF64\n");
            break;
        default:
            printf("Invalid class\n");
            break;
    }

    printf("Data: ");
    switch (elf_header.e_ident[EI_DATA]) {
        case ELFDATA2LSB:
            printf("2's complement, little endian\n");
            break;
        case ELFDATA2MSB:
            printf("2's complement, big endian\n");
            break;
        default:
            printf("Invalid data encoding\n");
            break;
    }

    printf("Version: %d\n", elf_header.e_ident[EI_VERSION]);

    printf("OS/ABI: ");
    switch (elf_header.e_ident[EI_OSABI]) {
        case ELFOSABI_SYSV:
            printf("UNIX System V ABI\n");
            break;
        case ELFOSABI_HPUX:
            printf("HP-UX ABI\n");
            break;
        case ELFOSABI_NETBSD:
            printf("NetBSD ABI\n");
            break;
        case ELFOSABI_LINUX:
            printf("Linux ABI\n");
            break;
        case ELFOSABI_SOLARIS:
            printf("Solaris ABI\n");
            break;
        case ELFOSABI_IRIX:
            printf("IRIX ABI\n");
            break;
        case ELFOSABI_FREEBSD:
            printf("FreeBSD ABI\n");
            break;
        case ELFOSABI_TRU64:
            printf("Tru64 UNIX ABI\n");
            break;
        case ELFOSABI_ARM:
            printf("ARM architecture ABI\n");
            break;
        case ELFOSABI_STANDALONE:
            printf("Standalone (embedded) ABI\n");
            break;
        default:
            printf("Unknown ABI\n");
            break;
    }

    printf("ABI Version: %d\n", elf_header.e_ident[EI_ABIVERSION]);

    printf("Type: ");
    switch (elf_header.e_type) {
        case ET_NONE:
            printf("NONE\n");
            break;
        case ET_REL:
            printf("REL (Relocatable file)\n");
            break;
        case ET_EXEC:
            printf("EXEC (Executable file)\n");
    }
}
