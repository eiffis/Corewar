/*
** EPITECH PROJECT, 2024
** navy
** File description:
** str_to_word_array
*/

#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include "my.h"

static int is_in(char c, char *separator)
{
    for (int i = 0; separator[i] != '\0'; i++) {
        if (separator[i] == c)
            return 1;
    }
    return 0;
}

static int skip_sep(char *str, char *separator, int i)
{
    for (; str[i] != '\0' && is_in(str[i], separator) == 1; i++);
    return i;
}

static int nb_line(char *str, char *sep_line)
{
    int cpt = 1;
    int i = 0;

    if (is_in(str[i], sep_line) == 1)
        i = skip_sep(str, sep_line, i);
    while (str[i] != '\0') {
        if (is_in(str[i], sep_line) == 1) {
            cpt++;
            i = skip_sep(str, sep_line, i);
            continue;
        }
        i++;
    }
    if (is_in(str[my_strlen(str) - 1], sep_line) == 1) {
        cpt--;
    }
    return cpt;
}

int str_len_sep(char *str, char *separator, int start)
{
    int cpt = 0;

    for (int i = start; str[i] != '\0' && is_in(str[i], separator) != 1; i++)
        cpt++;
    return cpt;
}

char *my_strndup(char *str, int n)
{
    char *str2 = malloc(sizeof(char) * (n + 1));

    if (str2 == NULL)
        return NULL;
    for (int i = 0; i < n + 1; i++)
        str2[i] = '\0';
    str2 = my_strncpy(str2, str, n);
    return str2;
}

char **my_str_to_word_array(char *str, char *separator)
{
    int nlines = nb_line(str, separator);
    char **tab = malloc(sizeof(char *) * (nlines + 1));
    int k = 0;
    int i = skip_sep(str, separator, 0);

    tab[nlines] = NULL;
    if (str == NULL || tab == NULL) {
        return NULL;
    }
    for (; i < my_strlen(str); i++) {
        if (is_in(str[i], separator) == 1) {
            continue;
        }
        tab[k] = my_strndup(str + i, str_len_sep(str, separator, i));
        i += str_len_sep(str, separator, i);
        i = skip_sep(str, separator, i) - 1;
        k++;
    }
    return tab;
}
