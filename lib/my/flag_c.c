/*
** EPITECH PROJECT, 2024
** printf
** File description:
** flag_c
*/

#include "my.h"

int flag_c(va_list ap, args_t *arg)
{
    (void) arg;
    my_putchar(va_arg(ap, int));
    return 1;
}
