/*
** EPITECH PROJECT, 2025
** B-PSU-200-REN-2-1-minishell2-enzo.iffis
** File description:
** len_array
*/
#include <stdlib.h>

int len_array(char **array)
{
    int count = 0;

    for (int i = 0; array[i] != NULL; i++){
        count++;
    }
    return count;
}
