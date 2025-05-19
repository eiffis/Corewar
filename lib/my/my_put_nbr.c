/*
** EPITECH PROJECT, 2024
** my_put_nbr
** File description:
** display numbers
*/

#include "my.h"

void put_overflow(void)
{
    my_putstr("-2147483648");
}

int my_put_h_nbr(int nb)
{
    short int n = (short int) nb;

    if (n < 10 && n >= 0) {
        my_putchar(n + 48);
    } else if (n < 0) {
        my_putchar('-');
        n *= -1;
        my_put_l_nbr(n);
    } else {
        my_put_l_nbr(n / 10);
        my_put_l_nbr(n % 10);
    }
    return 0;
}

int my_put_ll_nbr(long long int nb)
{
    if (nb == LLONG_MIN)
        nb++;
    if (nb < 10 && nb >= 0) {
        my_putchar(nb + 48);
    } else if (nb < 0) {
        my_putchar('-');
        nb *= -1;
        my_put_ll_nbr(nb);
    } else {
        my_put_ll_nbr(nb / 10);
        my_put_ll_nbr(nb % 10);
    }
    return 0;
}

int my_put_l_nbr(long int nb)
{
    if (nb == LONG_MIN)
        nb++;
    if (nb < 10 && nb >= 0) {
        my_putchar(nb + 48);
    } else if (nb < 0) {
        my_putchar('-');
        nb *= -1;
        my_put_l_nbr(nb);
    } else {
        my_put_l_nbr(nb / 10);
        my_put_l_nbr(nb % 10);
    }
    return 0;
}

int my_put_nbr(int nb)
{
    if (nb == INT_MIN) {
        put_overflow();
        return 0;
    }
    if (nb < 10 && nb >= 0) {
        my_putchar(nb + 48);
    } else if (nb < 0) {
        my_putchar('-');
        nb *= -1;
        my_put_nbr(nb);
    } else {
        my_put_nbr(nb / 10);
        my_put_nbr(nb % 10);
    }
    return 0;
}
