/*
** EPITECH PROJECT, 2024
** strncpy
** File description:
** copy n characters
*/

#include <stddef.h>

char *my_strncpy(char *dest, char const *src, int n)
{
    for (int i = 0; i < n; i++) {
        dest[i] = src[i];
        if (dest[i] == '\0' || src[i] == '\0')
            return dest;
    }
    return dest;
}
