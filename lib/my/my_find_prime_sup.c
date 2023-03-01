/*
** EPITECH PROJECT, 2022
** my_find_prime_sup
** File description:
** find a first prime nbr
*/

int my_is_prime(int nb);

int my_find_prime_sup(int nb)
{
    int val = 0;

    if ( nb == 1 || nb == 0)
        return 2;
    val = my_is_prime(nb);
    if (val == 1)
        return nb;

    while ( val != 1) {
        nb += 1;
        val = my_is_prime(nb);
    }
    if (nb != 0)
        nb -= 1;
    return nb;
}
