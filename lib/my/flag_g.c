/*
** EPITECH PROJECT, 2024
** my_printf
** File description:
** flag_g
*/

#include "my.h"
#include "my_printf.h"

int count_coma(double nb)
{
    double coma = nb - (int) nb;
    int cpt = 0;

    if (coma == 0 || nb > 10)
        return 0;
    if (nb > 0 && nb < 10) {
        while (coma < 1) {
            cpt++;
            coma *= 10;
        }
    }
    return cpt;
}

int flag_g(va_list ap, args_t *arg)
{
    double nb = va_arg(ap, double);
    int ret = 0;

    (void) arg;
    if (count_coma(nb) == 0) {
        ret += my_put_nbr(nb);
        return ret;
    }
    if (count_coma(nb) >= 5 && nb < 1) {
        ret += put_science(nb, 0);
        return ret;
    }
    if (count_coma(nb) >= 5 && nb > 1) {
        my_put_nbr(nb);
        return ret;
    } else
        ret += my_put_float(nb, count_coma(nb));
    return ret;
}
