#include <stdio.h>
#include "main.h"

/**
 * 1-print_binary.c - prints the binary representation of a number
 *
 **/
void print_binary(unsigned long int n) {
    unsigned long int mask = 1UL << (sizeof(unsigned long int) * 8 - 1);

    while (mask > 0) {
        if ((n & mask) == 0) {
            printf("0");
        } else {
            printf("1");
        }
        mask = mask >> 1;
    }
}

