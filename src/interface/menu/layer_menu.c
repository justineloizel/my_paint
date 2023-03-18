/*
** EPITECH PROJECT, 2022
** B-MUL-200-REN-2-1-mypaint-tom.lefoix
** File description:
** layer_menu.c
*/

#include "paint.h"

void layer_plus(void *storage, UNUSED int id)
{
    add_layer(((main_t *)storage)->board->layerList, NULL);
    ((main_t *)storage)->board->actual_layer =
    ((main_t *)storage)->board->layerList->tail;
}

void layer_less(void *storage, UNUSED int id)
{
    manager_delete_layer(((main_t *)storage), 0);
}

void thicker_brush(void *storage, UNUSED int id)
{
    ((main_t *)storage)->board->size += 1;
}

void thinner_brush(void *storage, UNUSED int id)
{
    if (((main_t *)storage)->board->size == 1)
        return;
    ((main_t *)storage)->board->size -= 1;
}