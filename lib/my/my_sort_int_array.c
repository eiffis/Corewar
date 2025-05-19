/*
** EPITECH PROJECT, 2024
** sort_int_array
** File description:
** sort integer in array
*/

#include "my.h"

void sort_array(int *array, int *i, int *j)
{
    int tmp = 0;

    if (array[*i] < array[*j]) {
        tmp = array[*i];
        array[*i] = array[*j];
        array[*j] = tmp;
    }
}

void my_sort_int_array(int *array, int size)
{
    for (int i = 0; i != size; i++) {
        for (int j = 0; j != size; j++)
            sort_array(array, &i, &j);
    }
}
