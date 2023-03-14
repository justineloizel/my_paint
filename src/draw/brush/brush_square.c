/*
** EPITECH PROJECT, 2023
** B-MUL-200-REN-2-1-mypaint-tom.lefoix
** File description:
** brush_square.c
*/

#include "paint.h"

void draw_filled_square(board_t *board, sfVector2i position)
{
    for (int i = 0; i < board->size; i++) {
        for (int j = 0; j < board->size; j++) {
            put_pixel(board->actual_layer, position.x + j, position.y + i,
                      board->color);
        }
    }
}

void draw_square(board_t *board, sfVector2i position)
{
    for (int i = 0; i < board->size; i++) {
        put_pixel(board->actual_layer, position.x + i,
        position.y, board->color);
        put_pixel(board->actual_layer, position.x + i,
        position.y + board->size - 1, board->color);
        put_pixel(board->actual_layer, position.x, position.y + i,
        board->color);
        put_pixel(board->actual_layer, position.x + board->size - 1,
        position.y + i, board->color);
    }
}
