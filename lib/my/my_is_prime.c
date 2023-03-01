/*
** EPITECH PROJECT, 2022
** my_is_prime
** File description:
** check if nb is prime
*/

int my_is_prime(int nb)
{
    int val = 2;

    if (nb == 2)
        return 1;
    while ( nb % val != 0){
        val += 1;
        if (val == nb)
            return 1;
    }
    return 0;
}
