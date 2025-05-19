/*
** EPITECH PROJECT, 2024
** my_printf
** File description:
** flag_n
*/

#include "my.h"
#include "my_printf.h"

int flag_n(va_list ap, args_t *arg)
{
    int *address = va_arg(ap, int *);

    *address = arg->cpt;
    return 0;
}
