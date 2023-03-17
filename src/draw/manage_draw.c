/*
** EPITECH PROJECT, 2023
** B-MUL-200-REN-2-1-mypaint-tom.lefoix
** File description:
** manage_draw.c
*/

#include "paint.h"

int is_board(main_t *storage)
{
    sfVector2f pos_board = sfRectangleShape_getPosition(storage->board->board);
    sfVector2f size_board = sfRectangleShape_getSize(storage->board->board);
    sfVector2f mouse_pos = get_valid_position(storage,
    V2I_V2F(sfMouse_getPositionRenderWindow(storage->window.window)));

    if (mouse_pos.x >= pos_board.x &&
    mouse_pos.x <= pos_board.x + size_board.x
    && mouse_pos.y >= pos_board.y &&
    mouse_pos.y <= pos_board.y + size_board.y)
        return 1;
    return 0;
}

void is_in_palette(main_t *storage)
{
    sfVector2f pos_palette = sfSprite_getPosition(storage->palette->sprite);
    sfVector2u size_palette = sfImage_getSize(storage->palette->image);
    sfVector2f mouse_pos = get_valid_position(storage,
    V2I_V2F(sfMouse_getPositionRenderWindow(storage->window.window)));

    if (mouse_pos.x >= pos_palette.x && mouse_pos.x <= pos_palette.x +
    (double)size_palette.x
    && mouse_pos.y >= pos_palette.y && mouse_pos.y <= pos_palette.y +
    (double)size_palette.y) {
        BOARD->color = sfImage_getPixel(storage->palette->image, (size_t)(mouse_pos.x - PALETTE_POS.x), (size_t)(mouse_pos.y - PALETTE_POS.y));
    }
}

void manage_draw(main_t *storage)
{
    sfBool mouse_is_pressed = sfMouse_isButtonPressed(sfMouseLeft);
    if (mouse_is_pressed && is_board(storage))
        draw_object(storage->board, V2F_V2I(get_valid_position(storage,
        V2I_V2F(sfMouse_getPositionRenderWindow(storage->window.window)))));
    else if (mouse_is_pressed)
        is_in_palette(storage);
}

int is_around(sfVector2i position_f, sfVector2i position_a, int size)
{
    int norm = (position_f.x - position_a.x) + (position_f.y - position_a.y);
    if (norm < size) {
        return 1;
    }
    return 0;
}
