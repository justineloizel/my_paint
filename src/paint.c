/*
** EPITECH PROJECT, 2022
** B-MUL-200-REN-2-1-mypaint-tom.lefoix
** File description:
** paint.c
*/


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
    }
}

int main(void)
{
    main_t storage = {init_window(), create_base_menu()};
    sfEvent event;
    add_button_in_his_menu(storage.list_menu);
    storage.list_menu->list_menu = add_visible_menu(\
    storage.list_menu->list_menu, 1);
    while (sfRenderWindow_isOpen(storage.window.window)) {
        sfRenderWindow_clear(storage.window.window, sfBlack);
        event_manager(event, &storage);
        print_button_menu(storage.list_menu, storage.window.window);
        sfRenderWindow_display(storage.window.window);
    }
    free_window(&(storage.window));
    return 0;
}
