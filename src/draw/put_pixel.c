/*
** EPITECH PROJECT, 2022
** test graphic
** File description:
** test graphic
*/

#include "paint.h"

void board_destroy(board_t *board)
{
    free(board->fb->pixels);
    sfTexture_destroy(board->fb->texture);
    sfSprite_destroy(board->fb->sprite);
    sfClock_destroy(board->clock);
    free(board->fb);
    free(board);
}

static framebuffer_t *framebuffer_create(unsigned int width, unsigned int height)
{
    framebuffer_t *framebuffer;

    framebuffer = malloc(sizeof(framebuffer_t));
    if (framebuffer == NULL)
        return (NULL);
    framebuffer->pixels = malloc((sizeof(sfUint8)) * ((width * height) * 4));
    if (framebuffer->pixels == NULL)
        return (NULL);
    framebuffer->width = width;
    framebuffer->height = height;
    framebuffer->texture = sfTexture_create(width, height);
    framebuffer->sprite = sfSprite_create();
    if (framebuffer->texture == NULL || framebuffer->sprite == NULL)
        return (NULL);
    sfSprite_setTexture(framebuffer->sprite, framebuffer->texture, sfTrue);
    sfSprite_setPosition(framebuffer->sprite, (sfVector2f){0, 0});
    return (framebuffer);
}

board_t *board_create(unsigned int width, unsigned int height)
{
    board_t *board = malloc(sizeof(board_t));

    board->fb = framebuffer_create(width, height);
    board->color = sfCyan;
    board->board = sfRectangleShape_create();
    board->clock = sfClock_create();
    if (board->fb == NULL || board->board == NULL || board->clock == NULL)
        return (NULL);
    board->size = 10;
    sfRectangleShape_setFillColor(board->board, sfWhite);
    sfRectangleShape_setSize(board->board, (sfVector2f){1280, 830});
    sfRectangleShape_setPosition(board->board, (sfVector2f){600,150});
    return (board);
}

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

    //correction_draw(board, position);
    for (int i = 0; i < board->size; i++) {
        for (int j = 0; j < board->size; j++) {
            put_pixel(board->fb, position.x + j, position.y + i, board->color);
        }
    }
    sfTexture_updateFromPixels(board->fb->texture, board->fb->pixels,\
    1920, 1080, 0, 0);
    sfClock_restart(board->clock);
}
