/*
** EPITECH PROJECT, 2023
** B-MUL-200-REN-2-1-mypaint-tom.lefoix
** File description:
** color_palette.c
*/

#include "paint.h"

color_palette_t *init_palette(void)
{
    color_palette_t *palette = malloc(sizeof(color_palette_t));

    if (palette == NULL)
        return NULL;
    palette->image = sfImage_createFromFile("assets/8.jpg");
    if (palette->image == NULL)
        return NULL;
    palette->texture = sfTexture_createFromImage(palette->image, NULL);
    if (palette->texture == NULL)
        return NULL;
    palette->sprite = sfSprite_create();
    if (palette->sprite == NULL)
        return NULL;
    sfSprite_setTexture(palette->sprite, palette->texture, sfTrue);
    sfSprite_setPosition(palette->sprite, PALETTE_POS);
    return palette;
}

void destroy_palette(color_palette_t *palette)
{
    sfSprite_destroy(palette->sprite);
    sfTexture_destroy(palette->texture);
    sfImage_destroy(palette->image);
    free(palette);
}
