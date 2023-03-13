/*
** EPITECH PROJECT, 2023
** B-MUL-200-REN-2-1-mypaint-tom.lefoix
** File description:
** window.c
*/

#include "paint.h"

sfVector2f get_valid_position(main_t *storage, sfVector2f position)
{
    position = sfRenderWindow_mapPixelToCoords(WINDOW.window,\
    V2F_V2I(position), WINDOW.view);
    return position;
}

window_t init_window(void)
{
    window_t window;
    window.mode = (sfVideoMode){1920, 1080, 32};
    window.window = sfRenderWindow_create(window.mode, "My Paint",
                                        sfDefaultStyle, NULL);
    window.clock = sfClock_create();
    window.view = sfRenderWindow_getView(window.window);
    sfRenderWindow_setFramerateLimit(window.window, 40);
    sfRenderWindow_setMouseCursorVisible(window.window, 1);
    window.pencil = sfSprite_create();
    window.pen_texture = sfTexture_createFromFile("assets/pen.png", NULL);
    window.cursor = 0;
    sfSprite_setTexture(window.pencil, window.pen_texture, sfTrue);
    return window;
}

void free_window(window_t *window)
{
    sfClock_destroy(window->clock);
    sfRenderWindow_destroy(window->window);
}
