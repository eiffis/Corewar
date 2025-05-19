/*
** EPITECH PROJECT, 2024
** put_float.c
** File description:
** print float
*/

#include "my.h"

int print_lfloat(long double copy, int precision, int cpt)
{
    int coma = 0;

    if (precision > 0)
        my_putchar('.');
    for (int i = 0; i < precision; i++) {
        copy *= 10;
        coma = (int) copy % 10;
        my_putchar(coma + 48);
        copy -= coma;
        cpt++;
    }
    return cpt;
}

int my_put_bl_float(long double nb, int precision)
{
    long long int before = 0;
    long double copy = 0;
    long double round = 49;
    int cpt = lnb_len((int) nb);

    for (int i = 0; i <= precision + 1; i++)
        round *= 0.1;
    nb += round;
    before = (long long int) nb;
    my_put_ll_nbr(before);
    if (before == LLONG_MIN)
        return 0;
    copy = nb - before;
    cpt = print_lfloat(copy, precision, cpt);
    return cpt;
}

int print_float(double copy, int precision, int cpt)
{
    int coma = 0;

    if (precision > 0)
        my_putchar('.');
    for (int i = 0; i < precision; i++) {
        copy *= 10;
        coma = (int) copy % 10;
        my_putchar(coma + 48);
        copy -= coma;
        cpt++;
    }
    return cpt;
}

int my_put_float(double nb, int precision)
{
    int before = 0;
    double copy = 0;
    double round = 49;
    int cpt = nb_len((int) nb);

    for (int i = 0; i <= precision + 1; i++)
        round *= 0.1;
    nb += round;
    before = (int) nb;
    my_put_nbr(before);
    copy = nb - before;
    cpt = print_float(copy, precision, cpt);
    return cpt;
}
