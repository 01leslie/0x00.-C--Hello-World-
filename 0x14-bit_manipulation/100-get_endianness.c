#include <stdio.h>
#include "main.h"

/**
 * 100-get_endianness.c - checks the endianness.
 *
 * Returns: 0 if big endian and 1 if little endian 
 **/

int get_endianness(void) {
    unsigned int x = 1;
    char *c = (char*) &x;

    if (*c) {
        return 1;
    } else {
        return 0;
    }
}

