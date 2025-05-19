/*
** EPITECH PROJECT, 2024
** printf
** File description:
** put binary
*/

#include <stdlib.h>
#include "my.h"
#include <stdio.h>

int flag_b(va_list ap, args_t *arg)
{
    int i = 0;
    int nb = va_arg(ap, int);
    char *str = malloc(sizeof(char) * nb_len(nb));
    int ret = nb_len(nb);

    (void) arg;
    while (nb != 0) {
        str[i] = (nb % 2) + 48;
        nb = nb / 2;
        i++;
    }
    str[i] = '\0';
    str = my_revstr(str);
    my_putstr(str);
    return ret;
}
