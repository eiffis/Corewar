/*
** EPITECH PROJECT, 2024
** my_h
** File description:
** include lib
*/

#ifndef MY_H
    #define MY_H

    #include <stddef.h>
    #include <stdarg.h>
    #include <stdlib.h>
    #include <limits.h>
    #include <fcntl.h>
    #include <stdio.h>
    #include <unistd.h>
    #include "my_printf.h"
    #include "list.h"

int my_isalphanum(char c);
int my_isalpha(char c);
void my_putchar(char c);
int len_array(char **array);
int my_isneg(int nb);
int size_tab(char *tab);
int my_put_nbr(int nb);
int my_put_l_nbr(long int nb);
int my_put_ll_nbr(long long int nb);
int my_put_h_nbr(int nb);
void my_swap(int *a, int *b);
int my_putstr(char const *str);
int my_puterr(char const *str, int error_code);
int my_strlen(char const *str);
int my_getnbr(char const *str);
void my_sort_int_array(int *tab, int size);
int my_compute_power_rec(int nb, int power);
int my_compute_square_root(int nb);
int my_is_prime(int nb);
int my_find_prime_sup(int nb);
char *my_strcpy(char *dest, char const *src);
char *my_strncpy(char *dest, char const *src, int n);
char *my_revstr(char *str);
char *my_strstr(char *str, char const *to_find);
int my_strcmp(char const *s1, char const *s2);
int my_strncmp(char const *s1, char const *s2, int n);
char *my_strupcase(char *str);
char *my_strlowcase(char *str);
char *my_strcapitalize(char *str);
int my_str_isalpha(char const *str);
int my_str_isnum(char const *str);
int my_str_islower(char const *str);
int my_str_isupper(char const *str);
int my_str_isprintable(char const *str);
int my_showstr(char const *str);
int my_showmem(char const *str, int size);
char *my_strcat(char *dest, char const *src);
char *my_strncat(char *dest, char const *src, int nb);
char *my_strdup(char const *src);
char **my_str_to_word_array(char *str, char *separator);
int my_show_word_array(char *const *tab);
int verif_overflow(int nb, int cpt);
int count_sep(char const *src, int start);
int my_word_len(char const *src, int start);
int my_tab_len(char const *src);
char *my_strndup_cus(char const *src, int start);
void put_overflow(void);
void sort_array(int *array, int *i, int *j);
int flag_f(va_list ap, args_t *arg);
int flag_u(va_list ap, args_t *arg);
int flags_i_and_d(va_list ap, args_t *arg);
int my_put_float(double nb, int precision);
int my_put_bl_float(long double nb, int precision);
int flag_c(va_list ap, args_t *arg);
int flag_purcent(va_list ap, args_t *arg);
int flag_x(va_list ap, args_t *arg);
int flag_up_x(va_list ap, args_t *arg);
int flag_s(va_list ap, args_t *arg);
int flag_p(va_list ap, args_t *arg);
int flag_o(va_list ap, args_t *arg);
int flag_n(va_list ap, args_t *arg);
int flag_e(va_list ap, args_t *arg);
int flag_up_e(va_list ap, args_t *arg);
int flag_g(va_list ap, args_t *arg);
int flag_up_g(va_list ap, args_t *arg);
int flag_b(va_list ap, args_t *arg);
int put_science(double nb, int precision);
int put_up_science(double nb, int precision);
int my_put_hexa(va_list ap, args_t *arg);
int my_put_up_hexa(long int nb);
int nb_len(int nb);
int hnb_len(int nb);
int lnb_len(long int nb);
char *my_str_char_cpy(char *str);
args_t *check_args(args_t *arg, char const *str);
char *open_file(char *filepath);
int get_size_file(char *filepath);
char *cut_str(char *src, char delim);
char *int_to_str(int score);
char *my_strcatdup(char *s1, char *s2);
char *int_to_str_cus(int nb);

#endif //MY_H
