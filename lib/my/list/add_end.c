/*
** EPITECH PROJECT, 2024
** organised
** File description:
** add_end
*/

#include "list.h"

void add_end(list_t *list, void *data)
{
    node_t *node = malloc(sizeof(node_t));

    node->data = data;
    node->next = NULL;
    node->prev = list->tail;
    if (list->tail != NULL)
        list->tail->next = node;
    list->tail = node;
    if (list->head == NULL)
        list->head = node;
    list->size++;
}
