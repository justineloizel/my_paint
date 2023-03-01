/*
** EPITECH PROJECT, 2022
** flag_c.c
** File description:
** flag_c.c
*/

#include "myprintf.h"

int my_char(va_list c, params param_struct, int *count)
{
    char charac = va_arg(c, int);

    if (param_struct.padding && !param_struct.minus)
        *count += my_minus(param_struct.padding - 1);
    *count += write (1, &charac , 1);
    if (param_struct.minus)
        *count += my_minus(param_struct.padding - 1);
    return 0;
}
