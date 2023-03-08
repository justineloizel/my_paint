/*
** EPITECH PROJECT, 2023
** B-MUL-200-REN-2-1-mypaint-tom.lefoix
** File description:
** destroy.c
*/

#include "paint.h"

static void free_button(button_t *button)
{
    sfTexture_destroy(button->texture);
    sfSprite_destroy(button->sprite);
    free(button);
}

static void free_list_button(list_button_t *list_button)
{
    button_t *tmp = list_button->head;
    button_t *next = NULL;

    while (tmp != NULL) {
        next = tmp->next;
        free_button(tmp);
        tmp = next;
    }
    free(list_button);
}

static void free_list_menu(list_menu_t *list_menu)
{
    menu_t *tmp = list_menu->head;
    menu_t *next = NULL;

    while (tmp != NULL) {
        next = tmp->next;
        free_button(tmp->menu_button);
        free_list_button(tmp->button_list);
        free(tmp);
        tmp = next;
    }
    free(list_menu);
}

void destroy_storage(main_t *storage)
{
    free_window(&storage->window);
    free_list_menu(storage->list_menu);
    board_destroy(storage->board);
    free(storage);
}