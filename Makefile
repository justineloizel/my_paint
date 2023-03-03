##
## EPITECH PROJECT, 2022
## lib
## File description:
## Makefile
##

MAKEFLAGS += -silent
CC = gcc

VPATH += src/

SRC += paint.c

CFLAGS = -I include/ -Wall -Wextra

LDFLAGS = -L lib/

BUILD_DIR = build/

NAME = paint

DEBUG ?= 1
ifeq ($(DEBUG), 1)
	CFLAGS += -g
endif

$(BUILD_DIR)%.o: %.c
	@mkdir -p $(@D)
	#@echo "  CC       $<      $@"
	@$(CC) $(CFLAGS) -c $< -o $@

OBJ = $(SRC:%.c=$(BUILD_DIR)%.o)

all:	$(NAME)

$(NAME):	$(OBJ)
	@ echo "$(BLUE)Compilation of $(NAME)...$(NC)"
	$(CC) $(OBJ) -o $(NAME) $(LDFLAGS)
	@ echo "$(GREEN)$(NAME) created$(NC)"

clean:
	make clean -C lib/my/
	make clean -C lib/my_printf/
	@ echo "$(RED)lib clean"
	rm -rf $(BUILD_DIR)
	rm -f $(OBJ)
	rm -f *~
	rm -f \#*\#
	rm -f vgcore.*
	@ echo "$(RED)clean successful !"

fclean: clean
	make fclean -C lib/my/
	make fclean -C lib/my_printf/
	rm -f $(NAME)
	@ echo "$(RED)fclean successful !$(NC)"

re: 	fclean all

.PHONY: all clean fclean re .SILENT

BLUE = \033[1;34m
RED = \033[1;31m
GREEN = \033[1;32m
NC = \033[0m
