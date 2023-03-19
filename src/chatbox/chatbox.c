/*
** EPITECH PROJECT, 2023
** B-MUL-200-REN-2-1-mypaint-tom.lefoix
** File description:
** chatbox.c
*/

#include "paint.h"
#include "my.h"
chat_box_t *init_chat_box(void);
void destroy_chat_box(chat_box_t *chat_box);

static char *my_str_cat_char(chat_box_t *chat_box, char c)
{
    int len = my_strlen(chat_box->msg);
    char *new_text;

    if (c == 8)
        new_text = malloc(sizeof(char) * (len + 1));
    else
        new_text = malloc(sizeof(char) * (len + 2));
    if (new_text == NULL || (len == 0 && c == 8) || (len > 21 && c != 8))
        return chat_box->msg;
    new_text = my_strcpy(new_text, chat_box->msg);
    if (c == 8)
        new_text[len - 1] = '\0';
    else {
        new_text[len + 1] = '\0';
        new_text[len] = c;
    }
    return new_text;
}

static void event_text_entered(chat_box_t *chat_box, sfEvent event)
{
    if (event.text.unicode < 128) {
        chat_box->msg = my_str_cat_char(chat_box, (char)event.text.unicode);
        sfText_setString(chat_box->text, chat_box->msg);
    }
}

static void event_manager_chat_box(sfEvent event, chat_box_t *chat_box,
int *check, main_t *storage)
{
    print_layer(storage);
    print_button_menu(storage->list_menu, WINDOW.window);
    sfRenderWindow_drawRectangleShape(WINDOW.window, chat_box->bg, NULL);
    sfRenderWindow_drawText(WINDOW.window, chat_box->text, NULL);
    while (sfRenderWindow_pollEvent(WINDOW.window, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(WINDOW.window);
        if (event.type == sfEvtKeyPressed && event.key.code == sfKeyEscape)
            *check = -1;
        if (event.type == sfEvtKeyPressed && event.key.code == sfKeyEnter)
            *check = 0;
        if (event.type == sfEvtTextEntered)
            event_text_entered(chat_box, event);
    }
}

char *chat_box(main_t *storage)
{
    chat_box_t *chat_box = init_chat_box();
    int check = 1;
    sfEvent event;
    char *msg;

    if (chat_box == NULL)
        return NULL;
    while (check > 0) {
        sfRenderWindow_clear(storage->window.window,BACKGROUND_COLOR);
        event_manager_chat_box(event, chat_box, &check, storage);
        sfRenderWindow_display(WINDOW.window);
    }
    msg = chat_box->msg;
    destroy_chat_box(chat_box);
    if (check == 0)
        return msg;
    else {
        free(msg);
        return NULL;
    }
}
