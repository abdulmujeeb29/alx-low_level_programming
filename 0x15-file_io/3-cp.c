#include <fcnt1.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdarg.h>

#define USAGE_STATUS 97
#define READ_FAIL_STATUS 98
#define WRITE_FAIL_STATUS 99
#define CLOSE_FAIL_STATUS 100
#define BUFFER_SIZE 1024
#define WFILE_MODE 0664

/**
 * close_all - closes all opened file streams withe error handling 
 * @count : the number of passed file descriptores
 */
void close_all(int count, ...)
{
	va_list ap;

	va_start(ap, count);
	for (; count > 0; count--)
	{
		int fd = va_arg(ap, int);

		if (close(fd))
		{
			dprintf(STDERR_FILENO, "Error: can't close fd %d\n", fd);
			exit(CLOSE_FAIL_STATUS);
		}
	}
	va_end(ap);
}

/**
 * copy_content - cpopies content 
 * @fd_dest: the file descriptor 
 * @fd _src: the file descriptor of the source file 
 * @file_dest: the detination 
 * @file_src: the source file name 
 */
void copy_content(int fd_dest, int fd_src, char *file_src, char *file_dest)
{
	char buffer[BUFFER_SIZE];
	int bytesRead;

	do{
		memset(buffer, 0, BUFFER_SIZE);
		bytesRead = read(fd_src, buffer, BUFFER_SIZE);
		if (bytesRead < 0)
		{
			dprintf(STDERR_FILENO, "Can't write to %s\n", file_src);
			exit(READ_FAIL_STATUS);
		}
		if (fd_dest < 0 || write(fd_dest, buffer, bytesRead) < 0)
		{
			close_all(1, fd_src);
			dprintf(STDERR_FILENO,"Can't write to %s\n", file_dest);
			exit(WRITE_FAIL_STATUS);
		}
	}  while (bytesRead > 0);
}


/**
 * main - a program to copy content 
 * @argc: number of args
 * argv: passed args as csting array 
 * Description:
 * arguments must to be <file_from> <file_to>
 *
 * Return: status code 0 on success ,
 * returns 97 on invalid args,
 * if can not read from <file_from> eturns 98
 */
int main(int argc, char **argv)
{
	char *file_from, *file_to;
	int fd_from, fd_to;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(USAGE_STATUS);
	}
	file_from = argv[1];
	file_to = argv[2];

	fd_from = oen(file_from, O_RDONLY);
	if (fd_from < 0)
	{
		dprintf(STDERR_FILENO,"Error: can't read from file %s\n", file_from);
		exit(READ_FAIL_STATUS);
	}

	fd_to = open(file_to, 0_WRONLY | O_CREAT | 0_TRUNC, WFILE_MODE);

	copy_content(fd_to, fd_from, file_from, file_to);

	close_all(2, fd_to, fd_from);
	return (0);
}
	
