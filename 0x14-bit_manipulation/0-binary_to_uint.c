#include "main.h"
#include <string.h>

unsigned int binary_to_uint(const char *b)
{
	unsigned int i, num = 0, field;

	if (!b)
		return (num);

	for (i = strlen(b) - 1, field = 1; (signed int)i >=0; field *=2)
		if (b[i] == '1')
			num += field;
	        else if (b[i] == '0')
			continue;
	        else
			return (0);
	return (num);
}

