/*
** EPITECH PROJECT, 2024
** my_printf
** File description:
** parsing
*/

#include "my.h"

static
const func_t func[18] =
{
    {'%', &flag_purcent},
    {'i', &flags_i_and_d},
    {'d', &flags_i_and_d},
    {'o', &flag_o},
    {'x', &flag_x},
    {'X', &flag_up_x},
    {'u', &flag_u},
    {'c', &flag_c},
    {'s', &flag_s},
    {'f', &flag_f},
    {'p', &flag_p},
    {'n', &flag_n},
    {'e', &flag_e},
    {'E', &flag_up_e},
    {'g', &flag_g},
    {'G', &flag_up_g},
    {'b', &flag_b},
    {'\0', NULL},
};

int check_flag_for_str(char c)
{
    for (int i = 0; func[i].flag != '\0'; i++) {
        if (c == func[i].flag)
            return 1;
    }
    return 0;
}

char *my_str_char_cpy(char *str)
{
    char *copy;
    int i = 1;
    int k = 0;

    for (; str[i] != '\0'; i++) {
        if (check_flag_for_str(str[i]))
            break;
    }
    i++;
    copy = malloc(sizeof(char) * (i + 1));
    for (int j = 0; j <= i; j++) {
        copy[k] = str[j];
        k++;
    }
    copy[k - 1] = '\0';
    return copy;
}

args_t *create_struct(char *format, int cpt)
{
    args_t *arg = malloc(sizeof(args_t));

    (void) format;
    arg->specifier = '\0';
    arg->width = 0;
    arg->precision = -1;
    arg->size = '\0';
    arg->cpt = cpt;
    arg->nb_args = 1;
    check_args(arg, format);
    return arg;
}

int parsing(char flag, args_t *arg, va_list ap)
{
    for (int i = 0; func[i].flag != '\0'; i++) {
        if (flag == func[i].flag)
            return func[i].fct(ap, arg);
    }
    my_putchar('%');
    return -1;
}
