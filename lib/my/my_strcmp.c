/*
** EPITECH PROJECT, 2022
** my_strcmp
** File description:
** compare two string
*/

#include <stdio.h>

int my_strcmp(char const *s1, char const *s2)
{
    int i = 0;

    if (s1 == NULL || s2 == NULL)
        return 84;
    for (; s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0'; i++);
    if (s1[i] - s2[i] < 0)
        return (-1);
    if (s1[i] - s2[i] > 0)
        return (1);
    if (s1[i] == s2[i])
        return 0;
}
