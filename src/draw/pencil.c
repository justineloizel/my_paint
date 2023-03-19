/*
** EPITECH PROJECT, 2022
** B-MUL-200-REN-2-1-mypaint-tom.lefoix
** File description:
** pencil.c
*/

#include "paint.h"

static void check_tools(main_t *storage)
{
    sprites_t *sprite = get_sprite(storage->window.sprites, SHAPE);

    if (storage->window.cursor == ERASER) {
        storage->window.eraser_pos = get_valid_position(storage,
        V2I_V2F(sfMouse_getPositionRenderWindow(storage->window.window)));
        storage->window.eraser_pos.y -= 24;
        sfSprite_setPosition(storage->window.eraser,
        storage->window.eraser_pos);
        sfRenderWindow_drawSprite(storage->window.window,
        storage->window.eraser, NULL);
        storage->board->color = sfTransparent;
        manage_draw(storage);
    }
    if (storage->window.pen == 1) {
        sfRenderWindow_drawSprite(storage->window.window,
        sprite->sprite, NULL);
        sprite = get_sprite(storage->window.sprites, THICKNESS);
        sfRenderWindow_drawSprite(storage->window.window,
        sprite->sprite, NULL);
    }
}

void display_cursor(main_t *storage)
{
    if (storage->window.cursor == PENCIL) {
        storage->window.pen_pos = get_valid_position(storage,
        V2I_V2F(sfMouse_getPositionRenderWindow(storage->window.window)));
        storage->window.pen_pos.y -= 24;
        sfSprite_setPosition(storage->window.pencil, storage->window.pen_pos);
        sfRenderWindow_drawSprite(storage->window.window,
        storage->window.pencil, NULL);
        manage_draw(storage);
    }
    check_tools(storage);
}

void drawing_activated(void *storage, int id)
{
    ((main_t *)storage)->window.cursor = PENCIL;
    ((main_t *)storage)->window.pen = 1;
    sfRenderWindow_setMouseCursorVisible(((main_t *)storage)->window.window,
    0);
    button_menu_is_clicked(storage, id);
    ((main_t *)storage)->list_menu->list_menu =
    add_visible_menu(((main_t *)storage)->list_menu->list_menu, PENCIL_TOOL);
}

void eraser_activated(void *storage, int id)
{
    ((main_t *)storage)->window.cursor = ERASER;
    ((main_t *)storage)->window.pen = 1;
    sfRenderWindow_setMouseCursorVisible(((main_t *)storage)->window.window,
    0);
    button_menu_is_clicked(storage, id);
    ((main_t *)storage)->list_menu->list_menu =
    add_visible_menu(((main_t *)storage)->list_menu->list_menu, PENCIL_TOOL);

}
