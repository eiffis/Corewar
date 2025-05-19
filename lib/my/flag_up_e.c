/*
** EPITECH PROJECT, 2024
** my_printf
** File description:
** flag_e
*/

#include "my_printf.h"
#include "my.h"

int check_up_cpt(int cpt)
{
    if (cpt >= 0)
        my_putchar('+');
    if (cpt < 0) {
        my_putchar('-');
        cpt *= -1;
    }
    if (cpt < 10)
        my_putchar('0');
    return cpt;
}

int put_up_science(double nb, int precision)
{
    int cpt = 0;
    int ret = precision;

    while (nb >= 10) {
        nb = nb / 10;
        cpt++;
    }
    while (nb < 1) {
        nb *= 10;
        cpt--;
    }
    my_put_float(nb, precision);
    my_putchar('E');
    cpt = check_up_cpt(cpt);
    my_put_nbr(cpt);
    ret += nb_len(cpt);
    return ret;
}

int flag_up_e(va_list ap, args_t *arg)
{
    double nb = va_arg(ap, double);

    return put_up_science(nb, arg->precision);
}
