/*
** EPITECH PROJECT, 2024
** my is prime
** File description:
** find prime numbers
*/

#include "my.h"

int my_is_prime(int nb)
{
    if (nb == 0 || nb == 1)
        return 0;
    if (nb == 2 || nb == 3)
        return 1;
    for (int i = 2; i < nb; i++) {
        if (nb % i == 0)
            return 0;
    }
    return 1;
}
