/*
** EPITECH PROJECT, 2024
** my_printf
** File description:
** flag_u
*/

#include "my.h"

int flag_u(va_list ap, args_t *arg)
{
    int nb = va_arg(ap, int);

    (void) arg;
    if (nb < 0)
        nb *= -1;
    my_put_nbr(nb);
    return nb_len(nb);
}
