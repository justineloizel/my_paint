/*
** EPITECH PROJECT, 2023
** B-MUL-200-REN-2-1-mypaint-tom.lefoix
** File description:
** paint.c
*/

#include "myprintf.h"
#include "paint.h"

static void manage_event_bis(main_t *storage, sfEvent event)
{
    if (event.type == sfEvtKeyPressed && event.key.code == sfKeyDown)
        zoom_out(storage);
    if (event.type == sfEvtKeyPressed && event.key.code == sfKeyUp)
        zoom_in(storage);
    if (event.type == sfEvtKeyPressed && event.key.code == sfKeyR) {
        storage->board->nb_zoom = 0;
        sfView_reset(BOARD->view, REC_BOARD);
    }
}

void event_manager(sfEvent event, main_t *storage)
{
    while (sfRenderWindow_pollEvent(WINDOW.window, &event)) {
        if (event.type == sfEvtClosed || storage->window.pop_up == QUIT)
            sfRenderWindow_close(WINDOW.window);
        if (event.type == sfEvtKeyPressed && event.key.code == sfKeyEscape)
            sfRenderWindow_close(WINDOW.window);
        if (event.type == sfEvtMouseButtonPressed) {
            verify_menu_click(event.mouseButton, storage);
        }
        if (event.type == sfEvtResized)
            recalcul_position_menu(storage);
        manage_event_bis(storage, event);
    }
}

static void display_pop_up(main_t *storage)
{
    sprites_t *sprite = get_sprite(storage->window.sprites, MANUAL_SPRITE);
    if (storage->window.pop_up == MANUAL) {
        sfRenderWindow_drawSprite(storage->window.window,
        sprite->sprite, NULL);
    }
    if (storage->window.pop_up == ABOUT) {
        sprite = get_sprite(storage->window.sprites, ABOUT_SPRITE);
        sfRenderWindow_drawSprite(storage->window.window,
        sprite->sprite, NULL);
    }
    if (storage->window.pop_up == SAVE) {
        sprite = get_sprite(storage->window.sprites, SAVE_SPRITE);
        sfRenderWindow_drawSprite(storage->window.window,
        sprite->sprite, NULL);
    }
    if (storage->window.pop_up == OPEN) {
        sprite = get_sprite(storage->window.sprites, OPEN_SPRITE);
        sfRenderWindow_drawSprite(storage->window.window,
        sprite->sprite, NULL);
    }
}

void paint(main_t *storage)
{
    sfEvent event;
    while (sfRenderWindow_isOpen(storage->window.window)) {
        sfRenderWindow_clear(storage->window.window, BACKGROUND_COLOR);
        event_manager(event, storage);
        if (storage->window.cursor == PENCIL)
            sfRenderWindow_drawSprite(storage->window.window,
            storage->palette->sprite, NULL);
        print_layer(storage);
        if (storage->window.pop_up > 0)
            display_pop_up(storage);
        print_button_menu(storage->list_menu, storage->window.window);
        if (storage->window.cursor > 0)
            display_cursor(storage);
        else
            sfRenderWindow_setMouseCursorVisible(storage->window.window, 1);
        sfRenderWindow_display(storage->window.window);
        check_if_open_file(storage);
    }
}

int main(void)
{
    main_t *storage = init_storage();
    if (storage == NULL)
        return 84;
    paint(storage);
    destroy_storage(storage);
    return 0;
}
