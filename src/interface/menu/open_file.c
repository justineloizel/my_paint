/*
** EPITECH PROJECT, 2022
** B-MUL-200-REN-2-1-mypaint-tom.lefoix
** File description:
** open_file.c
*/

#include "paint.h"

void open_file(void *storage, int id)
{
    ((main_t *)storage)->window.pop_up = OPEN;
    ((main_t *)storage)->list_menu->list_menu =
    add_visible_menu(((main_t *)storage)->list_menu->list_menu, POP_TOOL);
    button_menu_is_clicked(storage, id);
}
