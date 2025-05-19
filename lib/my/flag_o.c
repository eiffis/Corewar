/*
** EPITECH PROJECT, 2024
** printf
** File description:
** flag_o
*/

#include "my.h"

int my_put_short_octal(va_list ap, args_t *arg)
{
    int i = 0;
    int nb = (short)va_arg(ap, int);
    char *str = malloc(sizeof(char) * nb_len(nb));
    int ret = nb_len(nb);

    while (nb != 0) {
        str[i] = (nb % 8) + 48;
        nb = nb / 8;
        i++;
    }
    str[i] = '\0';
    str = my_revstr(str);
    if (arg->specifier == '#')
        my_putchar('0');
    my_putstr(str);
    return ret;
}

int my_put_long_octal(va_list ap, args_t *arg)
{
    int i = 0;
    int nb = va_arg(ap, long int);
    char *str = malloc(sizeof(char) * nb_len(nb));
    int ret = nb_len(nb);

    while (nb != 0) {
        str[i] = (nb % 8) + 48;
        nb = nb / 8;
        i++;
    }
    str[i] = '\0';
    str = my_revstr(str);
    if (arg->specifier == '#')
        my_putchar('0');
    my_putstr(str);
    return ret;
}

int my_put_octal(va_list ap, args_t *arg)
{
    int i = 0;
    int nb = va_arg(ap, int);
    char *str = malloc(sizeof(char) * nb_len(nb));
    int ret = nb_len(nb);

    (void) arg;
    while (nb != 0) {
        str[i] = (nb % 8) + 48;
        nb = nb / 8;
        i++;
    }
    str[i] = '\0';
    str = my_revstr(str);
    my_putstr(str);
    return ret;
}

int flag_o(va_list ap, args_t *arg)
{
    int ret = 0;

    (void) arg;
    if (arg->size == 'h') {
        ret = my_put_short_octal(ap, arg);
        return ret;
    } else if (arg->size == 'l') {
        ret = my_put_long_octal(ap, arg);
        return ret;
    } else {
        ret = my_put_octal(ap, arg);
        return ret;
    }
}
