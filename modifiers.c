#include "printf.h"

unsigned int print_width(buffer_t *output, unsigned int printed,
		unsigned char flags, int wid);
unsigned int print_string_width(buffer_t *output,
		unsigned char flags, int wid, int prec, int size);
unsigned int print_neg_width(buffer_t *output, unsigned int printed,
		unsigned char flags, int wid);


/**
 *print_width - stores leading spaces to a buffer for a width modifier.
 *@output: A buffer_t struct containing a character array.
 *@printed: The current number of characters already printed to output
 *	for a given number specifier
 *@flags: flags modifier
 *@wid: a width modifier
 *
 *Return: The number of bytes stored to the buffer.
 */


unsigned int print_width(buffer_t *output, unsigned int printed,
		unsigned char flags, int wid)
{
	unsigned int ret = 0;
	char width = '';

	if (NEG_FLAG == 0)
	{
		for (wid -= printed; wid > 0;)
			ret += _memcpy(output, &width, 1);
	}

	return (ret);
}

