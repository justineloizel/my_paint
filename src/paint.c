/*
** EPITECH PROJECT, 2022
** B-MUL-200-REN-2-1-mypaint-tom.lefoix
** File description:
** paint.c
*/

#include "myprintf.h"
#include "paint.h"

void event_manager(sfEvent event, main_t *storage)
{
    while (sfRenderWindow_pollEvent(WINDOW.window, &event)) {
        if (event.type == sfEvtClosed || storage->window.pop_up == 3)
            sfRenderWindow_close(WINDOW.window);
        if (event.type == sfEvtKeyPressed && event.key.code == sfKeyEscape)
            sfRenderWindow_close(WINDOW.window);
        if (event.type == sfEvtMouseButtonPressed) {
            verify_menu_click(event.mouseButton, storage);
        }
        if (event.type == sfEvtResized) {
            recalcul_position_menu(storage);
        }
        if (event.type == sfEvtKeyPressed && event.key.code == sfKeyUp) {
            add_layer(storage->board->layerList, NULL);
            storage->board->actual_layer = storage->board->layerList->tail;
        }
        if (event.type == sfEvtKeyPressed && event.key.code == sfKeyDown) {
            manager_delete_layer(storage, 0);
        }
        if (event.type == sfEvtKeyPressed && event.key.code == sfKeyN) {
            add_layer(BOARD->layerList, "pokemon.jpg");
            BOARD->actual_layer = BOARD->layerList->tail;
        }
    }
}

static void display_pop_up(main_t *storage)
{
    if (storage->window.pop_up == 1) {
        sfRenderWindow_drawSprite(storage->window.window, storage->window.manual, NULL);
    }
    if (storage->window.pop_up == 2) {
        sfRenderWindow_drawSprite(storage->window.window, storage->window.about, NULL);
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
        if (storage->window.pop_up > 0)
            display_pop_up(storage);
        if (storage->window.cursor == 1)
            sfRenderWindow_drawSprite(storage->window.window, storage->palette->sprite, NULL);
        print_layer(storage);
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
