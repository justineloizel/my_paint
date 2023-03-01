/*
** EPITECH PROJECT, 2022
** B-CPE-101-REN-1-1-myprintf-tom.lefoix
** File description:
** my_error_flag.c
*/

#include "myprintf.h"

int my_error_flag(va_list error, UNU params param_struct, int *count)
{
    char const *error_s = va_arg(error, char *);
    *count = write(2, error_s, my_strlen(error_s));
    return 0;
}
