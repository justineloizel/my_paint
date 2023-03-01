/*
** EPITECH PROJECT, 2022
** my_str_isalpha
** File description:
** stand by
*/

#include <stdio.h>

int my_str_isalpha(char const *str)
{
    if (str == NULL)
        return 0;
    for (int i = 0; str[i]; i++)
        if ((str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z'))
            return 0;
    return 1;
}
