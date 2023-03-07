/*
** EPITECH PROJECT, 2023
** B-MUL-200-REN-2-1-mypaint-tom.lefoix
** File description:
** menu.c
*/

#include <stdlib.h>
#include "menu.h"

static const menu_store_t menu_list[] = {
        {1, {1, "assets/restart_but.png", {500, 40}, {1, 1}, {0, 0, 80, 32},
        {0, 32, 80, 32},{0, 64, 80, 32}, button_menu_is_clicked}}
};

menu_t *init_menu(menu_store_t data)
{
    menu_t *menu = malloc(sizeof(menu_t));

    if (menu == NULL)
        return NULL;
    menu->id = data.id;
    menu->menu_button = init_button(data.button);
    menu->button_list = malloc(sizeof(list_button_t));
    if (menu->button_list == NULL)
        return NULL;
    menu->button_list->head = NULL;
    menu->button_list->tail = NULL;
    menu->next = NULL;
    menu->prev = NULL;
    return menu;
}

void add_new_menu(menu_store_t data, list_menu_t *list_menu)
{
    if (list_menu->head == NULL) {
        list_menu->head = init_menu(data);
        list_menu->tail = list_menu->head;
        return;
    }
    list_menu->tail->next = init_menu(data);
    list_menu->tail->next->prev = list_menu->tail;
    list_menu->tail = list_menu->tail->next;
}

menu_t *get_menu_by_id(int id, list_menu_t *list_menu)
{
    menu_t *menu = list_menu->head;

    for (; menu != NULL; menu = menu->next) {
        if (menu->id == id)
            return menu;
    }
    return NULL;
}

list_menu_t *create_base_menu(void)
{
    list_menu_t *list_menu = malloc(sizeof(list_menu_t));

    if (list_menu == NULL)
        return NULL;
    list_menu->list_menu = malloc(sizeof(int));
    if (list_menu->list_menu == NULL)
        return NULL;
    list_menu->list_menu[0] = -1;
    list_menu->head = NULL;
    list_menu->tail = NULL;
    for (size_t i = 0; i < ARRLEN(menu_list); i++) {
        add_new_menu(menu_list[i], list_menu);
    }
    return list_menu;
}
