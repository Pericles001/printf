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

