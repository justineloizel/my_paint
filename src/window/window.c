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

static void init_pop_ups(window_t *window)
{
    window->cursor = 0;
    window->pop_up = 0;
    sfSprite_setTexture(window->pencil, window->pen_texture, sfTrue);
    window->eraser = sfSprite_create();
    window->eraser_texture = sfTexture_createFromFile("assets/gomme.png", NULL);
    sfSprite_setTexture(window->eraser, window->eraser_texture, sfTrue);
    window->manual = sfSprite_create();
    window->manual_texture = sfTexture_createFromFile("assets/manual_pop_up.png", NULL);
    sfSprite_setTexture(window->manual, window->manual_texture, sfTrue);
    window->manual_pos.x = 550;
    window->manual_pos.y = 100;
    sfSprite_setPosition(window->manual, window->manual_pos);
    window->about = sfSprite_create();
    window->about_texture = sfTexture_createFromFile("assets/about_pop_up.png", NULL);
    sfSprite_setTexture(window->about, window->about_texture, sfTrue);
    window->about_pos.x = 550;
    window->about_pos.y = 100;
    sfSprite_setPosition(window->about, window->about_pos);
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
    window.layer = sfSprite_create();
    window.layer_texture = sfTexture_createFromFile("assets/layers.png", NULL);
    sfSprite_setTexture(window.layer, window.layer_texture, sfTrue);
    window.layer_pos.x = 30;
    window.layer_pos.y = 850;
    sfSprite_setPosition(window.layer, window.layer_pos);
    init_pop_ups(&window);
    return window;
}

void free_window(window_t *window)
{
    sfClock_destroy(window->clock);
    sfRenderWindow_destroy(window->window);
}
