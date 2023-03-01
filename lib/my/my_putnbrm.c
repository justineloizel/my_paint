/*
** EPITECH PROJECT, 2022
** graphique
** File description:
** my_putnbrm.c
*/

#include <stdio.h>
#include <stdlib.h>

char *my_putnbrm(long int nbr)
{
    int count = 0;
    char *str;
    int is_neg = 0;
    if (nbr == 0) {
        str = malloc(sizeof(char) * 2);
        str[0] = '0';
        str[1] = '\0';
        return str;
    }
    for (int i = 1; nbr / i != 0; i *= 10, count++);
    if (nbr < 0) {
        is_neg = 1;
        nbr *= -1;
    } str = malloc(sizeof(char) * (count + 1 + is_neg));
    str[0] = (is_neg == 1) ? '-' : '\0';
    str[count + is_neg] = '\0';
    for (int i = count - 1 + is_neg; i >= 0 + is_neg; i--) {
        str[i] = (nbr % 10) + 48;
        nbr = nbr / 10;
    } return str;
}

char *my_putnbrm_2d(long int nbr)
{
    int count = 0;
    char *str;
    for (int i = 1; nbr / i != 0; i *= 10, count++);
    if (nbr < 10) {
        str = malloc(3);
        str[0] = '0';
        str[1] = nbr + 48;
        str[2] = '\0';
        return str;
    }
    str = malloc(sizeof(char) * (count + 1));
    str[count] = '\0';
    for (int i = count - 1; i >= 0; i--) {
        str[i] = (nbr % 10) + 48;
        nbr = nbr / 10;
    }
    return str;
}
