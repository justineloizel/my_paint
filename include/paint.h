/*
** EPITECH PROJECT, 2022
** B-MUL-200-REN-2-1-mypaint-tom.lefoix
** File description:
** paint.h
*/

#ifndef PAINT_H_
    #define PAINT_H_
    #include <SFML/Audio.h>
    #include <SFML/Graphics.h>
    #include <stdio.h>
    #include <stdlib.h>
    #include <unistd.h>
    #include <time.h>
    #include <math.h>
    #include "window.h"
    #include "menu.h"
    #include "layer.h"

    #define WINDOW storage->window
    #define MENU_LIST storage->list_menu
    #define  BOARD storage->board
    #define V2I_V2F(X) (sfVector2f){X.x, X.y}
    #define V2F_V2I(X) (sfVector2i){X.x, X.y}
#define DIR_X (vector.x < 0) ? (i > position.x) ? 1 : 0 : (i < position.x) ? 1 : 0
#define DIR_Y (vector.y < 0) ? (j > position.y) ? 1 : 0 : (j < position.y) ? 1 : 0

typedef struct framebuffer_t
{
    sfUint8 *pixels;
    unsigned int width;
    unsigned int height;
    sfTexture *texture;
    sfSprite *sprite;
    struct framebuffer_t *next;
    struct framebuffer_t *prev;
} framebuffer_t;

typedef struct board {
    layer_list_t *layerList;
    framebuffer_t *actual_layer;
    sfColor color;
    int size;
    sfClock *clock;
    sfRectangleShape *board;
}board_t;

typedef struct main_s {
    window_t window;
    list_menu_t *list_menu;
    board_t *board;
}main_t;

int *add_visible_menu(int *actual_list, int menu);
int *delete_visible_menu(int *actual_list, int index);
menu_t *get_menu_by_id(int id, list_menu_t *list_menu);
void print_button_menu(list_menu_t *list_menu, sfRenderWindow *window);
void is_click(sfMouseButtonEvent event, main_t *storage, button_t *button);
void verify_menu_click(sfMouseButtonEvent event, main_t *storage);
void button_menu_is_clicked(void *storage, int id);
void recalcul_position_menu(main_t *storage);
void put_pixel(framebuffer_t *framebuffer, unsigned int x,\
unsigned int y, sfColor color);
sfVector2f get_valid_position(main_t *storage, sfVector2f position);

        void draw_object(board_t *board, sfVector2i position);
//init
        main_t *init_storage(void);
        list_menu_t *create_base_menu(void);
        void add_button_in_his_menu(list_menu_t *list_menu);
        board_t *board_create(unsigned int width, unsigned int height);
framebuffer_t *framebuffer_create(unsigned int width, unsigned int height);
layer_list_t *init_layer(void);

//manage
        void manage_draw(main_t *storage);
        void correction_draw(board_t *board , sfVector2i position);

//destroy
        void destroy_storage(main_t *storage);
        void board_destroy(board_t *board);
        void board_destroy(board_t *board);
        void delete_framebuffer(framebuffer_t *fb);
void delete_layer(layer_list_t *layer_list, framebuffer_t *target);
#endif
