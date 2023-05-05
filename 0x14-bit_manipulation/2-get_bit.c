#include <stdio.h>
#include "main.h"

/**
 * 2-get_bit.c - returns teh value of a bit at a given index
 * index: is the index
 *
 * returns: the value of a bit at index (index) or -1 if an error occured
 *
 **/

int get_bit(unsigned long int n, unsigned int index) {
    if (index >= sizeof(unsigned long int) * 8) {
        return -1;
    }

    unsigned long int mask = 1UL << index;
    return (n & mask) ? 1 : 0;
}

