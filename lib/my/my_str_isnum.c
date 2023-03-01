/*
** EPITECH PROJECT, 2022
** my_str_isnum
** File description:
** stand by
*/

#include <stdio.h>

int my_str_isalphanum(char const *str)
{
    if (str == NULL)
        return 0;
    for (int i = 0; str[i]; i++)
        if ((str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z') &&
                (str[i] < '0' || str[i] > '9'))
            return 0;
    return 1;
}

int my_str_isnum(char const *str)
{
    if (str == NULL)
        return 0;
    for (int i = 0; str[i]; i++)
        if (str[i] < '0' || str[i] > '9')
            return 0;
    return 1;
}
