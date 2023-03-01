/*
** EPITECH PROJECT, 2022
** B-CPE-101-REN-1-1-myprintf-tom.lefoix
** File description:
** flag_t.c
*/

#include "myprintf.h"

int my_tab(va_list tab, UNU params param_struct, int *count)
{
    *count += my_puttab(va_arg(tab, char **));
    return 0;
}
