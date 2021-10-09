#include "printf.h"



unsigned int _memcpy();
void free_buffer(buffer_t *output);
buffer_t *init_buffer(void);


/**
 *_memcpy - copies n bytes from memory area src to
 *	the buffer contained in a buffer_t struct
 *@output: A buffer_t struct
 *@src: A pointer to the memory area to copy
 *@n: the number of bytes to be copied
 *
 *return: The number of bytes copied
 */

unsigned int _memcpy(buffer_t *output, const char *src, unsigned int n)
{
	unsigned int index;

	for (index = 0; index < n; index++)
	{
		*(output->buffer) = *(src + index);
		(output->len)++;

		if (output->len == 1024)
		{
			write(1, output->start, output->len);
			output->buffer = output->start;
			output->len = 0;
		}
		else
			(output->buffer)++;
		
		return (n);
	}


}
