/*
** EPITECH PROJECT, 2024
** organised
** File description:
** del_node
*/

#include "list.h"

void del_node(list_t *list, node_t *node)
{
    if (node->next != NULL)
        node->next->prev = node->prev;
    if (node->prev != NULL)
        node->prev->next = node->next;
    if (list->head == node)
        list->head = node->next;
    if (list->tail == node)
        list->tail = node->prev;
    list->size--;
}
