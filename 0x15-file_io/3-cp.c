i#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#define BUF_SIZE 1024

void print_error(const char *message, const char *filename, int code)
{
	dprintf(STDERR_FILENO, message, filename);
	dprintf(STDERR_FILENO, "\n");
	exit(code);
}

void copy_file(const char *file_from, const char *file_to)
{
	int fd_from, fd_to;
	ssize_t read_count, write_count;
	char buffer[BUF_SIZE];

	fd_from = open(file_from, O_RDONLY);
	if (fd_from == -1)
		print_error("Error: Can't read from file %s", file_from, 98);

	fd_to = open(file_to, O_WRONLY | O_CREAT | O_TRUNC, 0664);
	if (fd_to == -1)
		print_error("Error: Can't write to %s", file_to, 99);

	while ((read_count = read(fd_from, buffer, BUF_SIZE)) > 0)
	{
		write_count = write(fd_to, buffer, read_count);
		if (write_count == -1)
			print_error("Error: Can't write to %s", file_to, 99);
	}

	if (read_count == -1)
		print_error("Error: Can't read from file %s", file_from, 98);

	if (close(fd_from) == -1)
		print_error("Error: Can't close fd %s", file_from, 100);

	if (close(fd_to) == -1)
		print_error("Error: Can't close fd %s", file_to, 100);
}

int main(int argc, char **argv)
{
	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: %s file_from file_to\n", argv[0]);
		return (97);
	}

	copy_file(argv[1], argv[2]);

	return (0);
}

