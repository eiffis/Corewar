/*
** EPITECH PROJECT, 2024
** strcpy
** File description:
** copy string in dest
*/

char *my_strcpy(char *dest, char const *src)
{
    int i = 0;

    for (; src[i] != '\0'; i++)
        dest[i] = src[i];
    dest[i] = '\0';
    return dest;
}
