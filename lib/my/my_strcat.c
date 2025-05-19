/*
** EPITECH PROJECT, 2024
** strcat
** File description:
** idk
*/

#include "my.h"

char *my_strcatdup(char *s1, char *s2)
{
    int len = my_strlen(s1) + my_strlen(s2);
    char *new = malloc(sizeof(char) * len + 1);
    int j = 0;

    for (; s1[j] != '\0'; j++)
        new[j] = s1[j];
    for (int i = 0; s2[i] != '\0'; i++) {
        new[j] = s2[i];
        j++;
    }
    new[j] = '\0';
    return new;
}

char *my_strcat(char *dest, char const *src)
{
    int j = 0;

    for (j = 0; dest[j] != '\0'; j++);
    for (int i = 0; src[i] != '\0'; i++) {
        dest[j] = src[i];
        j++;
    }
    return dest;
}
