/*
** EPITECH PROJECT, 2022
** my_str_isupper
** File description:
** stand by
*/

int my_str_isupper(char const *str)
{
    for (int i = 0; str[i]; i++)
        if (str[i] < 'A' || str[i] > 'Z')
            return 0;
    return 1;
}
