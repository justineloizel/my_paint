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
    sfSprite *thickness;
    sfTexture *thick_texture;
    sfVector2f thick_pos;
    sfVideoMode mode;
    sfClock *clock;
    int cursor;
    int pop_up;
    int pen;
    sfView const *view;
}window_t;
window_t init_window(void);
void free_window(window_t *window);
#endif /*WINDOW_H_*/
