/*
** EPITECH PROJECT, 2023
** B-MUL-200-REN-2-1-mypaint-tom.lefoix
** File description:
** manager_button.c
*/

#include "paint.h"
#include "myprintf.h"

void is_hover(button_t *button, sfRenderWindow *window)
{
    sfVector2f pos = sfSprite_getPosition(button->sprite);
    sfVector2f pos_mouse = sfRenderWindow_mapPixelToCoords(window,
    sfMouse_getPositionRenderWindow(window),sfRenderWindow_getView(window));
    sfVector2f size = {sfSprite_getLocalBounds(button->sprite).width,
    sfSprite_getGlobalBounds(button->sprite).height};
    sfVector2u screen_size = sfRenderWindow_getSize(window);
    sfVector2f scale = {button->scale.x / ((float)screen_size.x / 1920),
    button->scale.y / ((float)screen_size.y / 1080)};
    if ((pos_mouse.x > pos.x && pos_mouse.x < (pos.x + size.x * scale.x)) &&
        (pos_mouse.y > pos.y && pos_mouse.y < (pos.y + size.y * scale.y))) {
        sfSprite_setTextureRect(button->sprite, button->rec_hover);
        return;
    }
    sfSprite_setTextureRect(button->sprite, button->rec);
}

void is_click(sfMouseButtonEvent event, main_t *storage, button_t *button)
{
    sfVector2f size = {(float)sfSprite_getTextureRect(button->sprite).width,\
    (float)sfSprite_getTextureRect(button->sprite).height};
    sfVector2f clic = sfRenderWindow_mapPixelToCoords(WINDOW.window,\
    (sfVector2i){event.x, event.y}, sfRenderWindow_getView(WINDOW.window));
    sfVector2f pos = {sfSprite_getPosition(button->sprite).x,\
    sfSprite_getPosition(button->sprite).y};
    sfVector2u screen_size = sfRenderWindow_getSize(WINDOW.window);
    sfVector2f scale = {button->scale.x / ((float)screen_size.x / 1920),
    button->scale.y / ((float)screen_size.y / 1080)};
    if (IS_CLICk && button->fct != NULL) {
        sfSprite_setTextureRect(button->sprite, button->rec_click);
        sfRenderWindow_drawSprite(WINDOW.window, button->sprite, NULL);
        button->fct(storage, button->menu_id);
    }
    if (button->next == NULL || button == NULL)
        return;
    is_click(event, storage, button->next);
}

void print_list_button(list_button_t *list, sfRenderWindow *window)
{
    button_t *button = list->head;
    for (; button != NULL; button = button->next) {
        is_hover(button, window);
        sfSprite_setPosition(button->sprite, button->pos);
        sfRenderWindow_drawSprite(window, button->sprite, NULL);
    }

}

void recalcul_pos_button(sfVector2u size, button_t *button)
{
    sfVector2f new_position;
    for (; button != NULL; button = button->next) {
        new_position = button->pos;
        new_position.x *= ((float)size.x / 1920);
        new_position.y *= ((float)size.y / 1080);
        sfSprite_setPosition(button->sprite, new_position);
        sfSprite_setScale(button->sprite, (sfVector2f)
        {button->scale.x / ((float)size.x / 1920),
        button->scale.y / ((float)size.y / 1080)});
    }
}

void recalcul_position_menu(main_t *storage)
{
    sfVector2u screen_size = sfRenderWindow_getSize(storage->window.window);
    menu_t *menu = storage->list_menu->head;
    WINDOW.view = sfView_createFromRect((sfFloatRect){0, 0,
    (float)screen_size.x, (float)screen_size.y});

    sfRenderWindow_setView(WINDOW.window, (sfView const *)WINDOW.view);
}

//    for (; menu != NULL; menu = menu->next) {
//        recalcul_pos_button(screen_size, menu->menu_button);
//        recalcul_pos_button(screen_size, menu->button_list->head);
//    }
