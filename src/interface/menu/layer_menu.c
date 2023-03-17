/*
** EPITECH PROJECT, 2022
** B-MUL-200-REN-2-1-mypaint-tom.lefoix
** File description:
** layer_menu.c
*/

#include "paint.h"

void layer_plus(void *storage, int id)
{
    add_layer(((main_t *)storage)->board->layerList, NULL);
    ((main_t *)storage)->board->actual_layer = ((main_t *)storage)->board->layerList->tail;
}

void layer_less(void *storage, int id)
{
    manager_delete_layer(((main_t *)storage), 0);
}