/*
** EPITECH PROJECT, 2024
** strncat
** File description:
** idk
*/

char *my_strncat(char *dest, char const *src, int nb)
{
    int j = 0;

    for (j = 0; dest[j] != '\0'; j++);
    for (int i = 0; i != nb && src[i] != '\0'; i++) {
        dest[j] = src[i];
        j++;
    }
    return dest;
}
