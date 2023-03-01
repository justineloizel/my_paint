/*
** EPITECH PROJECT, 2022
** my_strdup
** File description:
** allocate memory in destination
*/

#include <stdlib.h>

int my_strlen(char const *str);

char *my_strdup(char const *src)
{
    int count = my_strlen(src);
    char *dest = malloc(sizeof(char) * (count + 1));

    if (dest == NULL || count == 0)
        return NULL;

    for (int i = 0; src[i] != 0; i++)
        dest[i] = src[i];

    dest[count] = '\0';

    return dest;
}
