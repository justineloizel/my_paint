/*
** EPITECH PROJECT, 2022
** my_revstr
** File description:
** reverse chaine char
*/

int my_strlen(char const *str);

char *my_revstr(char *str)
{
    int d = 0;
    int f = my_strlen(str) - 1;
    int temp_f = f / 2;
    char temp_evil;

    while (d < temp_f) {
        temp_evil = str[d];
        str[d] = str[f];
        str[f] = temp_evil;
        d += 1;
        f -= 1;
    }
    return str;
}
