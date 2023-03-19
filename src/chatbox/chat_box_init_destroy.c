/*
** EPITECH PROJECT, 2023
** B-MUL-200-REN-2-1-mypaint-tom.lefoix
** File description:
** chat_box_init_destroy.c
*/

#include "paint.h"

chat_box_t *init_chat_box(void)
{
    chat_box_t *chat_box = malloc(sizeof(chat_box_t));

    if (chat_box == NULL)
        return NULL;
    chat_box->bg = sfRectangleShape_create();
    chat_box->text = sfText_create();
    chat_box->font = sfFont_createFromFile("assets/arial.ttf");
    chat_box->msg = malloc(sizeof(char) * 1);
    if (chat_box->bg == NULL || chat_box->text == NULL ||
        chat_box->font == NULL || chat_box->msg == NULL)
        return NULL;
    chat_box->msg[0] = '\0';
    sfText_setPosition(chat_box->text, (sfVector2f){1075, 600});
    sfText_setFont(chat_box->text, chat_box->font);
    sfRectangleShape_setSize(chat_box->bg, (sfVector2f){200, 35});
    sfRectangleShape_setPosition(chat_box->bg, (sfVector2f){1075, 600});
    sfRectangleShape_setFillColor(chat_box->bg, sfWhite);
    sfText_setColor(chat_box->text, sfBlack);
    return chat_box;
}

void destroy_chat_box(chat_box_t *chat_box)
{
    sfText_destroy(chat_box->text);
    sfRectangleShape_destroy(chat_box->bg);
    sfFont_destroy(chat_box->font);
    free(chat_box);
}
