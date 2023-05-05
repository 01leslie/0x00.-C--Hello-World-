#include <stdio.h>
#include "main.h"

/** 0-binary_to_uint.c - converts binary to an unsigned int
 *
 * b: is a pointer to a string of characters 0 and 1
 * return: the cmonverted number 
 *
 **/

unsigned int binary_to_uint(const char *b) {
    unsigned int num = 0;
    int i = 0;

    if (b == NULL) {
        return 0;
    }

    while (b[i] != '\0') {
        if (b[i] == '0' || b[i] == '1') {
            num = num << 1;
            num += b[i] - '0';
            i++;
        } else {
            return 0;
        }
    }

    return num;
}


