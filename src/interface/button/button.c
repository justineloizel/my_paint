/*
** EPITECH PROJECT, 2023
** B-MUL-200-REN-2-1-mypaint-tom.lefoix
** File description:
** button.c
*/

#include "paint.h"
#include "myprintf.h"

static const button_store_t button_list[] = {
        {1,"assets/newfile.png", {10, 39}, {1, 1}, {0, 0, 80, 32},\
        {0, 32, 80, 32}, {0, 64, 80, 32}, new_file},

        {1, "assets/openfile.png", {10, 68}, {1, 1}, {0, 0, 80, 32},\
        {0, 32, 80, 32}, {0, 64, 80, 32}, NULL},

        {1,"assets/savefile.png", {10, 97}, {1, 1}, {0, 0, 80, 32},\
        {0, 32, 80, 32}, {0, 64, 80, 32}, NULL},

        {2, "assets/pencil_but.png", {90, 39}, {1, 1}, {0, 0, 80, 32},\
        {0, 32, 80, 32}, {0, 64, 80, 32}, drawing_activated},

        {2,"assets/eraser.png", {90, 68}, {1, 1}, {0, 0, 80, 32},\
        {0, 32, 80, 32}, {0, 64, 80, 32}, eraser_activated},

        {3, "assets/about.png", {170, 39}, {1, 1}, {0, 0, 80, 32},\
        {0, 32, 80, 32}, {0, 64, 80, 32}, NULL},

        {3,"assets/help_help.png", {170, 68}, {1, 1}, {0, 0, 80, 32},\
        {0, 32, 80, 32}, {0, 64, 80, 32}, NULL},

};

void set_button(button_t *button)
{
    sfSprite_setTexture(button->sprite, button->texture, sfTrue);
    sfSprite_setPosition(button->sprite, button->pos);
    sfSprite_setScale(button->sprite, button->scale);
}

button_t *init_button(button_store_t data)
{
    button_t *button = malloc(sizeof(button_t));

    if (button == NULL || data.filepath == NULL)
        return NULL;
    button->texture = sfTexture_createFromFile(data.filepath, NULL);
    button->sprite = sfSprite_create();
    if (button->sprite == NULL || button->texture == NULL)
        return NULL;
    button->pos = data.pos;
    button->scale = data.scale;
    button->fct = data.fct;
    button->rec = data.rec;
    button->rec_hover = data.rec_hover;
    button->rec_click = data.rec_click;
    button->menu_id = data.menu_id;
    button->next = NULL;
    button->prev = NULL;
    set_button(button);
    return button;
}

void add_button(button_store_t data, list_button_t *button_list)
{
    if (button_list->head == NULL) {
        button_list->head = init_button(data);
        button_list->tail = button_list->head;
        return;
    }
    button_list->tail->next = init_button(data);
    if (button_list->tail->next == NULL)
        return;
    button_list->tail->next->prev = button_list->tail;
    button_list->tail = button_list->tail->next;
}

void add_button_in_his_menu(list_menu_t *list_menu)
{
    menu_t *menu;
    for (size_t i = 0; i < ARRLEN(button_list); i++) {
        menu = get_menu_by_id(button_list[i].menu_id, list_menu);
        if (menu != NULL)
            add_button(button_list[i], menu->button_list);
        else
            write(2, "Invalid menu_id button.\n", 24);
    }
}
