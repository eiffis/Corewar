/*
** EPITECH PROJECT, 2024
** my_printf
** File description:
** my_printf
*/

#include "my.h"

int my_printf(char *format, ...)
{
    args_t *arg;
    va_list ap;
    int ret = 0;
    char *str;

    va_start(ap, format);
    for (int i = 0; format[i] != '\0'; i++) {
        if (format[i] != '%') {
            my_putchar(format[i]);
            ret += 1;
        } else {
        str = my_str_char_cpy(format + i);
        str++;
        arg = create_struct(str, ret);
        ret += parsing(str[my_strlen(str) - 1], arg, ap);
        i += arg->nb_args;
        }
    }
    va_end(ap);
    return ret;
}
