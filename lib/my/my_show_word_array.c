/*
** EPITECH PROJECT, 2024
** str show word array
** File description:
** displays content of array
*/

#include <stdio.h>
#include <stddef.h>
#include <unistd.h>
#include "my.h"

int my_show_word_array(char *const *tab)
{
    for (int i = 0; tab[i] != NULL; i++) {
        write(1, tab[i], my_strlen(tab[i]));
        write(1, "\n", 1);
    }
    return 0;
}
