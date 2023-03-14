/*
** EPITECH PROJECT, 2023
** B-MUL-200-REN-2-1-mypaint-tom.lefoix
** File description:
** layer_manager.c
*/

#include "paint.h"

void manager_delete_layer(main_t *storage, UNUSED int id)
{
    framebuffer_t *actual = BOARD->actual_layer;
    if (BOARD->actual_layer != BOARD->layerList->head)
        storage->board->actual_layer = BOARD->actual_layer->prev;
    else
        storage->board->actual_layer = BOARD->actual_layer->next;

    delete_layer(storage->board->layerList,actual);
    if (BOARD->layerList->head == NULL) {
        add_layer(BOARD->layerList, NULL);
        BOARD->actual_layer = BOARD->layerList->head;
    }
}
