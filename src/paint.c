/*
** EPITECH PROJECT, 2022
** B-MUL-200-REN-2-1-mypaint-tom.lefoix
** File description:
** paint.c
*/

#include "menu.h"
#include "window.h"
#include "myprintf.h"

void event_manager(sfEvent event, window_t *window, list_menu_t *menus)
{
    while (sfRenderWindow_pollEvent(window->window, &event)) {
        if (event.type == sfEvtClosed )
            sfRenderWindow_close(window->window);
        if (event.type == sfEvtKeyPressed && event.key.code == sfKeyEscape)
            sfRenderWindow_close(window->window);
        if (event.type == sfEvtMouseButtonPressed) {
            verify_menu_click(event.mouseButton, window, menus);
        }
    }
}

int main(void)
{
    window_t window = init_window();
    sfEvent event;
    list_menu_t *list_menu = create_base_menu();
    add_button_in_his_menu(list_menu);
    list_menu->list_menu = add_visible_menu(list_menu->list_menu, 1);
    while (sfRenderWindow_isOpen(window.window)) {
        sfRenderWindow_clear(window.window, sfBlack);
        event_manager(event, &window, list_menu);
        print_button_menu(list_menu, window.window);
        sfRenderWindow_display(window.window);
    }
    free_window(&window);
    return 0;
}
