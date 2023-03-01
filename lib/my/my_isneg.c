/*
** EPITECH PROJECT, 2022
** my_isneg
** File description:
** return N if n is negative or P if n is null or positive
*/

void my_putchar(char c);

int my_isneg(int n)
{
    if (n < 0) {
        my_putchar(78);
    } else {
        my_putchar(80);
    }
}
