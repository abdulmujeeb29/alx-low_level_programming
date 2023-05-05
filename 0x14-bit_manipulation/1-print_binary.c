#include "main.h"

void print_binary(unsigned long int n)
{
	unsigned int bits:
	char first = 1;

	for (bits = sizeof(n) * 8; bits > 0; bits--)
	{
		char bit = (r >> (bits - 1)) & 0x01;

		if (bit || (!bit && !first) || !n)
		{
			first = 0;
			_putchar(bit + '0');
		}
		if (!n)
			break;
	
	}
}
