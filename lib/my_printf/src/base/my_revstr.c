/*
** EPITECH PROJECT, 2022
** my_revstr
** File description:
** my_revstr
*/

int my_strlen(char const* str);

char *my_revstr(char *str)
{
    int a = 0;
    int len = my_strlen(str);
    int b = len / 2;
    char temp;

    while (a < b) {
        temp = str[a];
        str[a] = str[len - 1 - a];
        str[len - 1 - a] = temp;
        a++;
    }
    return (str);
}
