/*
** EPITECH PROJECT, 2024
** organised
** File description:
** create_list
*/

#include "list.h"

list_t *create_list(void)
{
    list_t *list = malloc(sizeof(list_t));

    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
    return list;
}
