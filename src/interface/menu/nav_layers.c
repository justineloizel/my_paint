/*
** EPITECH PROJECT, 2022
** B-MUL-200-REN-2-1-mypaint-tom.lefoix
** File description:
** nav_layers.c
*/

#include "paint.h"

void nav_top_layer(void *storage, UNUSED int id)
{
    if (((main_t *)storage)->board->actual_layer->next != NULL) {
        ((main_t *)storage)->board->actual_layer =
        ((main_t *)storage)->board->actual_layer->next;
    }
}

void nav_bottom_layer(void *storage, UNUSED int id)
{
    if (((main_t *)storage)->board->actual_layer->prev != NULL) {
        ((main_t *)storage)->board->actual_layer =
        ((main_t *)storage)->board->actual_layer->prev;
    }
}
