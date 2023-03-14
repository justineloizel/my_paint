/*
** EPITECH PROJECT, 2022
** test graphic
** File description:
** test graphic
*/

#include <math.h>
#include "string.h"
#include "paint.h"

brush_store_t brush_list[] = {
        {draw_filled_circle},
        {draw_circle},
        {draw_square},
        {draw_filled_square},
        {draw_triangle},
        {draw_filled_triangle},
        {draw_triangle_reverse},
        {draw_triangle_reverse_filled},
};

void put_pixel(framebuffer_t *framebuffer, unsigned int x,
unsigned int y, sfColor color)
{
    size_t i = (framebuffer->width * y + x) * 4;
    if (i >= framebuffer->width * framebuffer->height * 4)
        return;
    framebuffer->pixels[i + 0] = color.r;
    framebuffer->pixels[i + 1] = color.g;
    framebuffer->pixels[i + 2] = color.b;
    framebuffer->pixels[i + 3] = color.a;
}

void fill_gap(board_t *board, sfVector2i start, sfVector2i end)
{
    sfVector2f vector = { (float)abs(end.x - start.x),
    (float)abs(end.y - start.y) };
    sfVector2f distance = {(start.x < end.x) ? 1 : -1,\
    (start.y < end.y) ? 1 : -1 };
    int err = (int)(vector.x - vector.y);
    int x = (int)start.x;
    int y = (int)start.y;
    int err2;
    while (x != (int)end.x || y != (int)end.y) {
        brush_list[board->tools].brush(board, (sfVector2i){x, y});
        err2 = 2 * err;
        if ((double)err2 > -vector.y) {
            err -= (int)vector.y;
            x += (int)distance.x;
        }
        if ((double)err2 < vector.x) {
            err += (int)vector.x;
            y += (int)distance.y;
        }
    }
}

void draw_object(board_t *board, sfVector2i position)
{
    static sfVector2i old_position = (sfVector2i){-1, -1};
    position.x -= (board->size / 2) + (int)POS_BOARD.x;
    position.y -= (board->size / 2) + (int)POS_BOARD.y;

    brush_list[board->tools].brush(board, position);
    if (sfTime_asSeconds(sfClock_getElapsedTime(board->clock)) < 0.05 && old_position.x != -1)
        fill_gap(board, old_position, position);

    sfTexture_updateFromPixels(board->actual_layer->texture,
    board->actual_layer->pixels,\
    SIZE_BOARD.x, SIZE_BOARD.y, 0, 0);
    sfClock_restart(board->clock);
    old_position = position;
}
