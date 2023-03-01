/*
** EPITECH PROJECT, 2022
** param_minus_plus.c
** File description:
** param_minus_plus.c
*/

#include "myprintf.h"

int my_plus(int i)
{
    if (i >= 0) {
        write(1, "+", 1);
        return 1;
    }
    return 0;
}

int my_minus(int i)
{
    for (int j = 0; j < i; j++)
        write(1, " ", 1);
    return 0;
}

int my_zero(int i)
{
    for (int j = 0; j < i; j++)
        write(1, "0", 1);
    return 0;
}
