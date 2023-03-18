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
    #define V2I_V2F(X) (sfVector2f){ \
    X.x, X.y                         \
    }
    #define V2F_V2I(X) (sfVector2i){\
    X.x, X.y                        \
    }
    #define PALETTE_POS (sfVector2f){\
    40, 80\
    }
    #define IS_NULL(X) (X == NULL) ? NULL : free(X);
typedef struct framebuffer_t    {
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
    int tools;
    sfClock *clock;
    sfRectangleShape *board;
    short int nb_zoom;
    sfView *view;
}board_t;

typedef struct color_palette {
    sfTexture *texture;
    sfImage *image;
    sfSprite *sprite;
} color_palette_t;

typedef struct main_s {
    window_t window;
    list_menu_t *list_menu;
    board_t *board;
    color_palette_t *palette;
}main_t;

int *add_visible_menu(int *actual_list, int menu);
void quit_manual(void *storage, int id);
void display_about(void *storage, int id);
void display_manual(void *storage, int id);
void drawing_activated(void *storage, int id);
void display_cursor(main_t *storage);
void new_file(void *storage, int id);
void eraser_activated(void *storage, int id);
int *delete_visible_menu(int *actual_list, int index);
menu_t *get_menu_by_id(int id, list_menu_t *list_menu);
void print_button_menu(list_menu_t *list_menu, sfRenderWindow *window);
void is_click(sfMouseButtonEvent event, main_t *storage, button_t *button);
void verify_menu_click(sfMouseButtonEvent event, main_t *storage);
void button_menu_is_clicked(void *storage, int id);
void recalcul_position_menu(main_t *storage);
void put_pixel(framebuffer_t *framebuffer, unsigned int x,\
unsigned int y, sfColor color);
sfVector2f get_valid_position(main_t *storage, sfVector2f position, int view);

        void draw_object(board_t *board, sfVector2i position);
//init
        main_t *init_storage(void);
        list_menu_t *create_base_menu(void);
        void add_button_in_his_menu(list_menu_t *list_menu);
        board_t *board_create(unsigned int width, unsigned int height);
framebuffer_t *framebuffer_create(unsigned int width, unsigned int height);
        layer_list_t *init_layer(void);
        void add_layer(layer_list_t *list, char *filepath);
        color_palette_t *init_palette(void);

//manage
        void manage_draw(main_t *storage);
        void correction_draw(board_t *board , sfVector2i position);
        void print_layer(main_t *storage);
        void save_drawing_to_jpg(main_t *storage, int id);
        void save_drawing_to_png(main_t *storage, int id);
        void save_drawing_to_bmp(main_t *storage, int id);
        void fill_framebuffer(framebuffer_t *framebuffer, sfColor color);
        char *get_input(void);
        void zoom_in(main_t *storage);
        void zoom_out(main_t *storage);


//destroy
        void destroy_storage(main_t *storage);
        void board_destroy(board_t *board);
        void delete_framebuffer(framebuffer_t *fb);
        void delete_layer(layer_list_t *layer_list, framebuffer_t *target);
        void destroy_palette(color_palette_t *palette);

//brush
        void draw_filled_square(board_t *board, sfVector2i position);
        void draw_square(board_t *board, sfVector2i position);
        void draw_filled_circle(board_t *board, sfVector2i center);
        void draw_circle(board_t *board, sfVector2i position);
        void draw_filled_triangle(board_t *board, sfVector2i position);
        void draw_triangle(board_t *board, sfVector2i position);
        void draw_triangle_reverse(board_t *board, sfVector2i position);
        void draw_triangle_reverse_filled(board_t *board, sfVector2i position);
void filled_square(void *storage, int id);
void filled_circle(void *storage, int id);
void filled_triangle(void *storage, int id);
void quit_paint(void *storage, int id);
void layer_plus(void *storage, int id);
void layer_less(void *storage, int id);
#endif
