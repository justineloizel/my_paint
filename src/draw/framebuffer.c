/*
** EPITECH PROJECT, 2023
** B-MUL-200-REN-2-1-mypaint-tom.lefoix
** File description:
** framebuffer.c
*/

#include "paint.h"

void board_destroy(board_t *board)
{
    while (board->layerList->head != NULL) {
        delete_layer(board->layerList, board->layerList->head);
    }
    sfRectangleShape_destroy(board->board);
    sfClock_destroy(board->clock);
    free(board);
}

static void set_framebuffer(framebuffer_t *framebuffer)
{
    sfSprite_setTexture(framebuffer->sprite, framebuffer->texture, sfTrue);
    sfSprite_setPosition(framebuffer->sprite, (sfVector2f){0, 0});
    sfTexture_updateFromPixels(framebuffer->texture, framebuffer->pixels,
    1920, 1080, 0, 0);
    framebuffer->next = NULL;
    framebuffer->prev = NULL;
}

framebuffer_t *framebuffer_create(unsigned int width, unsigned int height)
{
    framebuffer_t *framebuffer;

    framebuffer = malloc(sizeof(framebuffer_t));
    if (framebuffer == NULL)
        return (NULL);
    framebuffer->pixels = malloc((sizeof(sfUint8)) * ((width * height) * 4));
    if (framebuffer->pixels == NULL) {
        return (NULL);
    }
    framebuffer->width = width;
    framebuffer->height = height;
    framebuffer->texture = sfTexture_create(width, height);
    framebuffer->sprite = sfSprite_create();
    if (framebuffer->texture == NULL || framebuffer->sprite == NULL) {
        return (NULL);
    }
    return (framebuffer);
}

board_t *board_create(unsigned int width, unsigned int height)
{
    board_t *board = malloc(sizeof(board_t));

    board->layerList = init_layer();
    if (board->layerList == NULL)
        return NULL;
    board->actual_layer = board->layerList->head;
    board->color = sfCyan;
    board->board = sfRectangleShape_create();
    board->clock = sfClock_create();
    if (board->actual_layer == NULL || board->board == NULL
        || board->clock == NULL)
        return (NULL);
    board->size = 10;
    sfRectangleShape_setFillColor(board->board, sfWhite);
    sfRectangleShape_setSize(board->board, (sfVector2f){1280, 830});
    sfRectangleShape_setPosition(board->board, (sfVector2f){600,150});
    return (board);
}
