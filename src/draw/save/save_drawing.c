/*
** EPITECH PROJECT, 2023
** B-MUL-200-REN-2-1-mypaint-tom.lefoix
** File description:
** save_drawing.c
*/

#include "paint.h"
#include "my.h"

void fill_framebuffer(framebuffer_t *framebuffer, sfColor color)
{
    for (size_t i = 0; i < framebuffer->width * framebuffer->height * 4;
    i += 4) {
        framebuffer->pixels[i] = color.r;
        framebuffer->pixels[i + 1] = color.g;
        framebuffer->pixels[i + 2] = color.b;
        framebuffer->pixels[i + 3] = color.a;
    }
}

void concat_framebuffer(framebuffer_t *framebuffer, framebuffer_t *layer)
{
    for (size_t i = 0; i < framebuffer->width * framebuffer->height * 4;
    i += 4) {
        if ((layer->pixels[i] == sfTransparent.r &&
            layer->pixels[i + 1] == sfTransparent.g &&
            layer->pixels[i + 2] == sfTransparent.b &&
            layer->pixels[i + 3] == sfTransparent.a) ||
            !framebuffer->is_visible)
            continue;
        framebuffer->pixels[i] = layer->pixels[i];
        framebuffer->pixels[i + 1] = layer->pixels[i + 1];
        framebuffer->pixels[i + 2] = layer->pixels[i + 2];
        framebuffer->pixels[i + 3] = layer->pixels[i + 3];
    }
    if (layer->next != NULL)
        concat_framebuffer(framebuffer, layer->next);
}

void save_drawing_to_jpg(main_t *storage, UNUSED int id)
{
    framebuffer_t *fb_save = framebuffer_create(SIZE_BOARD.x, SIZE_BOARD.y);
    sfImage *image;
    char *input = get_input();

    if (fb_save == NULL || input == NULL) {
        delete_framebuffer(fb_save);
        IS_NULL(input)
        return;
    }
    fill_framebuffer(fb_save, sfWhite);
    concat_framebuffer(fb_save, storage->board->layerList->head);
    image = sfImage_createFromPixels(SIZE_BOARD.x, SIZE_BOARD.y,
    fb_save->pixels);
    sfImage_saveToFile(image, my_strcat(input, ".jpeg"));
    sfImage_destroy(image);
    delete_framebuffer(fb_save);
}

void save_drawing_to_png(main_t *storage, UNUSED int id)
{
    framebuffer_t *fb_save = framebuffer_create(SIZE_BOARD.x, SIZE_BOARD.y);
    sfImage *image;
    char *input = get_input();

    if (fb_save == NULL || input == NULL) {
        delete_framebuffer(fb_save);
        IS_NULL(input)
        return;
    }
    concat_framebuffer(fb_save, storage->board->layerList->head);
    image = sfImage_createFromPixels(SIZE_BOARD.x, SIZE_BOARD.y,
    fb_save->pixels);
    sfImage_saveToFile(image, my_strcat(input, ".png"));
    sfImage_destroy(image);
    delete_framebuffer(fb_save);
}

void save_drawing_to_bmp(main_t *storage, UNUSED int id)
{
    framebuffer_t *fb_save = framebuffer_create(SIZE_BOARD.x, SIZE_BOARD.y);
    sfImage *image;
    char *input = get_input();

    if (fb_save == NULL || input == NULL) {
        delete_framebuffer(fb_save);
        IS_NULL(input)
        return;
    }
    fill_framebuffer(fb_save, sfWhite);
    concat_framebuffer(fb_save, storage->board->layerList->head);
    image = sfImage_createFromPixels(SIZE_BOARD.x, SIZE_BOARD.y,
            fb_save->pixels);
    sfImage_saveToFile(image, my_strcat(input, ".bmp"));
    sfImage_destroy(image);
    delete_framebuffer(fb_save);
}
