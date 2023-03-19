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
    sfSprite *manual;
    sfTexture *manual_texture;
    sfVector2f manual_pos;
    sfSprite *about;
    sfTexture *about_texture;
    sfVector2f about_pos;
    sfSprite *layer;
    sfTexture *layer_texture;
    sfVector2f layer_pos;
    sfSprite *shape;
    sfTexture *shape_texture;
    sfVector2f shape_pos;
    sfSprite *save_pop;
    sfTexture *save_texture;
    sfVector2f save_pos;
    sfSprite *open_pop;
    sfTexture *open_texture;
    sfVector2f open_pos;
    sfSprite *thickness;
    sfTexture *thick_texture;
    sfVector2f thick_pos;
    sfVideoMode mode;
    sfClock *clock;
    int cursor;
    int pop_up;
    int pen;
    sfView const *view;
    list_sprites_t *sprites;
} window_t;

window_t init_window(void);
void free_window(window_t *window);
list_sprites_t *create_sprites(void);
sprites_t *get_sprite(list_sprites_t *list, int id);
#endif /*WINDOW_H_*/
