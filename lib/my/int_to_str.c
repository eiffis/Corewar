/*
** EPITECH PROJECT, 2024
** top
** File description:
** int_to_str
*/

#include "my.h"

char *int_to_str_cus(int nb)
{
    int len = nb_len(nb);
    char *str = malloc(sizeof(char) * len + 1);
    int i = 0;

    if (str == NULL)
        return NULL;
    for (i = 0; nb > 0; i++) {
        str[i] = nb % 10 + 48;
        nb = nb / 10;
    }
    str[i] = '\0';
    str = my_revstr(str);
    return str;
}

char *int_to_str(int score)
{
    int len = nb_len(score);
    char *str = malloc(sizeof(char) * len + 1);
    int i = 0;

    if (str == NULL)
        return NULL;
    if (score == 0)
        str[0] = '0';
    if (score < 10) {
        str[len - 1] = '0';
        i++;
    }
    for (i = 0; score > 0; i++) {
        str[i] = score % 10 + 48;
        score = score / 10;
    }
    str[len] = '\0';
    str = my_revstr(str);
    return str;
}
