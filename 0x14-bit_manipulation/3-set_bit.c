#include "main.h"

/**
 * set_bit - Sets the value of a bit at a given index to 1.
 * @n: Apointer to the bit.
 * @index: The index to set the value at - indices start at 0.
 *
 * Return: If an error occursn - -1.
 *         otherwise - 1.
 */

int set_bit(unsigned long int *n, unsigned int index)
{
	if (!n || index >= sizeof(*n) *8)
		return (-1);
	*n |= 1UL << index;
	return (1);
}

