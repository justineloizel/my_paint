/*
** EPITECH PROJECT, 2022
** my_strlowcase
** File description:
** stand by
*/

#include <stdio.h>

char *my_strlowcase(char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] > 64 && str[i] < 91)
            str[i] = str[i]  + 32;
    }
    return str;
}
