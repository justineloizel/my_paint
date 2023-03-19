/*
** EPITECH PROJECT, 2023
** B-MUL-200-REN-2-1-mypaint-tom.lefoix
** File description:
** window.h
*/
#ifndef WINDOW_H_
    #define WINDOW_H_
    #include <SFML/Audio.h>
    #include <SFML/Graphics.h>
    #include <stdio.h>
    #include <stdlib.h>
    #include <unistd.h>
    #include <time.h>
    #include <math.h>

typedef struct sprites_store {
    int id;
    char *filepath;
    sfVector2f pos;
} sprites_store_t;

typedef struct sprites {
    int id;
    sfSprite *sprite;
    sfTexture *texture;
    sfVector2f pos;
    struct sprites *next;
    struct sprites *prev;
} sprites_t;

typedef struct list_sprites {
    sprites_t *head;
    sprites_t *tail;
} list_sprites_t;

typedef struct window {
    sfRenderWindow *window;
    sfSprite *pencil;
    sfTexture *pen_texture;
    sfVector2f pen_pos;
    sfSprite *eraser;
    sfTexture *eraser_texture;
    sfVector2f eraser_pos;
    sfVideoMode mode;
    sfClock *clock;
    int cursor;
    int pop_up;
    int pen;
    list_sprites_t *sprites
    sfView *view;
} window_t;

window_t init_window(void);
void free_window(window_t *window);
list_sprites_t *create_sprites(void);
sprites_t *get_sprite(list_sprites_t *list, int id);
#endif /*WINDOW_H_*/
