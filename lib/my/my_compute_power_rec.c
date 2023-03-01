/*
** EPITECH PROJECT, 2022
** my_compute_power_rec
** File description:
** print number of power p with recusivity
*/

int my_compute_power_rec(int nb, int p)
{
    if (p == 0)
        return 1;
    if (p < 0)
        return 0;
    return (my_compute_power_rec(nb, p - 1) * nb);
}
