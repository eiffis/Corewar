/*
** EPITECH PROJECT, 2024
** revstr
** File description:
** reverse string
*/

char *my_revstr(char *str)
{
    char tmp;
    int j = 0;

    for (; str[j] != '\0'; j++);
    j--;
    for (int i = 0; i <= j; i++) {
        tmp = str[j];
        str[j] = str[i];
        str[i] = tmp;
        j--;
    }
    return str;
}
