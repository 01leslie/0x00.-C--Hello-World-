#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include "main.h"

int append_text_to_file(const char *filename, char *text_content)
{
    if (filename == NULL) {
        return -1;
    }

    int fd = open(filename, O_WRONLY | O_APPEND | O_CREAT, 0664);
    if (fd == -1) {
        return -1;
    }

    int bytes_written = 0;
    if (text_content != NULL) {
        size_t text_len = strlen(text_content);
        bytes_written = write(fd, text_content, text_len);
        if (bytes_written < 0) {
            close(fd);
            return -1;
        }
    }

    close(fd);
    return bytes_written;
}
