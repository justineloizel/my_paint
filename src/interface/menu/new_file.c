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
    ((main_t *)storage)->board->actual_layer =
    ((main_t *)storage)->board->layerList->head;
}

void save_file(void *storage, int id)
{
    ((main_t *)storage)->window.pop_up = SAVE;
    ((main_t *)storage)->list_menu->list_menu =
    add_visible_menu(((main_t *)storage)->list_menu->list_menu, SAVE_POP);
    ((main_t *)storage)->list_menu->list_menu =
    add_visible_menu(((main_t *)storage)->list_menu->list_menu, POP_TOOL);
    button_menu_is_clicked(storage, id);
}

void save_file_jpg(void *storage, int id)
{
    save_drawing_to_jpg(((main_t *)storage), id);
    button_menu_is_clicked(storage, id);
}

void save_file_png(void *storage, int id)
{
    save_drawing_to_png(((main_t *)storage), id);
    button_menu_is_clicked(storage, id);
}

void save_file_bmp(void *storage, int id)
{
    save_drawing_to_bmp(((main_t *)storage), id);
    button_menu_is_clicked(storage, id);
}
