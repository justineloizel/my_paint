/*
** EPITECH PROJECT, 2022
** my_putstr
** File description:
** put a charractere of strf witch putchar
*/

#include <unistd.h>
int my_strlen(char const *str);
int my_put_nbr_base(int nbr, char *base);
void my_putchar(char c);

int my_putstr_non_print(char const *str)
{
    int value;

    for (int i = 0; i < my_strlen(str); i++) {
        if (str[i] < 32 || str[i] >= 127) {
            value = str[i];
            my_putchar('\\');
            my_put_nbr_base(value, "01234567");
        } else {
            write(1, &str[i], 1);
        }
    }
    return (my_strlen(str));
}
