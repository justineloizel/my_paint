/*
** EPITECH PROJECT, 2022
** B-MUL-200-REN-2-1-mypaint-tom.lefoix
** File description:
** sprites.c
*/

#include "paint.h"

static const sprites_store_t sprites_list[] = {
    {LAYERS, "assets/layers.png", {30, 910}},

    {THICKNESS, "assets/thickness.png", {30, 410}},

    {MANUAL_SPRITE, "assets/manual_pop_up.png", {550, 100}},

    {ABOUT_SPRITE, "assets/about_pop_up.png", {550, 100}},

    {SAVE_SPRITE, "assets/save_pop_up.png", {550, 100}},

    {OPEN_SPRITE, "assets/open_pop_up.png", {550, 100}},

    {SHAPE, "assets/shape.png", {30, 310}},
};

sprites_t *get_sprite(list_sprites_t *list, int id)
{
    sprites_t *node = list->head;

    for (; node != NULL && node->id != id; node = node->next);
    if (node == NULL)
        return NULL;
    return node;
}

sprites_t *init_sprite(sprites_store_t data)
{
    sprites_t *sprite = malloc(sizeof(sprites_t));

    if (sprite == NULL)
        return NULL;
    sprite->id = data.id;
    sprite->sprite = sfSprite_create();
    sprite->texture = sfTexture_createFromFile(data.filepath, NULL);
    sprite->pos = data.pos;
    if (sprite->sprite == NULL || sprite->texture == NULL)
        return NULL;
    sfSprite_setTexture(sprite->sprite, sprite->texture, sfTrue);
    sfSprite_setPosition(sprite->sprite, sprite->pos);
    sprite->next = NULL;
    sprite->prev = NULL;
    return sprite;
}

list_sprites_t *add_new_sprite(sprites_store_t data, list_sprites_t *sprites)
{
    if (sprites->head == NULL) {
        sprites->head = init_sprite(data);
        sprites->tail = sprites->head;
        return sprites;
    }
    sprites->tail->next = init_sprite(data);
    if (sprites->tail->next == NULL)
        return sprites;
    sprites->tail->next->prev = sprites->tail;
    sprites->tail = sprites->tail->next;
    return sprites;
}

list_sprites_t *create_sprites(void)
{
    list_sprites_t *sprites = malloc(sizeof(list_sprites_t));

    if (sprites == NULL)
        return NULL;
    sprites->head = NULL;
    sprites->tail = NULL;
    for (size_t i = 0; i < ARRLEN(sprites_list); i++) {
        add_new_sprite(sprites_list[i], sprites);
    }
    return sprites;
}
