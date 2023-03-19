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

void mask_layer(void *storage, UNUSED int id)
{
    if (((main_t *)storage)->board->actual_layer != NULL) {
        if (((main_t *)storage)->board->actual_layer->is_visible == 1) {
            ((main_t *)storage)->board->actual_layer->is_visible = 0;
        } else {
            ((main_t *)storage)->board->actual_layer->is_visible = 1;
        }
    }
    // 2 menu buttons (comme pencil mais par défault, menu visible affiché)
    // 2 menus affichés au même endroit l'un par dessus l'autre
    // si 1 = visible --> add menu visible et delete menu masked
    // si 0 = masked --> add menu masked et delete menu visible
}
