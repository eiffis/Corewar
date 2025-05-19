/*
** EPITECH PROJECT, 2024
** top
** File description:
** cut_str
*/

#include "my.h"

int nb_char(char *src, int delim)
{
    int cpt = 0;

    for (int i = 0; src[i] != delim && src[i] != '\0'; i++)
        cpt++;
    return cpt;
}

char *cut_str(char *src, char delim)
{
    int size = nb_char(src, delim);
    char *new = malloc(sizeof(char) * size + 1);

    for (int i = 0; src[i] != delim && src[i] != '\0'; i++)
        new[i] = src[i];
    new[size] = '\0';
    return new;
}
