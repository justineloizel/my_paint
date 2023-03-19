/*
** EPITECH PROJECT, 2023
** B-MUL-200-REN-2-1-mypaint-tom.lefoix
** File description:
** zoom.c
*/

#include "paint.h"

void zoom_in(main_t *storage)
{
    sfVector2f mouse_pos;

    if (BOARD->nb_zoom < 14) {
        mouse_pos = V2I_V2F(sfMouse_getPositionRenderWindow(WINDOW.window));
        sfView_setCenter(BOARD->view, mouse_pos);
        sfView_zoom(BOARD->view, 0.833f);
        BOARD->nb_zoom += 1;
    }
}

void zoom_out(main_t *storage)
{
    if (BOARD->nb_zoom > -14) {
        sfView_zoom(BOARD->view, 1.2f);
        BOARD->nb_zoom -= 1;
    }
}
