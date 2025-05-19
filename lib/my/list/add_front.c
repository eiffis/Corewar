/*
** EPITECH PROJECT, 2024
** organised
** File description:
** add_front
*/

#include "list.h"

void add_front(list_t *list, void *data)
{
    node_t *node = malloc(sizeof(node_t));

    node->data = data;
    node->next = list->head;
    node->prev = NULL;
    if (list->head != NULL)
        list->head->prev = node;
    list->head = node;
    if (list->tail == NULL)
        list->tail = node;
    list->size++;
}
