/*
** EPITECH PROJECT, 2022
** B-MUL-200-REN-2-1-mypaint-tom.lefoix
** File description:
** new_file.c
*/

#include "paint.h"

void new_file(void *storage, int id)
{
    ((main_t *)storage)->window.cursor = 0;
}