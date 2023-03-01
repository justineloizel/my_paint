/*
** EPITECH PROJECT, 2022
** my_nbletter
** File description:
** return numbers of letter in string
*/

int is_alpha(char c)
{
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
        return 1;
    }
    return 0;
}

int my_nbletter(char *str)
{
    int count = 0;
    for (int i = 0; str[i] != '\0'; i++)
        if (is_alpha(str[i]))
            count += 1;
    return count;
}
