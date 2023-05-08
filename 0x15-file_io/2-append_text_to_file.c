#include "main.h"
#include <string.h>
/*
 * append_text_to_file - appends text at the end of a file.
 * @filename: file to append the text to.
 * @text_content: content to append into the file.
 *
 * Return: 1 on success and -1 on failure.
 */

int append_text_to_file(const char *filename, char *text_content) {
    if (filename == NULL) {
        return -1; 
    }

    FILE *file = fopen(filename, "a");
    if (file == NULL) {
        return -1;  
    }

    if (text_content != NULL) {
        size_t text_len = strlen(text_content);
        fwrite(text_content, sizeof(char), text_len, file);  
    }

    fclose(file);  
    return 1; 
}
