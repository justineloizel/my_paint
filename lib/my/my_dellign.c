/*
** EPITECH PROJECT, 2022
** my_delling
** File description:
** how to dell lign in a char **
*/

#include <stdio.h>
#include <stdlib.h>

char *my_strdup(char const *src);
void my_puterror(char *error);

char **my_dellign(char **tab, int key_del)
{
    char **temps;
    int count = 0;
    int j = 0;

    for (; tab[count]; count++);
    if (count < key_del)
        my_puterror("a key is superior to the size of the tab");
    temps = malloc(sizeof(char *) * count + 1);
    for (int i = 0; tab[i]; i++, j++) {
        if (i == key_del) {
            j -= 1;
            continue;
        }
        temps[j] = my_strdup(tab[i]);
    }
    return temps;
}
