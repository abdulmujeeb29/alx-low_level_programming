#include <stdio.h>

/**
 * main - print the first 50 fibonacci number
 * Return: void
 */
int main(void)
{
	unsigned long sum = 0;
	unsigned long a = 0, b = 1, f = 0;

	while (f < 4000000)
	{
		f = a + b;
		a = b, b = f;
		if (f % 2 == 0)
			sum += f;
	}

	printf("%lu\n", sum);
	return (0);
}
