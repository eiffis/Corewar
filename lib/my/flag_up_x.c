/*
** EPITECH PROJECT, 2024
** printf
** File description:
** flag_x
*/

#include <stdlib.h>
#include "my.h"
#include <stdio.h>

int my_put_up_hexa(long int nb)
{
    int i = 0;
    char *str = malloc(sizeof(char) * 11);

    while (nb != 0) {
        if ((nb % 16) >= 0 && (nb % 16) < 10)
            str[i] = (nb % 16) + 48;
        if ((nb % 16) >= 10)
            str[i] = (nb % 16) + 55;
        i++;
        nb = nb / 16;
    }
    str[i] = '\0';
    str = my_revstr(str);
    my_putstr(str);
    return i - 1;
}

int flag_up_x(va_list ap, args_t *arg)
{
    int nb = va_arg(ap, int);

    (void) arg;
    if (arg->specifier == '#')
        my_putstr("0X");
    return my_put_up_hexa(nb);
}
