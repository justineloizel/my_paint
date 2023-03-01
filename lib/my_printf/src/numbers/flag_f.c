/*
** EPITECH PROJECT, 2022
** flag_f.c
** File description:
** flag_f.c
*/

#include "myprintf.h"


static void params_print_before(params param_struct, int *count, int char_print,
int is_neg)
{
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

static void params_print_after(params param_struct, int *count, int char_print,
int is_neg)
{
    if (!is_neg)
        is_neg = -1;
    if (param_struct.hashtag && !param_struct.pres)
        *count += write(1, ".", 1);
    if (param_struct.minus)
        for (int i = 1; i < param_struct.padding - char_print + is_neg; i++)
            *count += write(1, " ", 1);
}

int my_float(va_list nb, params param_struct, int *count)
{
    double n = va_arg(nb, double);
    int char_print = 0;
    int is_neg = 0;
    if (n < 0) {
        is_neg = -1;
        n *= -1;
    }
    if (param_struct.pres == 0)
        char_print += 1;
    if (param_struct.pres == -1)
        param_struct.pres = 6;
    if (param_struct.pres)
        *count += 1;
    char_print = param_struct.pres + count_nb(n, 0);
    params_print_before(param_struct, count, char_print, is_neg);
    *count += (my_putfloat(n, param_struct.pres) + count_nb(n, 0));
    params_print_after(param_struct, count, char_print, is_neg);
    return 0;
}
