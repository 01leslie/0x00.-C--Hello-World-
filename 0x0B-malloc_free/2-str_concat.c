#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "main.h"

char *str_concat(char *s1, char *s2)
{
if (s1 == NULL)
{
s1 = "";
}
if (s2 == NULL)
{
s2 = "";
}

/** Allocate memory to store the concatenated string**/
size_t len_s1 = strlen(s1);
size_t len_s2 = strlen(s2);
char *result = (char *) malloc((len_s1 + len_s2 + 1) * sizeof(char));
if (result == NULL)
{
return NULL; // Return NULL on failure to allocate memory
}

/** Copy the contents of s1 and s2 to the result string**/
strcpy(result, s1);
strcat(result, s2);
return result;
}

