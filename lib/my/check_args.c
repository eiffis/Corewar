/*
** EPITECH PROJECT, 2024
** printf
** File description:
** check_args
*/

#include "my.h"

int check_arg_size(args_t *arg, char *str_args)
{
    if (str_args[0] == 'l') {
        arg->size = 'l';
        arg->nb_args++;
        return 1;
    }
    if (str_args[0] == 'h') {
        arg->size = 'h';
        arg->nb_args++;
        return 1;
    }
    if (str_args[0] == 'L') {
        arg->size = 'L';
        arg->nb_args++;
        return 1;
    }
    return 0;
}

int check_specifier(args_t *arg, char *str_args)
{
    if (str_args[0] == '#') {
        arg->specifier = '#';
        arg->nb_args++;
        str_args++;
        return 1;
    }
    return 0;
}

int put_precision(args_t *arg, char *str_args)
{
    arg->precision = str_args[0] - 48;
    arg->nb_args++;
    return 0;
}

args_t *check_args(args_t *arg, char const *str)
{
    char *str_args = my_strdup(str);

    check_specifier(arg, str_args);
    if (str_args[0] > ('0') && str_args[0] <= '9') {
        if (str_args[1] > ('0') && str_args[1] <= '9')
            return arg;
        arg->width = str_args[0] - 48;
        str_args++;
        arg->nb_args++;
    }
    if (str_args[0] == '.') {
        str_args++;
        arg->nb_args++;
        if (str_args[0] >= 0 + 48 && str_args[0] <= 9 + 48) {
            put_precision(arg, str_args);
        } else
            return arg;
    }
    check_arg_size(arg, str_args);
    return arg;
}
