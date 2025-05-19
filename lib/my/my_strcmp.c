/*
** EPITECH PROJECT, 2024
** my_strcmp.c
** File description:
** Reproduce the behavior of the strcmp function
*/

int lower_char(char c)
{
    if (c >= 'A' && c <= 'Z') {
        return c + 32;
    }
    return c;
}

int my_strcmp(char const *s1, char const *s2)
{
    char c1;
    char c2;

    for (int i = 0; (s1[i] != '\0') || (s2[i] != '\0'); i++){
        c1 = lower_char(s1[i]);
        c2 = lower_char(s2[i]);
        if (c1 != c2)
            return c1 - c2;
    }
    return 0;
}
