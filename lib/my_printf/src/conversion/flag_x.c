/*
** EPITECH PROJECT, 2022
** flag_x_upx.c
** File description:
** flag_x_upx.c
*/

#include "myprintf.h"

static int count_nb_u(int n, int count_stat)
{
    if (n <= 0)
        count_stat += 1;
    for (; n != 0; count_stat += 1)
        n = n / 16;
    return (count_stat);
}

static int check_padd_pres(params p, int count_stat)
{
    if (p.zero)
        count_stat += my_zero(p.padding - count_stat);
    if (p.padding && p.pres == -1 && !p.minus) {
        count_stat += my_minus(p.padding - count_stat - p.hashtag);
    }
    if (p.padding && p.pres != -1 && !p.minus && p.padding > p.pres) {
        count_stat += my_minus(p.padding - count_stat);
        count_stat += my_zero(p.pres - count_stat);
    }
    if (p.padding && p.pres != -1 && !p.minus) {
        count_stat += my_minus(p.padding - count_stat - p.pres);
        count_stat += my_zero(p.pres - count_stat);
    }
    if (p.hashtag && p.padding && p.pres != -1)
        count_stat += write(1, "0x", 2);
    return (count_stat);
}

static int params_before(int n, params p, int count_stat)
{
    int len = count_nb_u(n, 0);

    count_stat += len;
    if (p.hashtag)
        p.hashtag = 2;
    if (p.hashtag && p.pres != -1 && !p.padding)
        count_stat += write(1, "0x", 2);
    if (p.hashtag && (p.zero || p.padding))
        count_stat += write (1, "0x", 2);
    if (n < 0 && p.pres != -1)
        count_stat += 1;
    if (p.pres != -1) {
        p.zero = 0;
        p.minus = 0;
    }
    if (p.pres != -1)
        count_stat += my_zero(p.pres - len);
    count_stat = check_padd_pres(p, count_stat);
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
    return (*count);
}

int my_hexa(va_list nb, params param_struct, int *count)
{
    int count_stat = 0;
    unsigned int n = va_arg(nb, unsigned int);

    count_stat += params_before(n, param_struct, count_stat);
    my_put_unsigned_base(n, "0123456789abcdef");
    params_after(param_struct, count_stat, count);
    return 0;
}
