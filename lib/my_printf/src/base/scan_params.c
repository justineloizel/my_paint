/*
** EPITECH PROJECT, 2022
** function to scan params
** File description:
** function to scan params
*/

#include "myprintf.h"

static const scan_params detect_params[] = {
    {'#', 1},
    {'\'', 1},
    {'+', 1},
    {' ', 1},
    {'-', 1},
    {'0', 1},
};

int is_param(char c)
{
    for (int i = 0; i < (int)ARRAY_LENGTH(detect_params); i++)
        if ( c == detect_params[i].c)
            return 1;
    return 0;
}

params get_padd_pres(params param_struct, char const *flag)
{
    param_struct.padding = my_getnbr_bef_point(flag);
    param_struct.pres = my_getnbr_aft_point(flag);
    return param_struct;
}

params check_if_params(const char *flag)
{
    params param_struct = {0, 0, 0, 0, 0, 0, 0, 0, 0};
    int i = 1;

    for (; !is_flag(flag[i]) && is_param(flag[i]) && flag[i]; i++) {
        if (flag[i] == '#')
            param_struct.hashtag = 1;
        if (flag[i] == '0')
            param_struct.zero = 1;
        if (flag[i] == '-')
            param_struct.minus = 1;
        if (flag[i] == ' ')
            param_struct.space = 1;
        if (flag[i] == '+')
            param_struct.plus = 1;
        if (flag[i] == '\'')
            param_struct.apo = 1;
    }
    param_struct = get_padd_pres(param_struct, &flag[i]);
    return param_struct;
}

params check_orders_params(char *flag, params param_struct)
{
    int i = 1;

    for (; flag[i] && is_param(flag[i]) ; i++);
    for (; flag[i]; i++)
        if (is_param(flag[i]) && flag[i] != '0') {
            param_struct.error = 84;
        }
    if (param_struct.plus)
        param_struct.space = 0;
    if (param_struct.minus)
        param_struct.zero = 0;
    return param_struct;
}

int my_put_error(params p, char *flag)
{
    int count = 0;
    int i = 0;
    int list[] = {p.hashtag, p.apo, p.plus, p.space, p.minus, p.zero};

    count += my_putchar('%');
    if (p.plus)
        list[3] = 0;
    if (p.minus)
        list[4] = 0;
    for (; i <= 5; i++)
        if (list[i])
            count += my_putchar(detect_params[i].c);
    for (i = 1; flag[i] && is_param(flag[i]) ; i++);
    count += my_putstr(&flag[i]);
    count += my_putchar(flag[0]);
    return count;
}
