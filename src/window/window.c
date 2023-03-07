/*
** EPITECH PROJECT, 2023
** B-MUL-200-REN-2-1-mypaint-tom.lefoix
** File description:
** window.c
*/

#include "window.h"

window_t init_window(void)
{
    window_t window;
    window.mode = (sfVideoMode){1920, 1080, 32};
    window.window = sfRenderWindow_create(window.mode, "My Paint",
                                        sfDefaultStyle, NULL);
    window.clock = sfClock_create();
    sfRenderWindow_setFramerateLimit(window.window, 40);
    sfRenderWindow_setMouseCursorVisible(window.window, 1);
    return window;
}

void free_window(window_t *window)
{
    sfClock_destroy(window->clock);
    sfRenderWindow_destroy(window->window);
}
