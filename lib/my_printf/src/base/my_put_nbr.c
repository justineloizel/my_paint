/*
** EPITECH PROJECT, 2022
** tkt
** File description:
** tkt
*/

#include <unistd.h>
void my_putchar(char c);

int my_put_nbr(int nb)
{
    if (nb < 0) {
        nb = nb * (-1);
        write(1, "-", 1);
    }
    if (nb > 9) {
        my_put_nbr(nb / 10);
        my_putchar((nb % 10) + 48);
    }
    if (nb < 10)
        my_putchar(nb + 48);
    return 0;
}
