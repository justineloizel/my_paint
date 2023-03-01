/*
** EPITECH PROJECT, 2022
** my_scinbr.c
** File description:
** print a numbers under scientifics form
*/

#include <stdio.h>
#include <unistd.h>

int my_compute_power_rec(int nb, int p);
int my_putfloat(double nb, int pres);
int my_putchar(char c);
int my_put_nbr(int nb);

static void print_sci(int count, int UP)
{
    if (UP == 1)
        write(1, "E", 1);
    else
        write(1, "e", 1);

    if (count < 0)
        write(1, "-", 1);
    else
        write(1, "+", 1);

    if ((count - 1) < 10)
        write(1, "0", 1);

    if (count > 0)
        my_put_nbr(count - 1);

    if (count < 0)
        my_put_nbr(count * -1);
}

int my_scinbr(double nb, int UP, int pres, int hashtag)
{
    int count = 0;
    int check = 0;

    if (nb < 0) {
        write(1, "-", 1);
        nb *= -1;
    }
    for (int i = 1; (((int)nb) / i) != 0; i *= 10, count++, check++);
    for (int i = 1; check == 0 && (int)(nb * i) == 0; count--, i *= 10);
    if (check != 0)
        my_putfloat((nb / my_compute_power_rec(10, count - 1)), pres);
    else
        my_putfloat((nb * my_compute_power_rec(10, (count * -1))), pres);
    if (!pres && hashtag)
        write(1, ".", 1);
    else
    hashtag = 0;
    print_sci(count, UP);
    return (5 + pres + hashtag);
}
