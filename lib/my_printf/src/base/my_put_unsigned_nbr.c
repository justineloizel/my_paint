/*
** EPITECH PROJECT, 2022
** my_put_nbr
** File description:
** my_put_nbr
*/

#include "myprintf.h"

int my_put_unsigned_nbr(unsigned int nb, int pres)
{
    unsigned int temp;
    int count = 0;

    if (nb > 0) {
        for (long int i = 10; (nb) / i != 0; i *= 10, count++);
        for (int i = 1; i < (pres - count); i++)
            write(1, "0", 1);
    }
    if (nb > 9) {
        temp = nb % 10;
        nb = nb / 10;
        my_put_unsigned_nbr(nb, 0);
        my_putchar(temp + 48);
    } else {
        my_putchar(nb + 48);
    }
    if (nb == 0)
        write(1, "0", 1);
    return (nb);
}
