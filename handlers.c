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

unsigned char handle_flags(const char *flag, char *index)
{
int i, j;
unsigned char ret = 0;
flag_t flags[] = {
{'+', PLUS},
{' ', SPACE},
{'#', HASH},
{'0', ZERO},
{'-', NEG},
{0, 0}
};

for (i = 0; flag[i]; i++)
{
for (j = 0; flags[j].flag != 0; j++)
{
if (flag[i] == flags[j].flag)
{
(*index)++;
if (ret == 0)
ret = flags[j].value;
else
ret |= flags[j].value;
break;
}
}
if (flags[j].value == 0)
break;
}

return (ret);
}


/**
 * handle_length - Matches length modifiers with their corresponding value.
 * @modifier: A pointer to a potential length modifier.
 * @index: An index counter for the original format string.
 *
 * Return: If a lenth modifier is matched - its corresponding value.
 *         Otherwise - 0.
 */

unsigned char handle_length(const char *modifier, char *index)
{
	if (*modifier == 'h')
	{
		(*index)++;
		return (SHORT);
	}

	else if (*modifier == '1')
	{
		(*index)++;
		return (LONG);
	}

	return (0);
}


/**
 * handle_width - Matches a width modifier with its corresponding value.
 * @args: A va_list of arguments.
 * @modifier: A pointer to a potential width modifier.
 * @index: An index counter for the original format string.
 *
 * Return: If a width modifier is matched - its value.
 *         Otherwise - 0.
 */
int handle_width(va_list args, const char *modifier, char *index)
{
int value = 0;

while ((*modifier >= '0' && *modifier <= '9') || (*modifier == '*'))
{
(*index)++;

if (*modifier == '*')
{
value = va_arg(args, int);
if (value <= 0)
return (0);
return (value);
}

value *= 10;
value += (*modifier - '0');
modifier++;
}

return (value);
}
