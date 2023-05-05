#include "main.h"
#include <string.h>

/**
 * binary_to_uint - convert binary nuber to unsigned int 
 * @b: the binary number as acstring
 * Description:
 * NOTE: the limit of @b length is the maximum positive signed int
 *
 * Return: the decimal form of the converted number otherwise 
 */
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

