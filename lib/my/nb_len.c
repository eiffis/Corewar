/*
** EPITECH PROJECT, 2024
** mini_printf
** File description:
** nb_len
*/

#include "my.h"

int hnb_len(int nb)
{
    int cpt = 0;

    if (nb < 0) {
        nb *= -1;
        cpt++;
    }
    while (nb > 0) {
        nb = nb / 10;
        cpt++;
    }
    return cpt;
}

int lnb_len(long int nb)
{
    int cpt = 0;

    if (nb < 0) {
        nb *= -1;
        cpt++;
    }
    while (nb > 0) {
        nb = nb / 10;
        cpt++;
    }
    return cpt;
}

int nb_len(int nb)
{
    int cpt = 0;

    if (nb < 0) {
        nb *= -1;
        cpt++;
    }
    if (nb < 10 && nb >= 0)
        return 2;
    while (nb > 0) {
        nb = nb / 10;
        cpt++;
    }
    return cpt;
}
