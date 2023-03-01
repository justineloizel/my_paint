/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** my_addlign.c
*/

#include <stdlib.h>
#include <stdio.h>
char *my_strdup(char const *src);
void my_puterror(char *error);

char **my_addlign(char **tab, char *str, int key)
{
    char **temps;
    int j = 0;
    int count = 0;
    for (; tab[count]; count++);
    if (count < key)
        my_puterror("a key is superior to the size of tab");
    temps = malloc(sizeof(char *) * count + 2);
    for (int h = 0; tab[h]; h++, j++) {
        if (h == key) {
            temps[j] = my_strdup(str);
            j += 1;
        }
        temps[j] = my_strdup(tab[h]);
    }
    if (count == key) {
        temps[j] = my_strdup(str);
        j += 1;
    }
    temps[j] = 0;
    return temps;
}
