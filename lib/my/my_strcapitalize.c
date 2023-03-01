/*
** EPITECH PROJECT, 2022
** my_strcapitalize
** File description:
** cap
*/

#include <stdio.h>
#include <stdlib.h>

int is_alphanum(char c);

static char *ch_nb(char *str, int i)
{
    for (; is_alphanum(str[i]); i++) {
        if (str[i] >= 'A' && str[i] <= 'Z')
            str[i] += 32;
    }
    return str;
}

char *my_strcapitalize(char *str)
{
    for (int i = 0; str[i]; i++) {
        if (i == 0 && (str[i] > 96 && str[i] < 123))
            str[i] -= 32;
        if (is_alphanum(str[i - 1]) == 0 && str[i] >= 'a' && str[i] <= 'z')
            str[i] -= 32;
    }
    for (int i = 0; str[i]; i++)
        if (str[i - 1] >= '0' && str[i -1] <= '9')
            str = ch_nb(str, i);
    return str;
}
