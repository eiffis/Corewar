/*
** EPITECH PROJECT, 2024
** my_printf
** File description:
** flag_p
*/

#include <stdint.h>
#include "my.h"

int my_put_hexa_flag_p(long int nb)
{
    int i = 0;
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
    my_putstr(str);
    return i - 1;
}

int flag_p(va_list ap, args_t *arg)
{
    void *pointer = va_arg(ap, void *);
    int ret = 2;

    (void) arg;
    my_putstr("0x");
    ret += my_put_hexa_flag_p((size_t)pointer);
    return ret;
}
