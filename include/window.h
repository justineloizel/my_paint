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
    sfIntRect pen_dim;
    sfSprite *eraser;
    sfTexture *eraser_texture;
    sfVector2f eraser_pos;
    sfIntRect eraser_dim;
    sfSprite *manual;
    sfTexture *manual_texture;
    sfVector2f manual_pos;
    sfSprite *about;
    sfTexture *about_texture;
    sfVector2f about_pos;
    sfVideoMode mode;
    sfClock *clock;
    int cursor;
    int pop_up;
    sfView const *view;
}window_t;
window_t init_window(void);
void free_window(window_t *window);
#endif /*WINDOW_H_*/
