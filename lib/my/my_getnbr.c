/*
** EPITECH PROJECT, 2024
** get nbr
** File description:
** get a number from string
*/

#include "my.h"

int verif_overflow(int nb, int cpt)
{
    if (cpt % 2 != 0 && nb > 0)
        return 1;
    if (cpt % 2 == 0 && nb < 0)
        return 1;
    return 0;
}

int my_getnbr(char const *str)
{
    int cpt = 0;
    int i = 0;
    int nb = 0;

    for (; str[i] < '0' || str[i] > '9'; i++) {
        if (str[i] == '-')
            cpt++;
    }
    for (; str[i] >= '0' && str[i] <= '9'; i++) {
        nb *= 10;
        if (cpt % 2 == 0)
            nb += str[i] - 48;
        if (cpt % 2 != 0)
            nb -= str[i] - 48;
        if (verif_overflow(nb, cpt) == 1)
            return 0;
    }
    return nb;
}
