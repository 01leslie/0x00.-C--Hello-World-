#include "main.h"

#define BUF_SIZE 1024

int main(int argc, char *argv[]) {
    if (argc != 3) {
        dprintf(STDERR_FILENO, "Usage: %s file_from file_to\n", argv[0]);
        exit(97);
    }
    char *file_from = argv[1];
    char *file_to = argv[2];

    int fd_from = open(file_from, O_RDONLY);
    if (fd_from == -1) {
        dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", file_from);
        exit(98);
    }

    int fd_to = open(file_to, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd_to == -1) {
        dprintf(STDERR_FILENO, "Error: Can't write to %s\n", file_to);
        exit(99);
    }

    char buf[BUF_SIZE];
    ssize_t num_read;
    while ((num_read = read(fd_from, buf, BUF_SIZE)) > 0) {
        if (write(fd_to, buf, num_read) != num_read) {
            dprintf(STDERR_FILENO, "Error: Can't write to %s\n", file_to);
            exit(99);
        }
    }
    if (num_read == -1) {
        dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", file_from);
        exit(98);
    }

    if (close(fd_from) == -1) {
        dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd_from);
        exit(100);
    }

    if (close(fd_to) == -1) {
        dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd_to);
        exit(100);
    }

    return 0;
}

