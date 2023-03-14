/*
** EPITECH PROJECT, 2023
** B-MUL-200-REN-2-1-mypaint-tom.lefoix
** File description:
** layer.h
*/
#ifndef LAYER_H_
    #define LAYER_H_
    #define POS_BOARD (sfVector2f){\
    600,150\
    }
    #define SIZE_BOARD (sfVector2f){\
    1280, 830\
    }
    #define SIZE_BOARD_ARG SIZE_BOARD.x, SIZE_BOARD.y
    #define UNUSED __attribute__((unused))
typedef struct board board_t;
typedef struct main_s main_t;
typedef struct framebuffer_t framebuffer_t;

typedef  struct layer_list {
    framebuffer_t *head;
    framebuffer_t *tail;
    int nb_layer;
}layer_list_t;

typedef struct brush_store {
    void (*brush)(board_t *board, sfVector2i position);
}brush_store_t;
void manager_delete_layer(main_t *storage, UNUSED int id);
framebuffer_t *framebuffer_from_image(unsigned int width, unsigned int height,
char *filepath);
#endif /*LAYER_H_*///
