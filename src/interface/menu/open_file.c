/*
** EPITECH PROJECT, 2022
** B-MUL-200-REN-2-1-mypaint-tom.lefoix
** File description:
** open_file.c
*/

#include "paint.h"
#include "my.h"
#include "myprintf.h"


char *get_filepath(void)
{
    size_t len = 0;
    char *input = NULL;

    my_printf("Entrer le chemin et le nom du fichier (avec extension) :");
    if (getline(&input, &len, stdin) == -1)
        return NULL;
    input[my_strlen(input) - 1] = '\0';
    if (my_strlen(input) < 1) {
        free(input);
        return NULL;
    }
    return input;
}

void check_if_open_file(main_t *storage)
{
    char *filepath;
    list_menu_t *list_menus = storage->list_menu;
    int index = is_visible_menu(POP_TOOL, list_menus->list_menu);

    if (storage->window.pop_up == OPEN) {
        filepath = chat_box(storage);
        if (filepath == NULL) {
            storage->window.pop_up = NO_POP;
            storage->list_menu->list_menu =
            delete_visible_menu(storage->list_menu->list_menu, index);
            return;
        }
        add_layer(BOARD->layerList, filepath);
        BOARD->actual_layer = BOARD->layerList->tail;
        storage->window.pop_up = NO_POP;
        button_menu_is_clicked(storage, POP_TOOL);
    }
}

void open_file(void *storage, int id)
{
    button_menu_is_clicked(storage, id);
    ((main_t *)storage)->window.pop_up = OPEN;
    ((main_t *)storage)->list_menu->list_menu =
    add_visible_menu(((main_t *)storage)->list_menu->list_menu, POP_TOOL);
}
