/*
** EPITECH PROJECT, 2023
** B-MUL-200-REN-2-1-mypaint-tom.lefoix
** File description:
** display_menu_manager.c
*/

#include "button.h"

int *add_visible_menu(int *actual_list, int menu)
{
    size_t size = 0;
    int *new_list;
    for (; actual_list[size] != -1; size++);
    new_list = malloc(sizeof(int) * (size + 2));
    if (new_list == NULL)
        return actual_list;
    new_list[size + 1] = -1;
    for (size_t i = 0; i < size; i++) {
        new_list[i] = actual_list[i];
    }
    new_list[size] = menu;
    free(actual_list);
    return new_list;
}

int *delete_visible_menu(int *actual_list, int index)
{
    size_t size = 0;
    int *new_list;
    size_t j = 0;

    for (; actual_list[size] != -1; size++);
    if ((size_t)index > size || actual_list[0] == -1)
        return actual_list;
    new_list = malloc(sizeof(int) * (size));
    if (new_list == NULL)
        return actual_list;
    new_list[size - 1] = -1;
    for (size_t i = 0; i < size; i++) {
        if (i == (size_t)index)
            continue;
        new_list[j] = actual_list[i];
        j++;
    }
    free(actual_list);
    return new_list;
}
