/*
** EPITECH PROJECT, 2022
** flag_ups.c
** File description:
** flag_ups.c
*/

#include "myprintf.h"

int my_str_non_print(va_list str, UNU params param_struct, int *count)
{
    char const *s = va_arg(str, char *);

    my_putstr_non_print(s);
    *count += my_strlen(s);
    return my_strlen(s);
}
