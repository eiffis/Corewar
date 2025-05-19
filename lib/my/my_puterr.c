/*
** EPITECH PROJECT, 2024
** put str
** File description:
** displays string
*/

#include "my.h"

int my_puterr(char const *str, int error_code)
{
    write(2, str, my_strlen(str));
    return error_code;
}
