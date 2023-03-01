/*
** EPITECH PROJECT, 2022
** my_puterror
** File description:
** put message of error in error output
*/

#include <unistd.h>
int my_strlen(char const *str);

void my_puterror(char *error)
{
    write(2, error, my_strlen(error));
    write(2, "\n", 1);
}
