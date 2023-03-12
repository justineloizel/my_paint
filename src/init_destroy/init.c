/*
** EPITECH PROJECT, 2023
** B-MUL-200-REN-2-1-mypaint-tom.lefoix
** File description:
** init.c
*/

#include "paint.h"

main_t *init_storage(void)
{
    main_t *storage = malloc(sizeof(main_t));

    if (storage == NULL)
        return NULL;
    storage->window = init_window();
    storage->list_menu = create_base_menu();
    storage->board = board_create(1920, 1080);
    if (storage->list_menu == NULL || storage->board == NULL)
        return NULL;
    add_button_in_his_menu(storage->list_menu);
    return storage;
}
