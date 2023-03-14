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
        if (event.type == sfEvtClosed )
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
            add_layer(storage->board->layerList);
            storage->board->actual_layer = storage->board->layerList->tail;
        }
        if (event.type == sfEvtKeyPressed && event.key.code == sfKeyDown) {
            storage->board->actual_layer = storage->board->layerList->tail->prev;
            delete_layer(storage->board->layerList,
            storage->board->layerList->tail);
        }
    }
}

void paint(main_t *storage)
{
    sfEvent event;
    while (sfRenderWindow_isOpen(storage->window.window)) {
        sfRenderWindow_clear(storage->window.window,
        (sfColor){47, 129, 121, 1});
        event_manager(event, storage);
        sfRenderWindow_drawRectangleShape(WINDOW.window, BOARD->board, NULL);
        // manage_draw(storage);
        print_layer(storage);
        print_button_menu(storage->list_menu, storage->window.window);
        if (storage->window.cursor > 0) {
            display_cursor(storage);
        }
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
