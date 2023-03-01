/*
** EPITECH PROJECT, 2022
** my_str_isprintable
** File description:
** stand by
*/

int my_str_isprintable(char const *str)
{
    for (int i = 0; str[i]; i++)
        if (str[i] < 32 || str[i] > 126)
            return 0;
    return 1;
}
