/*
** EPITECH PROJECT, 2022
** B-MUL-200-REN-2-1-mypaint-tom.lefoix
** File description:
** paint.c
*/

#include "myprintf.h"
#include "paint.h"

void manage_event_bis(main_t *storage, sfEvent event)
{
    static float test = 1;

    if (event.type == sfEvtKeyPressed && event.key.code == sfKeyN) {
        add_layer(BOARD->layerList, "pokemon.jpg");
        BOARD->actual_layer = BOARD->layerList->tail;
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
        if (event.type == sfEvtResized) {
            recalcul_position_menu(storage);
        }
        manage_event_bis(storage, event);

    }
}

static void display_pop_up(main_t *storage)
{
    sfRenderWindow_drawSprite(storage->window.window, storage->window.layer,
    NULL);
    if (storage->window.pop_up == MANUAL) {
        sfRenderWindow_drawSprite(storage->window.window,
        storage->window.manual, NULL);
    }
    if (storage->window.pop_up == ABOUT) {
        sfRenderWindow_drawSprite(storage->window.window,
        storage->window.about, NULL);
    }
    if (storage->window.pop_up == SAVE) {
        sfRenderWindow_drawSprite(storage->window.window,
        storage->window.save_pop, NULL);
    }
}

void paint(main_t *storage)
{
    sfEvent event;
    while (sfRenderWindow_isOpen(storage->window.window)) {
        sfRenderWindow_clear(storage->window.window,
        (sfColor){62, 62, 62, 1});
        event_manager(event, storage);
        sfRenderWindow_drawRectangleShape(WINDOW.window, BOARD->board, NULL);
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
