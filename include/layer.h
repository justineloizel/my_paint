/*
** EPITECH PROJECT, 2023
** B-MUL-200-REN-2-1-mypaint-tom.lefoix
** File description:
** layer.h
*/
#ifndef LAYER_H_
    #define LAYER_H_
    #define POS_BOARD (sfVector2f){\
    400,43\
    }
    #define SIZE_BOARD (sfVector2f){\
    1520, 965\
    }
    #define SIZE_BOARD_ARG SIZE_BOARD.x, SIZE_BOARD.y
    #define POS_BOARD_ARG POS_BOARD.x, POS_BOARD.y
    #define UNUSED __attribute__((unused))
    #define REC_BOARD (sfFloatRect){\
    POS_BOARD_ARG, SIZE_BOARD_ARG\
    }
    #define REC_VIEW_PORT (sfFloatRect){\
    0.2083333f, 0.03946f, 0.7916667f, 0.9555f\
    }
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
void check_top_menu(main_t *storage, int id);
#endif /*LAYER_H_*///
