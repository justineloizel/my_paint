/*
** EPITECH PROJECT, 2022
** my_strlen
** File description:
** count number of char in str
*/

int my_strlen(char const *str)
{
    int count = 0;

    for (; str[count]; count++);
    return (count);
}
