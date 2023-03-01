/*
** EPITECH PROJECT, 2022
** tkt
** File description:
** tkt
*/

#include <unistd.h>
int my_putchar(char c);

int my_put_nbr_pres(int nb, int pres, int plus)
{
    int count = 0;

    if (nb > 0 && plus)
        write(1, "+", 1);
    if (nb < 0) {
        nb = nb * (-1);
        write(1, "-", 1);
    }
    for (int i = 10; (nb) / i != 0; i *= 10, count++);
    for (int i = 1; i < (pres - count); i++)
        write(1,"0", 1);
    if (nb > 9) {
        my_put_nbr_pres(nb / 10, 0, 0);
        my_putchar((nb % 10) + 48);
    }
    if (nb < 10)
        my_putchar(nb + 48);
    return 0;
}
