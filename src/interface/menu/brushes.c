/*
** EPITECH PROJECT, 2022
** B-MUL-200-REN-2-1-mypaint-tom.lefoix
** File description:
** brushes.c
*/

#include "paint.h"

void filled_square(void *storage, UNUSED int id)
{
    ((main_t *)storage)->board->tools = 3;
}

void filled_circle(void *storage, UNUSED int id)
{
    ((main_t *)storage)->board->tools = 0;
}

void filled_triangle(void *storage, UNUSED int id)
{
    ((main_t *)storage)->board->tools = 7;
}

void quit_paint(void *storage, int id)
{
    button_menu_is_clicked(storage, id);
    ((main_t *)storage)->window.pop_up = QUIT;
}
