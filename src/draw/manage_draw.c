/*
** EPITECH PROJECT, 2023
** B-MUL-200-REN-2-1-mypaint-tom.lefoix
** File description:
** manage_draw.c
*/

#include "my.h"
#include "myprintf.h"
#include "paint.h"

int is_board(main_t *storage)
{
    sfVector2f pos_board = sfRectangleShape_getPosition(storage->board->board);
    sfVector2f size_board = sfRectangleShape_getSize(storage->board->board);
    sfVector2f mouse_pos = get_valid_position(storage,
    V2I_V2F(sfMouse_getPositionRenderWindow(storage->window.window)));

    if (mouse_pos.x >= pos_board.x + (float)(BOARD->size / 2) &&
    mouse_pos.x <= pos_board.x + size_board.x - (BOARD->size / 2)
    && mouse_pos.y >= pos_board.y + (BOARD->size / 2) &&
    mouse_pos.y <= pos_board.y + size_board.y - (float)(BOARD->size / 2))
        return 1;
    return 0;
}

void manage_draw(main_t *storage)
{
    if (sfMouse_isButtonPressed(sfMouseLeft) && is_board(storage))
        draw_object(storage->board, V2F_V2I(get_valid_position(storage,
        V2I_V2F(sfMouse_getPositionRenderWindow(storage->window.window)))));
}

int is_around(sfVector2i position_f, sfVector2i position_a, int size)
{
    int norm = (position_f.x - position_a.x) + (position_f.y - position_a.y);
    if (norm < size) {
        return 1;
    }
    return 0;
}
