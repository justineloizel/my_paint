/*
** EPITECH PROJECT, 2022
** my_put_nbr_base
** File description:
** my_put_nbr_base
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int my_put_nbr(int nb);
char *my_revstr(char *str);
int my_putstr(char const *str);
int my_strlen(char *str);

int my_put_unsigned_base(unsigned int nbr, char *base)
{
    char *str;
    int j = 0;
    unsigned int nb = nbr;
    int div = my_strlen(base);

    for (; nbr != 0; j++)
        nbr = nbr / div;
    str = malloc(sizeof(char) * (j + 1));
    nbr = nb;
    for (int i = 0; nbr != 0; i++) {
        str[i] = base[nbr % div];
        nbr = nbr / div;
    }
    my_revstr(str);
    return (write(1, str, my_strlen(str)));
}
