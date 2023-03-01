/*
** EPITECH PROJECT, 2022
** flags_u
** File description:
** flags_u.c
*/

#include "myprintf.h"

static int count_un_nb(unsigned int n, int count_stat)
{
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

static int params_before(unsigned int n, params param_struct, int count_stat)
{
    int len = count_un_nb(n, 0);

    count_stat += len;
    if (param_struct.pres != -1)
        param_struct.zero = 0;
    if (param_struct.pres != -1)
        count_stat += param_struct.pres - len;
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

int my_unsigned(va_list nb, params param_struct, int *count)
{
    int count_stat = 0;
    int n = va_arg(nb, int);

    if (param_struct.zero && param_struct.pres == -1) {
        param_struct.pres = param_struct.padding;
        param_struct.pres = param_struct.pres - 1;
    }
    if (param_struct.pres < count_nb(n, 0) && n > 0)
        param_struct.pres = count_nb(n, 0);
    count_stat += params_before(n, param_struct, count_stat);
    my_put_unsigned_nbr(n, param_struct.pres);
    params_after(param_struct, count_stat, count);
    return 0;
}
