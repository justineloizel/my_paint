/*
** EPITECH PROJECT, 2022
** flag_p.c
** File description:
** flag_p.c
*/

#include "myprintf.h"

static int my_put_nb_size_t_base(size_t nbr, char *base)
{
    char *str;
    int j = 0;
    size_t nb = nbr;
    size_t div = my_strlen(base);

    for (; nbr != 0; j++)
        nbr = nbr / div;
    str = malloc(sizeof(char) * (j + 1));
    nbr = nb;
    for (int i = 0; nbr != 0; i++) {
        str[i] = base[nbr % div];
        nbr = nbr / div;
    }
    str[j] = '\0';
    my_revstr(str);
    return (write(1, str, my_strlen(str)));
}

static int params_before(size_t n, params param_struct, int count_stat)
{
    if (param_struct.space && param_struct.plus && n != 0) {
        count_stat += my_plus(n);
        return count_stat;
    }
    if (param_struct.space && n != 0)
        count_stat += my_putchar(' ');
    if (param_struct.plus && n != 0)
        count_stat += my_plus(n);
    return (count_stat);
}

static int params_after(params param_struct, int count_stat,
int *count)
{
    my_minus(param_struct.minus - count_stat);
    if (param_struct.minus >= count_stat)
        *count += param_struct.minus;
    else
        *count += count_stat;
    return (*count);
}

int my_p_flag(va_list nb, params param_struct, int *count)
{
    size_t n = (size_t)va_arg(nb, void *);
    int count_stat = 0;

    if (n == 0)
        count_stat += my_putstr("(nil)");
    count_stat += params_before(n, param_struct, count_stat);
    if (n != 0) {
        my_putstr("0x");
        count_stat += (my_put_nb_size_t_base(n, "0123456789abcdef") + 2);
    }
    params_after(param_struct, count_stat, count);
    return 0;
}
