/*
** EPITECH PROJECT, 2024
** organised
** File description:
** list
*/

#ifndef INCLUDED_LIST_H
    #define INCLUDED_LIST_H

    #include <stdlib.h>

typedef struct struct_s {
    int pid;
    char *user;
    int pr;
    int ni;
    char *virt;
    int res;
    int shr;
    char s;
    float cpu;
    float mem;
    char *time;
    char *command;
} struct_t;

typedef struct node_s {
    void *data;
    struct node_s *prev;
    struct node_s *next;
} node_t;

typedef struct list_s {
    node_t *head;
    node_t *tail;
    int size;
} list_t;

list_t *create_list(void);
void add_end(list_t *list, void *data);
void add_front(list_t *list, void *data);
void del_front(list_t *list);
void del_end(list_t *list);
void del_node(list_t *list, node_t *node);

#endif
