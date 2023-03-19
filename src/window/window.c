/*
** EPITECH PROJECT, 2023
** B-MUL-200-REN-2-1-mypaint-tom.lefoix
** File description:
** window.c
*/

#include "paint.h"

sfVector2f get_valid_position(main_t *storage, sfVector2f position, int view)
{
    if (view == 0)
        position = sfRenderWindow_mapPixelToCoords(WINDOW.window,\
        V2F_V2I(position), WINDOW.view);
    if (view == 1)
        position = sfRenderWindow_mapPixelToCoords(WINDOW.window,\
        V2F_V2I(position), BOARD->view);
    return position;
}

static void init_bis(window_t *window)
{
    window->cursor = 0;
    window->pop_up = 0;
    window->pen = 0;
    sfSprite_setTexture(window->pencil, window->pen_texture, sfTrue);
    window->eraser = sfSprite_create();
    window->eraser_texture = sfTexture_createFromFile("assets/gomme.png", NULL);
    sfSprite_setTexture(window->eraser, window->eraser_texture, sfTrue);
}

window_t init_window(void)
{
    window_t window;
    window.mode = (sfVideoMode){1920, 1080, 32};
    window.window = sfRenderWindow_create(window.mode, "My Paint",
                                        sfDefaultStyle, NULL);
    window.clock = sfClock_create();
    window.view = (sfView *)sfRenderWindow_getView(window.window);
    sfRenderWindow_setFramerateLimit(window.window, 40);
    sfRenderWindow_setMouseCursorVisible(window.window, 1);
    window.pencil = sfSprite_create();
    window.pen_texture = sfTexture_createFromFile("assets/pen.png", NULL);
    init_bis(&window);
    window.sprites = create_sprites();
    return window;
}

void free_window(window_t *window)
{
    sfClock_destroy(window->clock);
    sfRenderWindow_destroy(window->window);
}
