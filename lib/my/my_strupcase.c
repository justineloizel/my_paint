/*
** EPITECH PROJECT, 2022
** my_strupcase
** File description:
** stand-by
*/
#include <stdio.h>

char *my_strupcase(char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] > 96 && str[i] < 122)
            str[i] = str[i]  - 32;
    }
    return str;
}
