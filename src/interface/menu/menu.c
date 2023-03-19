/*
** EPITECH PROJECT, 2023
** B-MUL-200-REN-2-1-mypaint-tom.lefoix
** File description:
** menu.c
*/

#include <stdlib.h>
#include "paint.h"

static const menu_store_t menu_list[] = {
        {FILE_MENU, {FILE_MENU, "assets/file_button.png", {0, 0}, {1, 1},
        {0, 0, 160, 40}, {0, 43, 160, 43},{0, 86, 160, 43},
        button_menu_is_clicked}},

        {EDIT, {EDIT, "assets/Edit.png", {160, 0}, {1, 1}, {0, 0, 160, 40},
        {0, 43, 160, 43},{0, 86, 160, 43}, button_menu_is_clicked}},

        {HELP, {HELP, "assets/Help.png", {320, 0}, {1, 1}, {0, 0, 160, 40},
        {0, 43, 160, 43},{0, 86, 160, 43}, button_menu_is_clicked}},

        {POP_TOOL, {POP_TOOL, "assets/manual.png", {3000, 3000}, {1, 1},
        {0, 0, 160, 40}, {0, 43, 160, 43},{0, 86, 160, 43}, NULL}},

        {PENCIL_TOOL, {PENCIL_TOOL, "assets/pencil.png", {3000, 3000}, {1, 1},
        {0, 0, 160, 40}, {0, 43, 160, 43},{0, 86, 160, 43}, NULL}},

        {QUIT, {QUIT, "assets/error.png", {1880, 0}, {1, 1}, {0, 0, 40, 40},
        {0, 43, 40, 40},{0, 0, 40, 40}, quit_paint}},

        {ADD_LAYER, {ADD_LAYER, "assets/add_layer.png", {280, 950}, {1, 1},
        {0, 0, 40, 40}, {0, 43, 40, 40},{0, 86, 40, 40}, layer_plus}},

        {LESS_LAYER, {LESS_LAYER, "assets/less_layer.png", {80, 950}, {1, 1},
        {0, 0, 40, 40}, {0, 43, 40, 40},{0, 86, 40, 40}, layer_less}},

        {TOP_NAV, {TOP_NAV, "assets/top_nav.png", {150, 900}, {1, 1},
        {0, 0, 40, 40}, {0, 43, 40, 40},{0, 86, 40, 40}, nav_top_layer}},

        {BOTTOM_NAV, {BOTTOM_NAV, "assets/bottom_nav.png", {190, 900}, {1, 1},
        {0, 0, 40, 40}, {0, 43, 40, 40},{0, 86, 40, 40}, nav_bottom_layer}},

        {NOT_VISIBLE, {NOT_VISIBLE, "assets/not_visible.png", {250, 900},
        {1, 1},
        {0, 0, 40, 40}, {0, 43, 40, 40},{0, 86, 40, 40}, mask_layer}},

        {SAVE_POP, {SAVE_POP, "assets/save_file.png", {3000, 3000}, {1, 1},
        {0, 0, 160, 40}, {0, 43, 160, 43},{0, 86, 160, 43},
        button_menu_is_clicked}},

};

menu_t *init_menu(menu_store_t data)
{
    menu_t *menu = malloc(sizeof(menu_t));

    if (menu == NULL)
        return NULL;
    menu->id = data.id;
    menu->menu_button = init_button(data.button);
    menu->button_list = malloc(sizeof(list_button_t));
    if (menu->button_list == NULL || menu->menu_button == NULL)
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
    if (list_menu->tail->next == NULL)
        return;
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
