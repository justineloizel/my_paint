/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** my_puttab.c
*/

#include <unistd.h>
#include <stdlib.h>

int my_strlen(char const *str);

void free_tab(char **tab)
{
    for (int i = 0; tab[i]; i++)
        free(tab[i]);
    free(tab);
}

int my_puttab(char **tab)
{
    int count = 0;

    for (int i = 0; tab[i]; i++) {
        count += write(1, tab[i], my_strlen(tab[i]));
        count += write(1, "\n", 1);
    }
    return count;
}
