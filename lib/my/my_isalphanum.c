/*
** EPITECH PROJECT, 2025
** B-PSU-200-REN-2-1-minishell1-enzo.iffis
** File description:
** my_isalphanum
*/

#include "my.h"

int my_isalphanum(char c)
{
    if ((c >= '0' && c <= '9') || (my_isalpha(c) == 0))
        return 0;
    return 1;
}
