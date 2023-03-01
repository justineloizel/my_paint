/*
** EPITECH PROJECT, 2022
** my_strncat
** File description:
** copy of strncat
*/

#include <stdio.h>

int my_strlen(char const *str);

char *my_strncat(char *dest, char const *src, int nb)
{
    int count_d = my_strlen(dest);
    int i = count_d;

    for (int j = 0; src[j] != '\0' && j != nb; i++, j++)
        dest[i] = src[j];
    return (dest);
}
