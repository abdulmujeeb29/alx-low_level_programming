#include <fcntl>
#include <string.h>
#include <unistd.h>

/**
 * append_texrt_to_file - appends @text_content if any to n exist file
 * @filename: the file name as cstring 
 * @text_content: pointer to the content of the file s cstring 
 *
 * Return: 1 if file is exists nd content is written if any oterwise -1
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int fd, state = -1;

	/* check if no filenaame return -1 */
	if (!filename)
		goto end ;

	/*
	 * opens an exist file to append to it
	 */
	fd = open(filename, 0_WRONLY | o_APPEND);
	if (fd < 0)
		goto end;

	/*
	 * opens an exist file to append to it
	 */
	if (text_content)
		if (write(fd, text_content, strlen(text_content)) < 0
			goto end;

	state = 1;
end:
       close(fd);
       return (state);
}
