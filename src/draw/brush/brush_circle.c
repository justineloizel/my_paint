/*
** EPITECH PROJECT, 2023
** B-MUL-200-REN-2-1-mypaint-tom.lefoix
** File description:
** brush_circle.c
*/

#include "paint.h"

static void complete_filled_circle(board_t *board, int x, int y, int i)
{
    double distance;
    for (int j = y - board->size; j <= y + board->size; j++) {
        distance = sqrt((i - x) * (i - x) + (j - y) * (j - y));
        if (distance <= (double) board->size) {
            put_pixel(board->actual_layer, i, j, board->color);
        }
    }
}

void draw_filled_circle(board_t *board, sfVector2i center)
{
    int x = center.x;
    int y = center.y;
    double dist;

    for (int i = x - board->size; i <= x + board->size; i++) {
        complete_filled_circle(board, x, y, i);
    }
}

void draw_circle(board_t *board, sfVector2i position)
{
    int r = board->size;
    int x1;
    int y1, angle;
    for (int i = 1; i < 360; i += 5) {
        angle = i;
        x1 = r * (int)cos(angle * M_PI / 180);
        y1 = r * (int)sin(angle * M_PI / 180);
        put_pixel(board->actual_layer, position.x + x1,
        position.y + y1, board->color);
    }
}
