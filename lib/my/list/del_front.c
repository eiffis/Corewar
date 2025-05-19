/*
** EPITECH PROJECT, 2024
** organised
** File description:
** del_front
*/

#include "list.h"

void del_front(list_t *list)
{
    node_t *node = list->head;

    list->head = list->head->next;
    list->head->prev = NULL;
    list->size--;
    free(node);
}
