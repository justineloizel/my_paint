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
    #define UNUSED __attribute__((unused))
typedef struct board board_t;
typedef struct framebuffer_t framebuffer_t;
typedef  struct layer_list {
    framebuffer_t *head;
    framebuffer_t *tail;
    int nb_layer;
}layer_list_t;
typedef struct brush_store {
    void (*brush)(board_t *board, sfVector2i position);
}brush_store_t;
#endif /*LAYER_H_*///
