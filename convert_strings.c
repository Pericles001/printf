#include "printf.h"

unsigned int convert_s(va_list args, buffer_t *output,
        unsigned char flags, int wid, int prec, unsigned char len);
unsigned int convert_S(va_list args, buffer_t *output,
        unsigned char flags, int wid, int prec, unsigned char len);
unsigned int convert_r(va_list args, buffer_t *output,
        unsigned char flags, int wid, int prec, unsigned char len);
unsigned int convert_R(va_list args, buffer_t *output,
        unsigned char flags, int wid, int prec, unsigned char len);

