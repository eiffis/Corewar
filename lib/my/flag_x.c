/*
** EPITECH PROJECT, 2024
** printf
** File description:
** flag_x
*/

#include <stdlib.h>
#include "my.h"
#include <stdio.h>

int my_put_hexa(va_list ap, args_t *arg)
{
    int i = 0;
    int nb = va_arg(ap, int);
    char *str = malloc(sizeof(char) * 11);

    while (nb != 0) {
        if ((nb % 16) >= 0 && (nb % 16) < 10)
            str[i] = (nb % 16) + 48;
        if ((nb % 16) >= 10)
            str[i] = (nb % 16) + 87;
        i++;
        nb = nb / 16;
    }
    str[i] = '\0';
    str = my_revstr(str);
    if (arg->specifier == '#')
        my_putstr("0x");
    my_putstr(str);
    return i - 1;
}

int my_put_short_hexa(va_list ap, args_t *arg)
{
    int i = 0;
    int nb = (short)va_arg(ap, int);
    char *str = malloc(sizeof(char) * 11);

    while (nb != 0) {
        if ((nb % 16) >= 0 && (nb % 16) < 10)
            str[i] = (nb % 16) + 48;
        if ((nb % 16) >= 10)
            str[i] = (nb % 16) + 87;
        i++;
        nb = nb / 16;
    }
    str[i] = '\0';
    str = my_revstr(str);
    if (arg->specifier == '#')
        my_putstr("0x");
    my_putstr(str);
    return i - 1;
}

int my_put_long_hexa(va_list ap, args_t *arg)
{
    int i = 0;
    int nb = va_arg(ap, long int);
    char *str = malloc(sizeof(char) * 11);

    while (nb != 0) {
        if ((nb % 16) >= 0 && (nb % 16) < 10)
            str[i] = (nb % 16) + 48;
        if ((nb % 16) >= 10)
            str[i] = (nb % 16) + 87;
        i++;
        nb = nb / 16;
    }
    str[i] = '\0';
    str = my_revstr(str);
    if (arg->specifier == '#')
        my_putstr("0x");
    my_putstr(str);
    return i - 1;
}

int flag_x(va_list ap, args_t *arg)
{
    int ret = 0;

    (void) arg;
    if (arg->size == 'h') {
        ret = my_put_short_hexa(ap, arg);
        return ret;
    } else if (arg->size == 'l') {
        ret = my_put_long_hexa(ap, arg);
        return ret;
    } else {
        ret = my_put_hexa(ap, arg);
        return ret;
    }
    return ret;
}
