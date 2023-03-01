/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** my_get_nbr_aft_point.c
*/

#include <stdio.h>
#include "myprintf.h"

int is_num(char nb)
{
    if (nb >= '0' && nb <= '9')
        return 1;
    return 0;
}

int my_getnbr_aft_point(char const *str)
{
    int nb = 0;
    int i = 0;
    for (; str[i] != '.' && str[i]; i++);
    if (!str[i])
        return -1;
    nb = my_getnbr(&str[i]);
    return nb;
}

int my_getnbr_bef_point(char const *str)
{
    int neg = 1;
    long int n = 0;
    int check = 0;

    for (int i = 0; (str[i] < '0' || str[i] > '9') && str[i]; i++)
        if (str[i] == '-')
            neg = neg * (-1);
    for (int j = 0; str[j] && str[j] != '.'; j++) {
        for (; str[j] >= '0' && str[j] <= '9'; j++, check++)
            n = (n * 10) + (str[j] - '0');
        if (check != 0 && n < 2147483647)
            return (n * neg);
    }
    return 0;
}
