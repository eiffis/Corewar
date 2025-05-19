/*
** EPITECH PROJECT, 2024
** find prime sup
** File description:
** search prime number that is greater or equal to nb
*/

#include "my.h"

int my_find_prime_sup(int nb)
{
    int i = 0;

    if (nb == 0 || nb == 1)
        return 2;
    for (; i < nb; i++) {
        if (my_is_prime(nb + i) == 1)
            return nb + i;
    }
    return 0;
}
