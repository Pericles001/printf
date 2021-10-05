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



#endif /* MAIN_H */