/*
** EPITECH PROJECT, 2022
** square root
** File description:
** calcul square root
*/

int my_compute_square_root(int nb)
{
    int stock;
    int val = 0;

    if (nb == 1)
        return nb;
    while ( stock != nb) {
        stock = val * val;
        val += 1;
        if (val == nb)
            return 0;
        if (val == 55000)
            return 0;
    }
    if (val != 0)
        val -= 1;
    return (val);
}
