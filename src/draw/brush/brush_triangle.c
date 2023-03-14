/*
** EPITECH PROJECT, 2023
** B-MUL-200-REN-2-1-mypaint-tom.lefoix
** File description:
** brush.c
*/

#include "paint.h"

void draw_filled_triangle(board_t *board, sfVector2i position)
{
    int x = position.x;
    int y = position.y;

    for (int i = board->size - 1; i >= 0; i--) {
        put_pixel(board->actual_layer, x + i, y, board->color);
        put_pixel(board->actual_layer, x + board->size - 1 - i / 2, y + i,
        board->color);
        put_pixel(board->actual_layer, x + i / 2, y + i, board->color);

        for (int j = x + i / 2 + 1; j < x + board->size - 1 - i / 2; j++) {
            put_pixel(board->actual_layer, j, y + i, board->color);
        }
    }
}

void draw_triangle(board_t *board, sfVector2i position)
{
    int height = (int)(sqrt(3) / 2 * board->size);
    int x = position.x;
    int y = position.y;

    for (int i = 0; i < board->size; i++) {
        put_pixel(board->actual_layer, x + i, y + height - 1, board->color);
        put_pixel(board->actual_layer, x + board->size - 1 - i / 2,
        y + height - 1 - i, board->color);
        put_pixel(board->actual_layer, x + i / 2, y + height - 1 - i,
        board->color);
    }
}

void draw_triangle_reverse(board_t *board, sfVector2i position)
{
    int x = position.x;
    int y = position.y;

    for (int i = 0; i < board->size; i++) {
        put_pixel(board->actual_layer, x + i, y, board->color);
        put_pixel(board->actual_layer, x + board->size - 1 - i / 2, y + i,
        board->color);
        put_pixel(board->actual_layer, x + i / 2, y + i, board->color);
    }
}

void draw_triangle_reverse_filled(board_t *board, sfVector2i position)
{
    int x = position.x;
    int y = position.y;

    for (int i = board->size - 1; i >= 0; i--) {
        put_pixel(board->actual_layer, x + i, y, board->color);
        put_pixel(board->actual_layer, x + board->size - 1 - i / 2, y + i,
        board->color);
        put_pixel(board->actual_layer, x + i / 2, y + i, board->color);

        for (int j = x + i / 2 + 1; j < x + board->size - 1 - i / 2; j++) {
            put_pixel(board->actual_layer, j, y + i, board->color);
        }
    }
}
