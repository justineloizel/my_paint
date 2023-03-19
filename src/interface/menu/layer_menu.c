/*
** EPITECH PROJECT, 2022
** B-MUL-200-REN-2-1-mypaint-tom.lefoix
** File description:
** layer_menu.c
*/

#include "paint.h"

void layer_plus(void *storage, UNUSED int id)
{
    add_layer(((main_t *)storage)->board->layerList, NULL);
    ((main_t *)storage)->board->actual_layer =
    ((main_t *)storage)->board->layerList->tail;
}

void layer_less(void *storage, UNUSED int id)
{
    manager_delete_layer(((main_t *)storage), 0);
}

void thicker_brush(void *storage, UNUSED int id)
{
    ((main_t *)storage)->board->size += 1;
}

void thinner_brush(void *storage, UNUSED int id)
{
    if (((main_t *)storage)->board->size == 1)
        return;
    ((main_t *)storage)->board->size -= 1;
}

void check_top_menu(main_t *storage, int id)
{
    int file_menu = is_visible_menu(FILE_MENU, storage->list_menu->list_menu);
    int edit_menu = is_visible_menu(EDIT, storage->list_menu->list_menu);
    int help_menu = is_visible_menu(HELP, storage->list_menu->list_menu);

    if (id < 0)
        return;
    if (file_menu != -1 && id != FILE_MENU) {
        button_menu_is_clicked((void *)storage, -FILE_MENU);
        return;
    }
    if (edit_menu != -1 && id != EDIT) {
        button_menu_is_clicked((void *)storage, -EDIT);
        return;
    }
    if (help_menu != -1 && id != HELP) {
        button_menu_is_clicked((void *)storage, -HELP);
        return;
    }
}
