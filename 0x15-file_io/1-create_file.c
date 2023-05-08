#include "main.h"
#include <string.h>
/*
 * create_file - creates a file and puts text in it.
 * @filename: name of thej file to create.
 * @text_content: text to write in the file 
 *
 * Return: 1 if success and -1 if failed
 */
int create_file(const char *filename, char *text_content) {
    if (filename == NULL) {
        return -1;
    }
    
    int fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
    if (fd == -1) {
        return -1;
    }
    
    if (text_content != NULL) {
        ssize_t bytes_written = write(fd, text_content, strlen(text_content));
        if (bytes_written == -1 || bytes_written != strlen(text_content)) {
            close(fd);
            return -1;
        }
    }
    
    close(fd);
    return 1;
}

