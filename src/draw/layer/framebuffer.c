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
    free(board->layerList);
    sfView_destroy(board->view);
    free(board);
}

void set_framebuffer(framebuffer_t *framebuffer, unsigned int width,
unsigned int height, int fill_fb)
{
    if (fill_fb)
        fill_framebuffer(framebuffer, sfTransparent);
    framebuffer->is_visible = 1;
    sfSprite_setTexture(framebuffer->sprite, framebuffer->texture, sfTrue);
    sfSprite_setPosition(framebuffer->sprite, POS_BOARD);
    sfTexture_updateFromPixels(framebuffer->texture, framebuffer->pixels,
    width, height, 0, 0);
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
    if (framebuffer->texture == NULL || framebuffer->sprite == NULL)
        return (NULL);
    set_framebuffer(framebuffer, width, height, sfTrue);
    return (framebuffer);
}

static void set_board(board_t *board)
{
    sfView_setSize(board->view, SIZE_BOARD);
    sfView_setViewport(board->view, REC_VIEW_PORT);
    sfRectangleShape_setFillColor(board->board, sfWhite);
    sfRectangleShape_setSize(board->board, SIZE_BOARD);
    sfRectangleShape_setPosition(board->board, POS_BOARD);
}

board_t *board_create(UNUSED unsigned int width, UNUSED unsigned int height)
{
    board_t *board = malloc(sizeof(board_t));
    board->layerList = init_layer();
    if (board->layerList == NULL)
        return NULL;
    board->actual_layer = board->layerList->head;
    board->color = sfBlack;
    board->board = sfRectangleShape_create();
    board->clock = sfClock_create();
    board->view = sfView_createFromRect(REC_BOARD);
    if (board->actual_layer == NULL || board->board == NULL
        || board->clock == NULL || board->view == NULL)
        return (NULL);
    board->size = 10;
    board->tools = 0;
    board->nb_zoom = 0;
    set_board(board);
    return (board);
}
