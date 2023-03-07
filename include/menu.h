/*
** EPITECH PROJECT, 2023
** B-MUL-200-REN-2-1-mypaint-tom.lefoix
** File description:
** menu.h
*/
#ifndef MENU_H_
    #define MENU_H_
    #include "button.h"

typedef struct menu_store {
    int id;
    button_store_t button;
} menu_store_t;

typedef struct menu {
    int id;
    button_t *menu_button;
    list_button_t *button_list;
    struct menu *next;
    struct menu *prev;
}menu_t;

typedef struct list_menu {
    menu_t *head;
    menu_t *tail;
    int *list_menu;
}list_menu_t;


int *add_visible_menu(int *actual_list, int menu);
int *delete_visible_menu(int *actual_list, int index);
menu_t *get_menu_by_id(int id, list_menu_t *list_menu);
list_menu_t *create_base_menu(void);
void add_button_in_his_menu(list_menu_t *list_menu);
void print_button_menu(list_menu_t *list_menu, sfRenderWindow *window);
void is_click(sfMouseButtonEvent event, void *window, button_t *button,\
list_menu_t *list_menu);
void verify_menu_click(sfMouseButtonEvent event, void *window,\
list_menu_t *menu_list);
void button_menu_is_clicked(void *standby, int id);
#endif /*MENU_H_*/
