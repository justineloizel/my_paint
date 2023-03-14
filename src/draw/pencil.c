/*
** EPITECH PROJECT, 2022
** B-MUL-200-REN-2-1-mypaint-tom.lefoix
** File description:
** pencil.c
*/

#include "paint.h"

void display_cursor(main_t *storage)
{
    if (storage->window.cursor == 1) {
        storage->window.pen_pos = get_valid_position(storage,
        V2I_V2F(sfMouse_getPositionRenderWindow(storage->window.window)));
        storage->window.pen_pos.y -= 24;
        sfSprite_setPosition(storage->window.pencil, storage->window.pen_pos);
        sfRenderWindow_drawSprite(storage->window.window, storage->window.pencil, NULL);
        storage->board->color = sfBlack;
        manage_draw(storage);
    }
    if (storage->window.cursor == 2) {
        storage->window.eraser_pos = get_valid_position(storage,
        V2I_V2F(sfMouse_getPositionRenderWindow(storage->window.window)));
        storage->window.eraser_pos.y -= 24;
        sfSprite_setPosition(storage->window.eraser, storage->window.eraser_pos);
        sfRenderWindow_drawSprite(storage->window.window, storage->window.eraser, NULL);
        storage->board->color = sfTransparent;
        manage_draw(storage);
    }
}

void drawing_activated(void *storage, int id)
{
    ((main_t *)storage)->window.cursor = 1;
    sfRenderWindow_setMouseCursorVisible(((main_t *)storage)->window.window, 0);
    button_menu_is_clicked(storage, id);
    // menu pops up with possibility to change line thickness +
    // color palette (color picker)!
}

void eraser_activated(void *storage, int id)
{
    ((main_t *)storage)->window.cursor = 2;
    sfRenderWindow_setMouseCursorVisible(((main_t *)storage)->window.window, 0);
    button_menu_is_clicked(storage, id);
    // menu pops up with possibility to change shape and thickness
}
