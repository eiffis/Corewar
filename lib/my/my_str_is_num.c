/*
** EPITECH PROJECT, 2024
** strisnum
** File description:
** idk
*/

int my_str_isnum(char const *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] < 48 || str[i] > 57)
            return 0;
    }
    return 1;
}
