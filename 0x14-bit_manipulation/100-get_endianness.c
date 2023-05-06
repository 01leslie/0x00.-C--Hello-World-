#include <stdio.h>
#include "main.h"

/**
 * 100-get_endianness.c - checks the endianness.
 *
 * Returns: 0 if big endian and 1 if little endian 
 **/
int get_endianness(void)
{
	int i;
	char *test;

	i = 1;
	test = (char *)&i;
	return ((int)test[0]);
}

