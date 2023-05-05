#include <stdio.h>
#include "main.h"

/**
 * 4-clear_bit.c - sets the value of a bit to 0 at a given index
 *
 * index: is the index
 *
 * returns: 1 if it worked or -1 if an error occured
 **/

int clear_bit(unsigned long int *n, unsigned int index) {
    if (index >= sizeof(unsigned long int) * 8) {
        return -1;
    }

    *n &= ~(1UL << index);
    return 1;
}

