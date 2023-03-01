/*
** EPITECH PROJECT, 2022
** .h for include lib
** File description:
** up
*/

#ifndef _MY_H_
    #define _MY_H_

    #define _SIZETAB(X) (sizeof(X) / sizeof(X[0]))
    int my_putchar(char c);
    char *my_strstr(char *str, char const *to_find);
    int my_isneg(int nb);
    int my_strcmp(char const *s1, char const *s2);
    int my_put_nbr(int nb);
    int my_strncmp(char const *s1, char const *s2, int n);
    void my_swap(int *a, int *b);
    char *my_strupcase(char *str);
    int my_putstr(char const *str);
    char *my_strlowcase(char *str);
    int my_strlen(char const *str);
    char *my_strcapitalize(char *str);
    int my_getnbr(char const *str);
    int my_str_isalpha(char const *str);
    void my_sort_int_array(int *tab, int size);
    int my_str_isnum(char const *str);
    int my_compute_power_rec(int nb, int power);
    int my_str_islower(char const *str);
    int my_compute_square_root(int nb);
    int my_str_isupper(char const *str);
    int my_is_prime(int nb);
    int my_str_isprintable(char const *str);
    int my_find_prime_sup(int nb);
    int my_showstr(char const *str);
    char *my_strcpy(char *dest, char const *src);
    int my_showmem(char const *str, int size);
    char *my_strncpy(char *dest, char const *src, int n);
    char *my_strcat(char *dest, char const *src);
    char *my_revstr(char *str);
    char *my_strncat(char *dest, char const *src, int nb);
    char *my_strcatn(char *dest, char const *src, int check);
    int my_show_word_array(char * const *tab);
    char *my_strdup(char const *src);
    char *my_strcatn(char *dest, char const *src, int check);
    char **my_str_to_word_array(char const *str, char *separators);
    char *concat_params(int ac, char **av);
    int is_alphanum(char c);
    int count_word(char const *str);
    int boucle2(char *str, char const *to_find, int i);
    char my_getop(char *str);
    int is_alpha(char c);
    int my_nbletter(char *str);
    char **my_dellign(char **tab, int key_del);
    void my_puterror(char *error);
    char **my_addlign(char **tab, char *str, int key);
    int my_puttab(char **tab);
    int my_arrsize(char const **arr);
    char *my_putnbrm(long int nbr);
    char *my_putnbrm_2d(long int nbr);
    void free_tab(char **tab);
    int my_str_isalphanum(char const *str);
    int is_separator(char const *separators, char letter);
#endif /* _MY_H_ */
