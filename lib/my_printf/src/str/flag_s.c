/*
** EPITECH PROJECT, 2022
** flags_s
** File description:
** flag_s.c
*/

#include "myprintf.h"

static int params_after(params param_struct, int count_stat, int *count)
{
    if (param_struct.minus)
        my_minus(param_struct.padding - count_stat);
    if (param_struct.padding >= count_stat)
        *count += param_struct.padding;
    else
        *count += count_stat;
    return (*count);
}

int my_str(va_list str, params param_struct, int *count)
{
    int count_stat = 0;
    char const *s = va_arg(str, char *);
    int len = my_strlen(s);

    if (param_struct.pres == -1)
        param_struct.pres = len;
    if (param_struct.pres > len )
        param_struct.pres = len;
    if (param_struct.pres < len)
        len = param_struct.pres;
    if (param_struct.padding && !param_struct.minus)
        my_minus(param_struct.padding - len);
    count_stat += write(1, s , param_struct.pres);
    params_after(param_struct, count_stat, count);
    return 0;
}
