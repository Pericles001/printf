#include "printf.h"


unsigned char handle_flags(const char *flag, char *index);
unsigned char handle_length(const char *modifier, char *index);
int handle_width(va_list args, const char *modifier, char *index);
int handle_precision(va_list args, const char *modifier, char *index);
unsigned int (*handle_specifiers(const char *specifier))(va_list, buffer_t *,
		unsigned char, int, int, unsigned char);

/**
* handle_flags - Matches flags with corresponding values.
* @flag: A pointer to a potential string of flags.
* @index: An index counter for the original format string.
*
* Return: If flag characters are matched - a corresponding value.
*         Otherwise - 0.
*/
