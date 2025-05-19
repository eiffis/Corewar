/*
** EPITECH PROJECT, 2024
** my_printf
** File description:
** flag_f
*/

#include "my.h"

int flag_bl_f(va_list ap, args_t *arg)
{
    long double nb = va_arg(ap, long double);

    if (arg->precision == -1)
        arg->precision = 6;
    return my_put_bl_float(nb, arg->precision);
}

int flag_f(va_list ap, args_t *arg)
{
    double nb = 0;
    int ret = 0;

    if (arg->size == 'L')
        return flag_bl_f(ap, arg);
    nb = va_arg(ap, double);
    if (arg->precision == -1)
        ret = my_put_float(nb, 6);
    else
        ret = my_put_float(nb, arg->precision);
    return ret;
}
