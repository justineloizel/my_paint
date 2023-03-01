/*
** EPITECH PROJECT, 2022
** flag_n.c
** File description:
** flag_n.c
*/

#include "myprintf.h"

int my_n_flag(int *count, va_list c)
{
    int *n = va_arg(c, int *);

    *n = *count;
    return 0;
}
