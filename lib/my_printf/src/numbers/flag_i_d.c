/*
** EPITECH PROJECT, 2022
** flag_i_d.c
** File description:
** flag_i_d.c
*/

#include "myprintf.h"

int count_nb(int n, int count_stat)
{
    if (n <= 0)
        count_stat += 1;
    for (; n != 0; count_stat += 1)
        n = n / 10;
    return (count_stat);
}

static int check_padd_pres(params param_struct, int count_stat)
{
    if (param_struct.padding && param_struct.pres == -1) {
        count_stat += my_minus(param_struct.padding - count_stat);
    }
    if (param_struct.padding && param_struct.pres != -1 && !param_struct.minus)
        count_stat += my_minus(param_struct.padding - count_stat);
    return (count_stat);
}

static int params_before(int n, params param_struct, int count_stat)
{
    int len = count_nb(n, 0);

    count_stat += len;
    if (param_struct.plus && n > 0)
        count_stat += 1;
    if (n < 0 && param_struct.pres != -1)
        count_stat += 1;
    if (param_struct.pres != -1)
        param_struct.zero = 0;
    if (param_struct.pres < count_nb(n, 0))
        param_struct.pres = count_nb(n, 0);
    if (param_struct.pres != -1)
        count_stat += param_struct.pres - len;
    if (param_struct.space)
        count_stat += my_putchar(' ');
    if (param_struct.zero) {
        count_stat += my_zero(param_struct.padding - count_stat);
    }
    count_stat = check_padd_pres(param_struct, count_stat);
    return (count_stat);
}

static int params_after(params param_struct, int count_stat, int *count)
{
    if (param_struct.minus) {
        count_stat += my_minus(param_struct.padding - count_stat);
    }
    if (param_struct.minus >= count_stat)
        *count += param_struct.padding;
    else
        *count += count_stat;
    return *count;
}

int my_nbr(va_list nb, params param_struct, int *count)
{
    int count_stat = 0;
    int n = va_arg(nb, int);

    if (param_struct.zero && param_struct.pres == -1) {
        param_struct.pres = param_struct.padding;
        param_struct.pres = param_struct.pres - 1;
    }
    count_stat += params_before(n, param_struct, count_stat);
    my_put_nbr_pres(n, param_struct.pres, param_struct.plus);
    params_after(param_struct, count_stat, count);
    return 0;
}
