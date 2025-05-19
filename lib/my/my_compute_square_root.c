/*
** EPITECH PROJECT, 2024
** compute square root
** File description:
** compute square root
*/

#include "my.h"

int my_compute_square_root(int nb)
{
    for (int i = 1; i <= nb; i++) {
        if (i * i == nb)
            return i;
    }
    return 0;
}
