## ----------------------------------------------------------------------------------- ##
##                                                                                     ##
## EPITECH PROJECT - Sat, May, 2025                                                    ##
## Title           - B-CPE-200-REN-2-1-corewar-enzo.iffis                              ##
## Description     -                                                                   ##
##     Makefile                                                                        ##

NAME = corewar_bonus

## main functions ##
SRCS := $(wildcard Corewar_functions/*.c)
SRCS += corewar_raylib.c
SRCS += corewar_bonus.c

CC := gcc

BUILD_DIR := .build

OBJ = $(SRCS:%.c=.build/%.o)

CFLAGS = -Wall -Wextra -I../include -lraylib -lm -ldl -lpthread -lGL

LDFLAGS = -L../lib/my -lmy

PINK := \033[38;5;212m
GRE := \033[0;37m
PURP := \033[0;35m

all:
	@ cd ../lib/my && $(MAKE) -j --no-print-directory
	@ $(MAKE) $(NAME) -j --no-print-directory

$(NAME): $(OBJ)
	@ $(CC) -o $(NAME) $(OBJ) $(LDFLAGS) $(CFLAGS)
	@ echo -e "$(PURP)===--- $(PINK)COMPILED$(GRE) < $@ > $(PURP)---===$(GRE)"

$(BUILD_DIR)/%.o: %.c
	@ mkdir -p $(dir $@)
	@ $(CC) $(CFLAGS) -c -o $@ $< $(LDFLAGS)
	@ echo -e "$(PINK)COMPILED$(GRE) $<"

clean:
	@ cd ../lib/my && $(MAKE) clean -j --no-print-directory
	@ $(RM) $(OBJ)
	@ $(RM) *.a
	@ echo "$(PINK)CLEANED$(GRE)"

fclean: clean
	@ cd ../lib/my && $(MAKE) fclean -j --no-print-directory
	@ $(RM) $(NAME)
	@ $(RM) -r $(BUILD_DIR)
	@ $(RM) *.a
	@ echo "$(PINK)FORCE CLEANED$(GRE)"

.PHONY: clean fclean tests_run re

re: fclean
	@ $(MAKE) all -j --no-print-directory
