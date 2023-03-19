/*
** EPITECH PROJECT, 2022
** my_strcpy
** File description:
** copy a string in the other string
*/

#include <stddef.h>
void my_putchar(char c);
void my_putstr(char const *str);

char *my_strcpy(char *dest, char const *src)
{
    int i = 0;

    if (dest == NULL || src == NULL)
        return (char *)src;
    for (; src[i] != '\0'; i++)
        dest[i] = src[i];
    dest[i] = '\0';
    return (dest);
}
