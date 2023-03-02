/*
** EPITECH PROJECT, 2022
** emacs my_strcat
** File description:
** concatenate two str
*/

#include <stdio.h>
#include <stdlib.h>
#include "my.h"

int my_strlen(char const *str);

char *my_strcat(char *dest, char const *src)
{
    int i = my_strlen(dest);
    char *temps = malloc(sizeof(char) * ((i + my_strlen(src)) + 1));

    if (dest == NULL || src == NULL)
        return my_strdup((dest == NULL) ? src : dest);
    for (int x = 0; x <= (i + my_strlen(src)); x++)
        temps[x] = '\0';
    temps = my_strcpy(temps, dest);
    for (int j = 0; src[j] != '\0'; i++, j++)
        temps[i] = src[j];
    return (temps);
}
