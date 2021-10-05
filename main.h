#ifndef MAIN_H
#define MAIN_H

#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>
#include <limits.h>


/*Flag modifier Macros*/
#define PLUS 1
#define SPACE 2
#define HASH 4
#define ZERO 8
#define NEG 16
#define PLUS_FLAG (flags & 1)
#define SPACE_FLAG ((flags >> 1) & 1)
#define HASH_FLAG ((flags >> 2) & 1)
#define ZERO_FLAG ((flags >> 3) & 1)
#define NEG_FLAG ((flags >> 4) & 1)


/* Length Modifier Macros*/
#define SHORT 1
#define LONG 2

/**
*struct buffer_s - A new type defining a buffer struct
*@buffer: A pointer to a character array
*@start: A pointer to the start of buffer
*@len:Length of the string stored in buffer
*/
typedef struct buffer_s
{
char *buffer;
char *start;
unsigned int len;
} buffer_t;

/**
*struct converter_s - A converter struct defined by a new type
*@specifier: A character representing a conversion specifier
*@func: A pointer to a conversion function corresponding to specifier
*/
typedef struct converter_s
{
unsigned char specifier;
unsigned int (*func)(va_list, buffer_t *,
 unsigned char, int, int, unsigned char);
} converter_t;

/**
*struct flag_s - A new type defining a flags struct
*@flag: A character representing a flag
*@value:The integer value of flag
*/
typedef struct flag_s
{
unsigned char flag;
unsigned char value;
} flag_t;

int _printf(const char *format, ...);

/*conversion specifier functions*/
unsigned int convert_c(va_list args, buffer_t *output,
	unsigned char flags, int wid, int prec, unsigned char len);
unsigned int convert_s(va_list args, buffer_t *output,
	unsigned char flags, int wid, int prec, unsigned char len);
unsigned int converter_di(va_list args, buffer_t *output,
	unsigned char flags, int wid, int prec, unsigned char len);
unsigned int convert_percent(va_list args, buffer_t *output,
	unsigned char flags, int wid, int prec, unsigned char len);

/*Handlers*/

/*Modifiers*/
unsigned int print_width(buffer_t *output, unsigned int printed,
	unsigned char flags, int wid);
unsigned int print_string_width(buffer_t *output,
	unsigned char flags, int wid, int prec, int size);
unsigned int print_neg_width(buffer_t *output, unsigned int printed,
	unsigned char flags, int wid);




/*Helper functions*/
buffer_t *init_buffer(void);
void free_buffer(buffer_t *output);
unsigned int _memcpy(buffer_t *output, const char *src, unsigned int n);
unsigned int convert_sbase(buffer_t *output, long int num, char *base,
	unsigned char flags, int wid, int prec);
unsigned convert_ubase(buffer_t *output, unsigned long int num, char *base,
	unsigned char flags, int wid, int prec);


#endif /* MAIN_H */