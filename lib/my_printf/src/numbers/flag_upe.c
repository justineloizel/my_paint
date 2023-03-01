/*
** EPITECH PROJECT, 2022
** flag_upe.c
** File description:
** flag_upe.c
*/

#include "myprintf.h"

static void params_print_before(params param_struct, int *count, int char_print,
int is_neg)
{
    if (param_struct.pres)
        *count += 1;
    if (param_struct.padding && !param_struct.minus && !param_struct.zero)
        for (int i = 1; i < param_struct.padding - char_print + is_neg; i++)
            *count += write(1, " ", 1);
    if (is_neg == -1)
        *count += write(1, "-", 1);
    if (param_struct.plus && !is_neg) {
        *count += write(1, "+", 1);
        is_neg = -1;
    }
    if (param_struct.space && !is_neg) {
        *count += write(1, " ", 1);
        is_neg = -1;
    }
    if (param_struct.zero)
        for (int i = 1; i < param_struct.padding - char_print + is_neg; i++)
            *count += write(1, "0", 1);
}

static void params_print_after(params param_struct, int *count, int char_print)
{
    if (param_struct.minus)
        for (int i = 1; i < param_struct.padding - char_print; i++)
            *count += write(1, " ", 1);
}

int my_upe_flag(va_list nb, params param_struct, int *count)
{
    int is_neg = 0;
    int char_print = 5;
    double n = va_arg(nb, double);
    if (n < 0.000000009 && n > -0.000000009) {
        if ( n < 0.0)
            *count += write(1, "-", 1);
        *count += write(1, "0.000000E+00", 12);
        return 0;
    }
    if (n < 0) {
        is_neg = -1;
        n *= -1;
    }
    if (param_struct.pres == -1)
        param_struct.pres = 6;
    char_print += param_struct.pres;
    params_print_before(param_struct, count, char_print, is_neg);
    *count += my_scinbr(n, 1, param_struct.pres, param_struct.hashtag);
    params_print_after(param_struct, count, char_print);
    return 0;
}
