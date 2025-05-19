/*
** EPITECH PROJECT, 2024
** my_printf
** File description:
** flag_e
*/

#include "my_printf.h"
#include "my.h"

int check_cpt(int cpt)
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

int print_zero(double nb, int precision)
{
    int cpt = 0;

    cpt += my_put_float(nb, precision);
    my_putchar('e');
    my_putstr("+00");
    cpt += 4;
    return cpt;
}

int print_all_science(double nb, int pre, int cpt, int ret)
{
    my_put_float(nb, pre);
    my_putchar('e');
    cpt = check_cpt(cpt);
    my_put_nbr(cpt);
    ret += nb_len(cpt);
    if (cpt < 10 && cpt >= 0)
        return 1;
    return ret;
}

int put_science(double nb, int precision)
{
    int cpt = 0;
    int ret = precision;

    if (precision == -1)
        precision = 6;
    if (nb == 0)
        return print_zero(nb, precision);
    while (nb >= 10) {
        nb = nb / 10;
        cpt++;
    }
    while (nb < 1) {
        nb *= 10;
        cpt--;
    }
    ret += print_all_science(nb, precision, cpt, ret);
    return ret;
}

int flag_e(va_list ap, args_t *arg)
{
    double nb = va_arg(ap, double);

    return put_science(nb, arg->precision);
}
