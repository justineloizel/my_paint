##
## EPITECH PROJECT, 2022
## makefile printf
## File description:
## makefile printf
##

SRC =	src/conversion/flag_b.c	\
		src/conversion/flag_o.c	\
		src/conversion/flag_x.c	\
		src/conversion/flag_upx.c	\
		src/param/param_minus_plus.c		\
		src/numbers/flag_f.c	\
		src/numbers/flag_i_d.c	\
		src/numbers/flags_e.c	\
		src/numbers/flag_upe.c	\
		src/numbers/flags_u.c	\
		src/str/flag_c.c		\
		src/str/flag_mod.c		\
		src/str/flag_s.c		\
		src/str/flag_ups.c		\
		src/others/flag_n.c		\
		src/others/flag_p.c		\
		src/base/my_compute_power_rec.c	\
		src/base/my_printf.c	\
		src/base/my_put_nbr_base.c	\
		src/base/my_put_nbr.c	\
		src/base/my_put_unsigned_base.c	\
		src/base/my_put_unsigned_nbr.c	\
		src/base/my_count_nbr_base.c	\
		src/base/my_putchar.c	\
		src/base/my_putfloat.c	\
		src/base/my_putstr_non_print.c	\
		src/base/my_putstr.c	\
		src/base/my_revstr.c	\
		src/base/my_scinbr.c	\
		src/base/my_strlen.c	\
		src/base/cut_string.c	\
		src/base/scan_params.c	\
		src/base/my_getnbr.c	\
		src/base/my_get_nbr_aft_point.c \
		src/base/my_put_nbr_pres.c	\
		src/base/my_puttab.c	\
		src/str/flag_t.c	\
		src/str/my_error_flag.c


OBJ = $(SRC:.c=.o)

BUIL_DIR = build/

BLUE = \033[1;34m

.c.o:
	@ gcc -c $< -o $@ $(CFLAGS)

CFLAGS = -I include/ -Wextra -Wall

NAME = libprint.a

all: $(NAME)

$(NAME): $(OBJ)
	@ ar rc $(NAME) $(OBJ)
	@ mv $(NAME) ../
	@ mkdir -p ../../include
	@ cp include/myprintf.h ../../include
	mkdir -p $(BUIL_DIR)
	mv $(OBJ) $(BUIL_DIR)
	@ echo "$(BLUE)Compilation of libprint.a done"

clean:
	rm -rf $(BUIL_DIR)
	rm -f *~
	rm -f \#*\#
	rm -f vgcore.*

fclean: clean
	rm -f ../$(NAME)

re: 	fclean all

test_run:	$(OBJ)
	gcc -o test_units $(SRC) tests/test.c -I include/ --coverage -lcriterion
	-./test_units
	gcovr --exclude tests/
	rm *.gcno
	rm *.gcda
	rm test_units

run:
	gcc main.c -L. -lmy -I include/ -o run
	-./run

debug:	$(OBJ)
	gcc main.c $(OBJ) -I include/ -g -o debug
	valgrind ./debug

.PHONY: .SILENT lib re all test_run clean fclean test_run run
