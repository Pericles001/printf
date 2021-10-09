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
unsigned int convert_sbase(buffer_t *output, long int num, char *base,
        unsigned char flags, int wid, int prec)
{
    int size;
    char digit, pad = '0';
    unsigned int ret = 1;

    for (size = 0; *(base + size);)
        size++;

    if (num >= size || num <= -size)
        ret += convert_sbase(output, num / size, base,
                flags, wid - 1, prec - 1);

    else
    {
        /* Handle precision */
        for (; prec > 1; prec--, wid--)
            ret += _memcpy(output, &pad, 1);

        /* Handle width */
        if (NEG_FLAG == 0)
        {
            pad = (ZERO_FLAG == 1) ? '0' : ' ';
            for (; wid > 1; wid--)
                ret += _memcpy(output, &pad, 1);
        }
    }

    digit = base[(num < 0 ? -1 : 1) * (num % size)];
    _memcpy(output, &digit, 1);

    return (ret);
}