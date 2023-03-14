/*
** EPITECH PROJECT, 2022
** B-MUL-200-REN-2-1-mypaint-tom.lefoix
** File description:
** pencil.c
*/

#include "paint.h"

void display_cursor(main_t *storage)
{
    storage->window.pen_pos.x = (sfMouse_getPositionRenderWindow(storage->window.window).x) - 0;
    storage->window.pen_pos.y = (sfMouse_getPositionRenderWindow(storage->window.window).y) - 24;
    sfSprite_setPosition(storage->window.pencil, storage->window.pen_pos);
    sfRenderWindow_drawSprite(storage->window.window, storage->window.pencil, NULL);
}

void drawing_activated(void *storage, int id)
{
    ((main_t *)storage)->window.cursor = 1;
    sfRenderWindow_setMouseCursorVisible(((main_t *)storage)->window.window, 0);
    button_menu_is_clicked(storage, id);
}