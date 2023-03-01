/*
** EPITECH PROJECT, 2022
** my_putfloat.C
** File description:
** put a float numbers
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int my_strlen(char const *str);
int my_put_nbr(int nb);
int my_putstr(char const *str);

char *my_round(char *str)
{
    int len = 0;

    for (; str[len]; len++);
    len--;
    for (; str[len] == '9' && len > 0; len--)
        str[len] = '0';
    if (str[len] < '9' && str[len] >= '0')
        str[len] += 1;
    if (len == 0)
        str[len] = '0';
    return (str);
}

static int check_round(char *str, int check)
{
    if (check == 0)
        if (str[0] == '9')
            return 1;
    if (str[0] == '0' && check == 1) {
        return 1;
    } else
        return 0;
}

static int create_str(double nb, char *str, int pres)
{
    long int j = 10;
    for (int h = 0; h < pres; h++, j *= 10)
        str[h] = (((int)(nb * j) - ((int)nb * j / 10)) % 10) + 48;
    str[pres] = '\0';
    return j;
}

int my_putfloat(double nb, int pres)
{
    char *str = malloc(sizeof(char) * (pres + 1));
    long int j = 0;
    double copy = nb;
    int check = 0;
    if (nb < 0)
        nb *= -1;
    nb -= (int)nb;
    j = create_str(nb, str, pres);
    check = check_round(str, check);
    if ((((int)(nb * j)) % 10) >= 5)
        str = my_round(str);
    check = check_round(str, check);
    if (pres == 0 && ((int)(nb * 10) % 10) >= 5)
        check += 1;
    my_put_nbr(copy + check);
    if (pres > 0)
        write(1, ".", 1);
    write(1, str, my_strlen(str));
    free(str);
    return (pres);
}
