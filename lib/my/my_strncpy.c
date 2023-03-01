/*
** EPITECH PROJECT, 2022
** my_strncpy
** File description:
** copy str in other str with n char
*/

void my_putchar(char c);
void my_putstr(char const *str);
int my_strlen(char const *str);

char *my_strncpy(char *dest, char const *src, int n)
{
    int i = 0;
    int count = my_strlen(src);

    for (; src[i] != '\0' && i != n; i++)
        dest[i] = src[i];
    if (count < n)
        dest [i] = '\0';
    return (dest);
}
