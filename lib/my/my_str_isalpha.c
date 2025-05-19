/*
** EPITECH PROJECT, 2024
** strisalpha
** File description:
** idk
*/

#include "my.h"

int my_str_isalpha(char const *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] < 65 || str[i] > 90)
            return 0;
    }
    return 1;
}
