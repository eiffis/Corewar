/*
** EPITECH PROJECT, 2024
** my_strncmp.c
** File description:
** strncmp function
*/

int my_strncmp(char const *s1, char const *s2, int n)
{
    for (int i = 0; i < n && s1[i] != '\0' && (s2[i] != '\0'); i++) {
        if (s1[i] != s2[i])
            return s1[i] - s2[i];
    }
    return 0;
}
