#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include "main.h"

int create_file(const char *filename, char *text_content)
{
    if (!filename) return -1;

    int fd = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0600);
    if (fd == -1) return -1;

    if (text_content) {
        ssize_t len = 0;
        while (*(text_content + len) != '\0') len++;

        ssize_t res_write = write(fd, text_content, len);
        if (res_write == -1) {
            close(fd);
            return -1;
        }
    }

    close(fd);
    return 1;
}
