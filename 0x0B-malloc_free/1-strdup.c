#include <stdlib.h>
#include "main.h>
#include <string.h>

char *_strdup(char *str)
{
if (str == NULL)
{
return NULL;
}
char *dup_str = (char*) malloc(strlen(str) + 1);
if (dup_str == NULL)
{
return NULL;
}
strcpy(dup_str, str);
return dup_str;
}

