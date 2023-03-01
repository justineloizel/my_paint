/*
** EPITECH PROJECT, 2022
** header printf
** File description:
** head
*/

#ifndef _MYPRINTF_H_
    #define _MYPRINTF_H_
    #define ARRAY_LENGTH(x) (sizeof(x) / sizeof(*x))
    #include <stdlib.h>
    #include <unistd.h>
    #include <stdarg.h>
    #include <stdio.h>
    #include <stddef.h>

    #define UNU __attribute__((unused))

typedef struct param {
    int hashtag;
    int apo;
    int plus;
    int space;
    int minus;
    int zero;
    int padding;
    int pres;
    int error;
} params;

int my_modulo(va_list c, params param_struct, int *count);
int my_char(va_list c, params param_struct, int *count);
int my_str(va_list str, params param_struct, int *count);
int my_nbr(va_list nb, params param_struc, int *count);
int my_unsigned(va_list nb, params param_struct, int *count);
int my_tab(va_list tab, params param_struct, int *count);
int my_error_flag(va_list error, params param_struct, int *count);

int my_float(va_list nb, params param_struct, int *count);
int my_n_flag(int *count, va_list c);
int my_p_flag(va_list nb, params param_struct, int *count);
int my_e_flag(va_list nb, params param_struct, int *count);

int my_octal(va_list nb, params param_struct, int *count);
int my_hexa(va_list nb, params param_struct, int *count);
int my_binary(va_list nb, params param_struct, int *count);
int my_hexa_capital(va_list nb, params param_struct, int *count);
int my_str_non_print(va_list str, params param_struct, int *count);

int my_upe_flag(va_list nb, params param_struct, int *count);
int my_plus(int i);
int my_minus(int i);
int my_zero(int i);
int count_nb(int n, int count_stat);

int which_params(const char *format, int i, char *flag, va_list args);
int is_flag(char c);
int my_printf(const char *format, ...);
int my_putfloat(double nb, int pres);
int my_putstr_non_print(char const *str);
int my_put_unsigned_base(unsigned int, char *);
int my_put_unsigned_nbr(unsigned int nb, int pres);
int my_count_nbr_base(int nbr, char *base);
int my_putchar(char c);
int my_putstr(char const *str);
int my_strlen(char const *str);
int my_put_nbr(int nb);
int my_put_nbr_pres(int nb, int pres, int plus);
int my_put_nbr_base(int, char *);
char *my_revstr(char *);
int my_scinbr(double nb, int UP, int pres, int hashtag);
char *cut_string(char *strd, char *strf, char c);
int my_getnbr(char const *str);
params check_orders_params(char *flag, params param_struct);
int my_put_error(params param_struct, char *flag);
int my_getnbr_aft_point(char const *str);
int my_getnbr_bef_point(char const *str);
int my_puttab(char **tab);

typedef struct detect {
    char c;
    int (*fct)();
}detect_flag;

typedef struct scan_param {
    char c;
    int pos;
}scan_params;
#endif
