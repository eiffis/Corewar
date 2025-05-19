##
## EPITECH PROJECT, 2024
## starting_project
## File description:
## Makefile
##

NAME = libmy.a

SRCS = my_compute_power_rec.c \
       my_compute_square_root.c \
       my_find_prime_sup.c \
       my_getnbr.c \
       my_isneg.c \
       my_is_prime.c \
       my_putchar.c \
       my_put_nbr.c \
       len_array.c \
       my_putstr.c \
       my_puterr.c \
       my_revstr.c \
       my_showmem.c \
       my_showstr.c \
       my_show_word_array.c \
       my_sort_int_array.c \
       my_strcapitalize.c \
       my_strcat.c \
       my_strcmp.c \
       my_strcpy.c \
       my_strdup.c \
       my_str_isalpha.c \
       my_str_islower.c \
       my_str_is_num.c \
       my_str_isprintable.c \
       my_str_isupper.c \
       my_strlen.c \
       my_strlowcase.c \
       my_strncat.c \
       my_strncmp.c \
       my_strncpy.c \
       my_strstr.c \
       my_str_to_word_array.c \
       my_strupcase.c \
       my_swap.c \
       my_printf.c \
       flag_f.c \
       flags_i_and_d.c \
       flag_u.c \
       my_put_float.c \
       nb_len.c \
       parsing.c \
       flag_c.c \
       flag_purcent.c \
       flag_x.c \
       flag_s.c \
       check_args.c \
       flag_p.c \
       flag_o.c \
       flag_up_x.c \
       flag_n.c \
       flag_e.c \
       flag_up_e.c \
       flag_g.c \
       flag_up_g.c \
       flag_b.c \
       list/add_end.c \
       list/add_front.c \
       list/create_list.c \
       list/del_end.c \
       list/del_front.c \
       list/del_node.c \
       open_file.c \
       cut_str.c \
       int_to_str.c \
       my_isalpha.c \
       my_isalphanum.c \
       my_size_tab.c

CC := gcc

BUILD_DIR := .build

OBJ = $(SRCS:%.c=.build/%.o)

CFLAGS = -Wall -Wextra -g -I../../include

PINK := \033[38;5;212m
GRE := \033[0;37m
PURP := \033[0;35m

all: $(NAME)
.PHONY: all

$(NAME): $(OBJ)
	@ $(AR) rc ./libmy.a $(OBJ)
	@ echo -e "$(PURP)===--- $(PINK)COMPILED$(GRE) < $@ > $(PURP)---===$(GRE)"

$(BUILD_DIR)/%.o: %.c
	@ mkdir -p $(dir $@)
	@ $(CC) $(CFLAGS) -c -o $@ $<
	@ echo -e "$(PINK)COMPILED$(GRE) $<"

clean:
	@ $(RM) $(SRC:.c=.gcda)
	@ $(RM) $(SRC:.c=.gcno)
	@ $(RM) $(OBJ) $(TOBJ)
	@ $(RM) *.0
	@ echo "$(PINK)CLEANED$(GRE)"

fclean: clean
	@ $(RM) $(NAME)
	@ $(RM) -r $(BUILD_DIR)
	@ $(RM) *.0
	@ echo "$(PINK)FORCE CLEANED $(GRE)"

.PHONY: clean fclean

re: fclean
	@ $(MAKE) all -j --no-print-directory

.PHONY: re
