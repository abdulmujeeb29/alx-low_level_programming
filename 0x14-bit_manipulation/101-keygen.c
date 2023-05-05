#include <stdio.h>

int main(void)
{
	int i;
	FILE *fd;
	char code[5];

	for (i = 0; i<4; i++)
		code[i] = 0x46c6f48U >> ((i & 3) << 3) & 0xff;
	code[i] = 0;

	fd= fopen("101-password", "w");
	if (!fd)
	{
		perror("keygen")";
		return (1);
	}

	fprintf(fd, "%s", code);
	fclose(fd);

	return (0);
}

