/*
** EPITECH PROJECT, 2022
** my_printf.c
** File description:
** it's our copy of printf(much much better)
*/

#include <stdarg.h>
#include <stdio.h>
#include "myprintf.h"
params check_if_params(const char *format);

static const detect_flag detect_list[] = {
    {'c', my_char},
    {'s', my_str},
    {'i', my_nbr},
    {'d', my_nbr},
    {'%', my_modulo},
    {'u', my_unsigned},
    {'o', my_octal},
    {'x', my_hexa},
    {'X', my_hexa_capital},
    {'f', my_float},
    {'F', my_float},
    {'b', my_binary},
    {'S', my_str_non_print},
    {'n', my_n_flag},
    {'p', my_p_flag},
    {'e', my_e_flag},
    {'E', my_upe_flag},
    {'t', my_tab},
    {'z', my_error_flag},
};

int is_flag(char c)
{
    char tab[] = {'i', 'p', 'n', 'b', '%', 'd', 'S', 's',
        'c', 'u', 'o', 'x', 'X', 'f', 'F', 'e', 'E','t', 'z', 0};

    for (int i = 0; tab[i]; i++) {
        if (c == tab[i])
            return 1;
    }
    return 0;
}

int which_flags(va_list args, char c, params param_struct, char *flag)
{
    int count = 0;

    if (param_struct.error == 84) {
        count = my_put_error(param_struct, flag);
        return (count);
    }
    for (int i = 0; i < (int)ARRAY_LENGTH(detect_list); i++) {
        if (detect_list[i].c == 'n' && c == 'n') {
            detect_list[i].fct(&count, args);
            return 0;
        }
        if (detect_list[i].c == c)
            detect_list[i].fct(args, param_struct, &count);
    }
    return count;
}

char *what_params(char *format, int *i)
{
    int save = *i + 1;
    char *parameter;

    for (; format[*i + 1] != '\0' && !is_flag(format[*i + 1]); *i += 1);
    parameter = cut_string(&format[save], &format[*i], format[*i + 1]);
    return parameter;
}

int my_printf(const char *format, ...)
{
    int count = 0;
    va_list args;
    char *flag = NULL;
    params param;

    va_start(args, format);
    for (int i = 0; i < my_strlen(format); i++) {
        if (format[i] == '%') {
            flag = what_params((char *)format, &i);
            param = check_if_params(flag);
            param = check_orders_params(flag, param);
            count += which_flags(args, format[i + 1], param, flag);
            i += 1;
            continue;
        }
        count += 1;
        write(1, &format[i], 1);
    }
    va_end(args);
    return count;
}
