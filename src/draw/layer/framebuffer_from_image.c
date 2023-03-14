/*
** EPITECH PROJECT, 2023
** B-MUL-200-REN-2-1-mypaint-tom.lefoix
** File description:
** framebuffer_from_image.c
*/

#include "paint.h"

void set_framebuffer(framebuffer_t *framebuffer, unsigned int width,
unsigned int height, int fb);

void copy_pixels(sfUint8 const *source, sfVector2u source_size,
sfUint8 *destination, sfVector2u destination_size)
{
    double ratio_width = (float)source_size.x / (float)destination_size.x;
    double ratio_height = (float)source_size.y / (float)destination_size.y;
    unsigned int size_src_x;
    unsigned int size_src_y;
    
    for (unsigned int i = 0; i < destination_size.y; ++i) {
        for (unsigned int j = 0; j < destination_size.x; ++j) {
             size_src_x = (unsigned int)(j * ratio_width);
            size_src_y = (unsigned int)(i * ratio_height);
            destination[(j + i * destination_size.x) * 4] = source[(size_src_x + size_src_y * source_size.x) * 4];
            destination[(j + i * destination_size.x) * 4 + 1] = source[(size_src_x + size_src_y * source_size.x) * 4 + 1];
            destination[(j + i * destination_size.x) * 4 + 2] = source[(size_src_x + size_src_y * source_size.x) * 4 + 2];
            destination[(j + i * destination_size.x) * 4 + 3] = source[(size_src_x + size_src_y * source_size.x) * 4 + 3];
        }
    }
}

sfUint8 *get_buffer_image(char *filepath)
{
    sfImage *image = sfImage_createFromFile(filepath);
    sfVector2u size;
    const sfUint8 *image_buffer;
    sfUint8 *buffer;

    if (image == NULL)
        return NULL;
    size = sfImage_getSize(image);
    image_buffer = sfImage_getPixelsPtr(image);
    if (image_buffer == NULL)
        return NULL;
    buffer = malloc(sizeof(sfUint8) * (int)(SIZE_BOARD.x * SIZE_BOARD.y * 4));
    if (buffer == NULL)
        return NULL;
    copy_pixels(image_buffer, size, buffer, (sfVector2u){SIZE_BOARD.x, SIZE_BOARD.y});
    sfImage_destroy(image);
    return buffer;
}

framebuffer_t *framebuffer_from_image(unsigned int width, unsigned int height,
char *filepath)
{
    framebuffer_t *framebuffer;

    framebuffer = malloc(sizeof(framebuffer_t));
    if (framebuffer == NULL)
        return (NULL);
    framebuffer->pixels = get_buffer_image(filepath);
    if (framebuffer->pixels == NULL) {
        return (NULL);
    }
    framebuffer->width = width;
    framebuffer->height = height;
    framebuffer->texture = sfTexture_create(width, height);
    framebuffer->sprite = sfSprite_create();
    if (framebuffer->texture == NULL || framebuffer->sprite == NULL) {
        return (NULL);
    }
    set_framebuffer(framebuffer, width, height, sfFalse);
    return (framebuffer);
}