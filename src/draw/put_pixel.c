/*
** EPITECH PROJECT, 2022
** test graphic
** File description:
** test graphic
*/

#include "string.h"
#include "paint.h"

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

void draw_object(board_t *board, sfVector2i position)
{
    position.x -= board->size / 2;
    position.y -= board->size / 2;

    for (int i = 0; i < board->size; i++) {
        for (int j = 0; j < board->size; j++) {
            put_pixel(board->actual_layer, position.x + j, position.y + i,
            board->color);
        }
    }
    sfTexture_updateFromPixels(board->actual_layer->texture,
    board->actual_layer->pixels,\
    1920, 1080, 0, 0);
    sfClock_restart(board->clock);
}
