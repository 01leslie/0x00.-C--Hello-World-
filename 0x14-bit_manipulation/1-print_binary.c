#include <stdio.h>
#include "main.h"

/**
 * 1-print_binary.c - prints the binary representation of a number
 *
 **/

void print_binary(unsigned long int n) {
    int bit_pos = sizeof(n) * 8 - 1; // position of the leftmost bit
    while ((n >> bit_pos) == 0 && bit_pos > 0) {
        bit_pos--; // skip leading zeros
    }
    while (bit_pos >= 0) {
        int bit = (n >> bit_pos) & 1; // get the current bit
        printf("%d", bit);
        bit_pos--; // move to the next bit
    }
    printf("\n");
}




