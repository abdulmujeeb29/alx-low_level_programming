#include <stdio.h>

int get_endianness(void){
	int x = 1;

	return *(char *)&x;
}

