/*
** EPITECH PROJECT, 2023
** B-MUL-200-REN-2-1-mypaint-tom.lefoix
** File description:
** menu_manager.c
*/

#include "paint.h"

int is_visible_menu(int id, int const *list)
{
    for (size_t i = 0; list[i] != -1; i++)
        if (list[i] == id)
            return (int)i;
    return -1;
}

void print_button_menu(list_menu_t *list_menu, sfRenderWindow *window)
{
    menu_t *menu = list_menu->head;
    for (; menu != NULL; menu = menu->next) {
        is_hover(menu->menu_button, window);
        sfRenderWindow_drawSprite(window, menu->menu_button->sprite, NULL);
        if (is_visible_menu(menu->id, list_menu->list_menu) != -1)
            print_list_button(menu->button_list, window);
    }
}

void verify_menu_click(sfMouseButtonEvent event, main_t *storage)
{
    menu_t *menu = storage->list_menu->head;
    for (; menu != NULL; menu = menu->next) {
        is_click(event, storage, menu->menu_button);
        if (is_visible_menu(menu->id, storage->list_menu->list_menu) != -1)
            is_click(event, storage, menu->button_list->head);
    }
}

void button_menu_is_clicked(void *storage, int id)
{
    list_menu_t *menus = ((main_t *)storage)->list_menu;
    int index = is_visible_menu(id, menus->list_menu);
    if (index != -1) {
        menus->list_menu = delete_visible_menu(menus->list_menu, index);
    } else {
        menus->list_menu = add_visible_menu(menus->list_menu, id);
    }
}
