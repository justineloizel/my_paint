/*
** EPITECH PROJECT, 2023
** B-MUL-200-REN-2-1-mypaint-tom.lefoix
** File description:
** button.h
*/
#ifndef BUTTON_H_
    #define BUTTON_H_
    #define ARRLEN(X) (sizeof(X) / sizeof(X[0]))
    #include <SFML/Audio.h>
    #include <SFML/Graphics.h>
    #include <stdio.h>
    #include <stdlib.h>
    #include <unistd.h>
    #include <time.h>
    #include <math.h>

typedef struct button_store {
    int menu_id;
    char *filepath;
    sfVector2f pos;
    sfVector2f scale;
    sfIntRect rec;
    sfIntRect rec_hover;
    sfIntRect rec_click;
    void (*fct)(void *, int);
}button_store_t;

typedef struct button {
    sfTexture *texture;
    sfSprite *sprite;
    int menu_id;
    sfVector2f pos;
    sfVector2f scale;
    sfIntRect rec;
    sfIntRect rec_hover;
    sfIntRect rec_click;
    void (*fct)(void *, int);
    struct button *next;
    struct button *prev;
}button_t;

typedef struct list_button {
    button_t *head;
    button_t *tail;
}list_button_t;
//Function
button_t *init_button(button_store_t data);
void print_list_button(list_button_t *list, sfRenderWindow *window);
void is_hover(button_t *button, sfRenderWindow *window);
#endif /*BUTTON_H_*/
