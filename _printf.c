#include "printf.h"


void cleanup(va_list args, buffer_t *output);
int run_printf(const char *format, va_list args, buffer_t *output);
int _printf(const char *format, ...);

/**
 * cleanup - Performs cleanup for _printf
 * @args: a va_list of arguments to _printf
 *@output: A buffer_t struct
 */

void cleanup(va_list args, buffer_t *output)
{
	va_end(args);
	write(1, output->start, output->len);
	free_buffer(output);
}




















/**
*_printf -  a function that produces output according to a format.
*@format:is a character string. The format string is composed of 
*zero or more directives. 
*Return: the number of characters printed
* (excluding the null byte used to end output to strings)
*/

int _printf(char *format, ...)
{
	buffer_t *output;
	va_list args;
	int ret;

	if (format == NULL)
		return (-1);
	output = init_buffer();
	if (output == NULL)
		return (-1);

	va_start(args, format);

	ret = run_printf(format, args, output);

	return (ret);
}
