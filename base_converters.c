/*
 * File: base_converters.c
 * Auth: Arsene Awounou
 */

#include "printf.h"

unsigned int convert_sbase(buffer_t *output, long int num, char *base,
        unsigned char flags, int wid, int prec);

unsigned int convert_ubase(buffer_t *output,
        unsigned long int num, char *base,
        unsigned char flags, int wid, int prec);

/**
 * convert_sbase - Converts a signed long to an inputted base and stores
 *                 the result to a buffer contained in a struct.
 * @output: A buffer_t struct containing a character array.
 * @num: A signed long to be converted.
 * @base: A pointer to a string containing the base to convert to.
 * @flags: Flag modifiers.
 * @wid: A width modifier.
 * @prec: A precision modifier.
 *
 * Return: The number of bytes stored to the buffer.
 */