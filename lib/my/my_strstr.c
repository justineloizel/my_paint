/*
** EPITECH PROJECT, 2022
** my_strstr
** File description:
** find a str in other str , return pointers if find a str , else 0
*/
#include <stdio.h>

int boucle2(char *str, char const *to_find, int i)
{
    int save;
    int check = 0;
    int j = 0;
    for (j = 0; str[i] == to_find[j] && to_find[j] != '\0';) {
        if (check == 0) {
            check = 1;
            save = i;
        }
        i += 1;
        j += 1;
    }
    if (j != 0)
        i = save;
    if (to_find[j] == '\0')
        return (i = -1);
    check = 0;
    return i;
}

char *my_strstr(char *str, char const *to_find)
{
    int j = 0;
    int h;

    if (to_find[0] == '\0')
        return (&str[0]);
    for (int i = 0; str[i] != '\0'; i++){
        if (str[i] == to_find[j])
            h = boucle2(str, to_find, i);
        if (h == -1)
            return (&str[i]);
    }
    return "NULL";
}
