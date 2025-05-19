/*
** EPITECH PROJECT, 2025
** B-PSU-200-REN-2-1-minishell1-enzo.iffis
** File description:
** my_isalpha
*/

int my_isalpha(char c)
{
    if ((c >= 'A' && c <= 'Z'))
        return 0;
    if ((c >= 'a' && c <= 'z'))
        return 0;
    return 1;
}
