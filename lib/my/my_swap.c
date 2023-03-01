/*
** EPITECH PROJECT, 2022
** my_swap.c
** File description:
** swap two valor
*/

void my_swap(int *a, int *b)
{
    int tmp = *b;

    *b = *a;
    *a = tmp;
}
