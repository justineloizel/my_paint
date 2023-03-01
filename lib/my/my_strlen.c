/*
** EPITECH PROJECT, 2022
** my_strlen
** File description:
** count number of char in str
*/

#include <stdio.h>

int my_strlen(char const *str)
{
    if (str == NULL)
        return 0;
    int count = 0;
    while ( str[count] != '\0') {
        count += 1;
    }
    return (count);
}
