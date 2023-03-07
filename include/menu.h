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

#endif /*MENU_H_*/
