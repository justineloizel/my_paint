/*
** EPITECH PROJECT, 2023
** B-MUL-200-REN-2-1-mypaint-tom.lefoix
** File description:
** button.c
*/

#include "paint.h"
#include "myprintf.h"

static const button_store_t button_list[] = {
        {FILE_MENU,"assets/new_file.png", {0, 43}, {1, 1}, {0, 0, 160, 40},\
        {0, 43, 160, 43}, {0, 0, 160, 40}, new_file},

        {FILE_MENU, "assets/open_file.png", {0, 86}, {1, 1}, {0, 0, 160, 40},\
        {0, 43, 160, 43}, {0, 0, 160, 40}, NULL},

        {FILE_MENU,"assets/save_file.png", {0, 129}, {1, 1}, {0, 0, 160, 40},\
        {0, 43, 160, 43}, {0, 0, 160, 40}, save_file},

        {EDIT, "assets/pencil.png", {160, 43}, {1, 1}, {0, 0, 160, 40},\
        {0, 43, 160, 43}, {0, 0, 160, 40}, drawing_activated},

        {EDIT,"assets/eraser.png", {160, 86}, {1, 1}, {0, 0, 160, 40},\
        {0, 43, 160, 43}, {0, 0, 160, 40}, eraser_activated},

        {HELP, "assets/about.png", {320, 43}, {1, 1}, {0, 0, 160, 40},\
        {0, 43, 160, 43}, {0, 0, 160, 40}, display_about},

        {HELP,"assets/manual.png", {320, 86}, {1, 1}, {0, 0, 160, 40},\
        {0, 43, 160, 43}, {0, 0, 160, 40}, display_manual},

        {POP_TOOL,"assets/Ok.png", {1100, 700}, {1, 1}, {0, 0, 160, 40},\
        {0, 43, 160, 43}, {0, 0, 160, 40}, quit_manual},

        {POP_TOOL,"assets/error.png", {1680, 180}, {1, 1}, {0, 0, 40, 40},\
        {0, 43, 40, 43}, {0, 0, 40, 40}, quit_manual},

        {PENCIL_TOOL,"assets/filled_square.png", {80, 350}, {1, 1},\
        {0, 0, 40, 40}, {0, 43, 40, 43}, {0, 86, 40, 43}, filled_square},

        {PENCIL_TOOL,"assets/filled_circle.png", {180, 350}, {1, 1},\
        {0, 0, 40, 40}, {0, 43, 40, 43}, {0, 86, 40, 43}, filled_circle},

        {PENCIL_TOOL,"assets/filled_triangle.png", {280, 350}, {1, 1},\
        {0, 0, 40, 40}, {0, 43, 40, 43}, {0, 86, 40, 43}, filled_triangle},

        {SAVE_POP,"assets/jpg_button.png", {800, 400}, {1, 1},\
        {0, 0, 160, 40}, {0, 43, 160, 43}, {0, 86, 160, 43}, save_file_jpg},

        {SAVE_POP,"assets/png_button.png", {1000, 400}, {1, 1},\
        {0, 0, 160, 40}, {0, 43, 160, 43}, {0, 86, 160, 43}, save_file_png},

        {SAVE_POP,"assets/bmp_button.png", {1200, 400}, {1, 1},\
        {0, 0, 160, 40}, {0, 43, 160, 43}, {0, 86, 160, 43}, save_file_bmp},


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
