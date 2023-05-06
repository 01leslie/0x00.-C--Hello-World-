#include <stdio.h>
#include "main.h"

/**
 * 1-print_binary.c - prints the binary representation of a number
 *
 **/

void print_binary(unsigned long int n) {
    unsigned long int i = 1UL << (sizeof(unsigned long int) * 8 - 1);
    while (i > 0) {
        putchar((n & i) ? '1' : '0');
        i >>= 1;
    }
}


