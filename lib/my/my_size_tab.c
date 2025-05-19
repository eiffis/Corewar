/*
** EPITECH PROJECT, 2025
** B-PSU-200-REN-2-1-minishell1-enzo.iffis
** File description:
** my_size_tab
*/

int size_tab(char *tab)
{
    int count = 0;

    for (int i = 0; tab[i] != '\0'; i++)
        count++;
    return count;
}
