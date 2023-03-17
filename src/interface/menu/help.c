/*
** EPITECH PROJECT, 2022
** B-MUL-200-REN-2-1-mypaint-tom.lefoix
** File description:
** help.c
*/

#include "paint.h"

void display_about(void *storage, int id)
{
    button_menu_is_clicked(storage, id);
    ((main_t *)storage)->window.pop_up = 2;
    ((main_t *)storage)->list_menu->list_menu = add_visible_menu(((main_t *)storage)->list_menu->list_menu, 4);
}

void display_manual(void *storage, int id)
{
    button_menu_is_clicked(storage, id);
    ((main_t *)storage)->window.pop_up = 1;
    ((main_t *)storage)->list_menu->list_menu = add_visible_menu(((main_t *)storage)->list_menu->list_menu, 4);

}

void quit_manual(void *storage, int id)
{
    button_menu_is_clicked(storage, id);
    ((main_t *)storage)->window.pop_up = 0;

}