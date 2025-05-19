/*
** EPITECH PROJECT, 2024
** strlen
** File description:
** return lenght of string
*/

int my_strlen(char const *str)
{
    int cpt = 0;

    for (int i = 0; str[i] != '\0'; i++)
        cpt++;
    return cpt;
}
