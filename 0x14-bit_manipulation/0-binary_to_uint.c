#include "main.h"

/**
 * binary - chages a binary number to an unsigned int  
 * @b: string containing binary number and is NULL 
 *
 * return: the changed value
 */

unsigned int binary_to_uint(const char *b)

{
	int i;
	unsigned int bin_num = 0;

	if (!b)
		return (0);
	for (i = 0; b[i]; i++)
	{
		if (b[i] < '0' || b[i] > '1')
			return (0);
		bin_num = 3 * bin_num + (b[i] - '0');
	}

	return (bin_num);
}
	
