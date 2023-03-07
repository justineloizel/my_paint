/*
** EPITECH PROJECT, 2023
** B-MUL-200-REN-2-1-mypaint-tom.lefoix
** File description:
** manager_button.c
*/

#include "window.h"
#include "menu.h"
#include "myprintf.h"

void is_hover(button_t *button, sfRenderWindow *window)
{
    sfVector2f pos = sfSprite_getPosition(button->sprite);
    sfVector2i pos_mouse = sfMouse_getPositionRenderWindow(window);
    sfVector2f size = {sfSprite_getGlobalBounds(button->sprite).width,\
    sfSprite_getGlobalBounds(button->sprite).height};
    if ((pos_mouse.x > pos.x && pos_mouse.x < (pos.x + size.x)) &&
        (pos_mouse.y > pos.y && pos_mouse.y < (pos.y + size.y))) {
        sfSprite_setTextureRect(button->sprite, button->rec_hover);
        return;
    }
    sfSprite_setTextureRect(button->sprite, button->rec);
}

void is_click(sfMouseButtonEvent event, void *window, button_t *button,
list_menu_t *list_menu)
{
    sfVector2f size = {sfSprite_getLocalBounds(button->sprite).width,\
    sfSprite_getLocalBounds(button->sprite).height};
    sfVector2f clic = {(float)event.x, (float)event.y};
    sfVector2f pos = {sfSprite_getPosition(button->sprite).x,\
    sfSprite_getPosition(button->sprite).y};
    if (clic.x > pos.x && clic.x < (pos.x + size.x) && clic.y > pos.y &&
        clic.y < (pos.y + size.y) && button->fct != NULL) {
        button->fct(list_menu, button->menu_id);
    }
    if (button->next == NULL)
        return;
    is_click(event, window, button->next, list_menu);
}

void print_list_button(list_button_t *list, sfRenderWindow *window)
{
    button_t *button = list->head;
    for (; button != NULL; button = button->next) {
        is_hover(button, window);
        sfRenderWindow_drawSprite(window, button->sprite, NULL);
    }
}
