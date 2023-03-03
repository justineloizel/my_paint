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

typedef struct window {
        char *name;
        sfRenderWindow *window;
        sfVideoMode mode;
        sfTexture *texture;
        sfSprite *sprite;
} window_t;

typedef struct entity {
        sfTexture *texture;
        sfSprite *sprite;
        sfVector2f pos;
        sfVector2f scale;
        sfIntRect rec;
        struct entity *next;
} entity_t;

typedef struct button {
        sfTexture *texture;
        sfSprite *sprite;
        sfVector2f pos;
        sfVector2f scale;
        sfIntRect none;
        sfIntRect hover;
        sfIntRect clicked;
        int menu;
        int is_valid;
        void (*fct)(window_t *, struct button *, entity_t *);
        struct button *next;
} button_t;

typedef struct list_but {
        char *filepath;
        int menu;
        sfIntRect rec;
        sfIntRect rec_above;
        sfIntRect rec_clic;
        sfVector2f pos;
        sfVector2f scale;
        void (*fct)(window_t *, button_t *, entity_t *);
} list_but_t;


#endif
