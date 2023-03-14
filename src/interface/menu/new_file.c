/*
** EPITECH PROJECT, 2022
** B-MUL-200-REN-2-1-mypaint-tom.lefoix
** File description:
** new_file.c
*/

#include "paint.h"

void new_file(void *storage, int id)
{
    ((main_t *)storage)->window.cursor = 0;
    button_menu_is_clicked(storage, id);
    board_destroy(((main_t *)storage)->board);
    ((main_t *)storage)->board = board_create(1920, 1080);
    add_layer(((main_t *)storage)->board->layerList, NULL);
    ((main_t *)storage)->board->actual_layer = ((main_t *)storage)->board->layerList->head;
}