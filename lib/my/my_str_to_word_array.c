/*
** EPITECH PROJECT, 2022
** Pokedex
** File description:
** Str to word array
*/

#include <stdlib.h>
#include <unistd.h>

int my_strlen(char const *str);

int is_alphanum(char c)
{
    return (
        (c >= 'a' && c <= 'z')
        || (c >= 'A' && c <= 'Z')
        || (c >= '0' && c <= '9')
        );
}

int is_separator(char const *separators, char letter)
{
    for (int i = 0; separators[i]; i++) {
        if (separators[i] == letter)
            return 1;
    }
    return 0;
}

int count_word(char const *str, char *separators)
{
    int count = 0;
    size_t len = my_strlen(str);

    if (str == NULL)
        return 0;
    for (size_t i = 0; i < len; i++) {
        if (is_separator(separators, str[i]) &&
        !is_separator(separators,str[i + 1]))
            count += 1;
    }
    return count + (len > 0 && !is_separator(separators, str[len - 1]));
}

static int fill_tab(char **tab, size_t len, char const *str, char *separators)
{
    int z = 0;
    int check;
    size_t save;

    for (size_t i = 0; i < len; i++) {
        check = 0;
        save = i;
        for (; is_separator(separators, str[i]) && i < len; i++, save++);
        for (; !is_separator(separators, str[i]) && i < len; check++, i++);
        tab[z] = malloc(sizeof(char) * (check + 1));
        if (tab[z] == NULL)
            return 84;
        for (int j = 0; j != check; save++, j++)
            tab[z][j] = str[save];
        tab[z][check] = '\0';
        z++;
    }
    return 0;
}

char **my_str_to_word_array(char const *str, char *separators)
{
    size_t len = my_strlen(str);
    int nb_word = count_word(str, separators);
    char **tab = malloc(sizeof(char *) * (nb_word + 1));
    for (int i = 0; i <= nb_word; i++)
        tab[i] = NULL;
    if (tab == NULL || str == NULL || str[0] == '\0') {
        free(tab);
        return NULL;
    }
    if (fill_tab(tab, len, str, separators) == 84)
        return NULL;
    if (tab[nb_word - 1] != NULL && tab[nb_word -1][0] == '\0')
        tab[nb_word -1] = NULL;
    tab[nb_word] = NULL;
    return tab;
}
