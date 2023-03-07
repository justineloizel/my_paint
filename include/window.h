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
    sfVideoMode mode;
    sfClock *clock;
}window_t;
window_t init_window(void);
void free_window(window_t *window);
#endif /*WINDOW_H_*/
