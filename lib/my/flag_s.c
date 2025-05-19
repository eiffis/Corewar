/*
** EPITECH PROJECT, 2024
** printf
** File description:
** flag_s
*/

#include "my.h"

int flag_s(va_list ap, args_t *arg)
{
    char *str = va_arg(ap, char *);

    if (str == NULL) {
        my_putstr("(null)");
        return 0;
    }
    if (arg->precision == 0)
        return 0;
    if (arg->precision > 0 && arg->precision <= 9) {
        for (int i = 0; i < arg->precision; i++) {
            my_putchar(str[i]);
        }
    } else
        my_putstr(str);
    return my_strlen(str);
}
