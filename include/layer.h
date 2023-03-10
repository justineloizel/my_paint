/*
** EPITECH PROJECT, 2023
** B-MUL-200-REN-2-1-mypaint-tom.lefoix
** File description:
** layer.h
*/
#ifndef LAYER_H_
	#define LAYER_H_
typedef struct framebuffer_t framebuffer_t;
typedef  struct layer_list {
    framebuffer_t *head;
    framebuffer_t *tail;
    int *nb_layer;
}layer_list_t;
#endif /*LAYER_H_*///
