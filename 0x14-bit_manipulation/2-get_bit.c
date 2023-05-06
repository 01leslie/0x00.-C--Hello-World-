#include <stdio.h>
#include "main.h"

/**
 * 2-get_bit.c - returns teh value of a bit at a given index
 * index: is the index
 * @n: input long integer
 * returns: the value of a bit at index (index) or -1 if an error occured
 *
 **/
int get_bit(unsigned long int n, unsigned int index)
{
	return ((index > (8 * sizeof(n) - 1)) ? -1 : (int)(n >> index) & 1);
}

