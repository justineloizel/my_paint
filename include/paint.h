/*
** EPITECH PROJECT, 2022
** B-MUL-200-REN-2-1-mypaint-tom.lefoix
** File description:
** paint.h
*/

#ifndef PAINT_H_
    #define PAINT_H_
    #include <SFML/Audio.h>
    #include <SFML/Graphics.h>
    #include <stdio.h>
    #include <stdlib.h>
    #include <unistd.h>
    #include <time.h>
    #include <math.h>
    #include "window.h"
    #include "menu.h"

    #define WINDOW storage->window
    #define MENU_LIST storage->list_menu

typedef struct main_s {
    window_t window;
    list_menu_t *list_menu;
}main_t;

int *add_visible_menu(int *actual_list, int menu);
int *delete_visible_menu(int *actual_list, int index);
menu_t *get_menu_by_id(int id, list_menu_t *list_menu);
list_menu_t *create_base_menu(void);
void add_button_in_his_menu(list_menu_t *list_menu);
void print_button_menu(list_menu_t *list_menu, sfRenderWindow *window);
void is_click(sfMouseButtonEvent event, main_t *storage, button_t *button);
void verify_menu_click(sfMouseButtonEvent event, main_t *storage);
void button_menu_is_clicked(void *storage, int id);
void recalcul_position_menu(main_t *storage);
#endif
