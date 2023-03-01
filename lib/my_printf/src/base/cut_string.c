/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** test.c
*/

#include <stdio.h>
#include <stdlib.h>

char *cut_string(char *strd, char *strf, char c)
{
    int i = 1;
    int nb = strf - strd;
    char *temps = malloc(sizeof(char) * (nb + 3));

    temps[0] = c;
    for (int j = 0; j <= nb; j++, i++)
        temps[i] = strd[j];
    temps[i] = '\0';
    return temps;
}
