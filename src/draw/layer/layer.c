/*
** EPITECH PROJECT, 2023
** B-MUL-200-REN-2-1-mypaint-tom.lefoix
** File description:
** layer.c
*/
#include "paint.h"
#include "layer.h"

void add_layer(layer_list_t *list, char *filepath)
{
    if (list->head == NULL) {
        if (filepath == NULL)
            list->head = framebuffer_create(SIZE_BOARD.x, SIZE_BOARD.y);
        if (filepath != NULL)
            list->head = framebuffer_from_image(SIZE_BOARD.x, SIZE_BOARD.y, filepath);
        list->tail = list->head;
        list->nb_layer += 1;
        return;
    }
    if (filepath == NULL)
        list->tail->next = framebuffer_create(SIZE_BOARD.x, SIZE_BOARD.y);
    else
        list->tail->next = framebuffer_from_image(SIZE_BOARD.x, SIZE_BOARD.y, filepath);

    if (list->tail->next == NULL)
        return;
    list->tail->next->prev = list->tail;
    list->tail = list->tail->next;
    list->nb_layer += 1;
}

layer_list_t *init_layer(void)
{
    layer_list_t *layer_list = malloc(sizeof(layer_list_t));

    if (layer_list == NULL)
        return NULL;
    layer_list->head = NULL;
    layer_list->tail = NULL;
    layer_list->nb_layer = 0;
    add_layer(layer_list, NULL);
    if (layer_list->head == NULL)
        return NULL;
    return layer_list;
}

void delete_layer(layer_list_t *layer_list, framebuffer_t *target)
{
    framebuffer_t *tmp = layer_list->head;

    for (; tmp != NULL && tmp != target; tmp = tmp->next);
    if (tmp == NULL)
        return;
    if (layer_list->head == tmp)
        layer_list->head = tmp ->next;
    if (layer_list->tail == tmp)
        layer_list->tail = tmp->prev;
    if (tmp->prev != NULL)
        tmp->prev->next = tmp->next;
    if (tmp->next != NULL)
        tmp->next->prev = tmp->prev;
    layer_list->nb_layer -= 1;
    delete_framebuffer(tmp);
}

void print_layer(main_t *storage)
{
    framebuffer_t *fb = storage->board->layerList->head;

    if (fb == NULL)
        return;

    for (; fb != NULL; fb = fb->next)
        sfRenderWindow_drawSprite(storage->window.window, fb->sprite, NULL);
}
