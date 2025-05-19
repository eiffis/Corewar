/*
** EPITECH PROJECT, 2024
** organised
** File description:
** del_end
*/

#include "list.h"

void del_end(list_t *list)
{
    node_t *node = list->tail;

    list->tail = list->tail->prev;
    list->tail->next = NULL;
    list->size--;
    free(node);
}
