/*
** EPITECH PROJECT, 2024
** my_printf
** File description:
** function for i and d
*/

#include "my.h"

int flag_lid(va_list ap)
{
    long int nb = va_arg(ap, long int);

    my_put_l_nbr(nb);
    return lnb_len(nb);
}

int flag_hid(va_list ap)
{
    int nb = va_arg(ap, int);

    my_put_h_nbr(nb);
    return hnb_len(nb);
}

int flags_i_and_d(va_list ap, args_t *arg)
{
    int nb = 0;

    if (arg->size == 'l')
        return flag_lid(ap);
    if (arg->size == 'h')
        return flag_hid(ap);
    nb = va_arg(ap, int);
    my_put_nbr(nb);
    return nb_len(nb);
}
