#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include "main.h"

ssize_t read_textfile(const char *filename, size_t letters)
{
    if (!filename) return 0;

    int fd = open(filename, O_RDONLY);
    if (fd == -1) return 0;

    char *buf = malloc(letters);
    if (!buf) {
        close(fd);
        return 0;
    }

    ssize_t res_read = read(fd, buf, letters);
    if (res_read == -1) {
        free(buf);
        close(fd);
        return 0;
    }

    ssize_t res_write = write(STDOUT_FILENO, buf, res_read);
    if (res_write == -1 || res_write != res_read) {
        free(buf);
        close(fd);
        return 0;
    }

    free(buf);
    close(fd);

    return res_write;
}

