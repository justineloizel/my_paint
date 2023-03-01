/*
** EPITECH PROJECT, 2022
** my_count_nbr_base
** File description:
** my_count_nbr_base
*/

#include <stdlib.h>
#include <stdio.h>

int my_strlen(char *str);

int my_count_nbr_base(int nbr, char *base)
{
    char *str;
    int j = 0;
    int nb = nbr;
    int div = my_strlen(base);

    for (; nbr != 0; j++)
        nbr = nbr / div;
    str = malloc(sizeof(char) * (j + 1));
    nbr = nb;
    for (int i = 0; nbr != 0; i++) {
        str[i] = base[nbr % div];
        nbr = nbr / div;
    }
    str[j] = '\0';
    return (my_strlen(str));
}
