/*
** EPITECH PROJECT, 2024
** my_isneg
** File description:
** my_isneg
*/

#include "my.h"

int my_isneg(int n)
{
    if (n < 0)
        my_putchar('N');
    else
        my_putchar('P');
    my_putchar('\n');
    return 0;
}
