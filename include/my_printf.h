/*
** EPITECH PROJECT, 2024
** my_printf
** File description:
** my_printf
*/

#ifndef MY_PRINTF_H_
    #define MY_PRINTF_H_

    #include <stdarg.h>

typedef struct args_s {
    char specifier;
    int width;
    int precision;
    char size;
    int cpt;
    int nb_args;
} args_t;

typedef struct func_s {
    char flag;
    int (*fct) (va_list ap, args_t *arg);
} func_t;

int my_printf(char *format, ...);
int parsing(char flag, args_t *arg, va_list ap);
args_t *create_struct(char *format, int cpt);

#endif
