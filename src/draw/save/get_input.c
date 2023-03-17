/*
** EPITECH PROJECT, 2023
** B-MUL-200-REN-2-1-mypaint-tom.lefoix
** File description:
** get_input.c
*/

#include "myprintf.h"
#include "my.h"

char *get_input(void)
{
    size_t len = 0;
    char *input = NULL;

    my_printf("Entrer le nom du fichier (sans l'extension) :");
    if (getline(&input, &len, stdin) == -1)
        return NULL;
    input[my_strlen(input) - 1] = '\0';
    if (my_strlen(input) < 1 || !my_str_isalphanum(input)) {
        free(input);
        return NULL;
    }
    return input;
}
