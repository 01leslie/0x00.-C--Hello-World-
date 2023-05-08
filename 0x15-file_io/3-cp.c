#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "main.h"

void _error(int e, char *filename);

int cp(char *file_from, char *file_to)
{
    int fd_from = open(file_from, O_RDONLY);
    if (fd_from == -1) {
        _error(98, file_from);
    }

    int fd_to = open(file_to, O_WRONLY | O_CREAT | O_TRUNC, 0664);
    if (fd_to == -1) {
        close(fd_from);
        _error(99, file_to);
    }

    char buf[1024];
    ssize_t bytes_read, bytes_written;

    while ((bytes_read = read(fd_from, buf, sizeof(buf))) > 0) {
        bytes_written = write(fd_to, buf, bytes_read);
        if (bytes_written < bytes_read) {
            close(fd_from);
            close(fd_to);
            _error(99, file_to);
        }
    }

    if (bytes_read < 0) {
        close(fd_from);
        close(fd_to);
        _error(98, file_from);
    }

    if (close(fd_from) < 0 || close(fd_to) < 0) {
        _error(100, NULL);
    }

    return 1;
}

int main(int argc, char *argv[])
{
    if (argc != 3) {
        fprintf(stderr, "Usage: %s file_from file_to\n", argv[0]);
        return 97;
    }

    if (cp(argv[1], argv[2]) == -1) {
        return 1;
    }

    return 0;
}

void _error(int e, char *filename)
{
    switch (e) {
    case 98:
        fprintf(stderr, "Error: Can't read from file %s\n", filename);
        exit(98);
    case 99:
        fprintf(stderr, "Error: Can't write to %s\n", filename);
        exit(99);
    case 100:
        fprintf(stderr, "Error: Can't close file descriptor\n");
        exit(100);
    }
}
