##
## EPITECH PROJECT, 2025
## Corewar
## File description:
## Makefile
##

NAME = corewar

## main functions ##
SRCS = src/main.c
SRCS += src/helper/printhelper.c
SRCS += src/parsing/utils.c
SRCS += src/parsing/parsing_arguments.c
SRCS += src/parsing/parse_code_champion.c
SRCS += src/VM/init_arena.c
SRCS += src/VM/start_vm.c
SRCS += src/VM/dump.c
SRCS += src/VM/free_arena.c
SRCS += src/process/check_dead_process.c
SRCS += src/process/create_process.c
SRCS += src/process/execute_process.c
SRCS += src/process/get_arguments.c
SRCS += src/champions/load_champ_in_vm.c
SRCS += src/op.c
SRCS += src/instructions/instru.c
SRCS += src/instructions/op_live.c
SRCS += src/instructions/op_ld.c
SRCS += src/instructions/op_st.c
SRCS += src/instructions/op_add.c
SRCS += src/instructions/op_sub.c
SRCS += src/instructions/op_and.c
SRCS += src/instructions/op_or.c
SRCS += src/instructions/op_xor.c
SRCS += src/instructions/op_zjmp.c
SRCS += src/instructions/op_ldi.c
SRCS += src/instructions/op_sti.c
SRCS += src/instructions/op_fork.c
SRCS += src/instructions/op_lld.c
SRCS += src/instructions/op_lldi.c
SRCS += src/instructions/op_lfork.c
SRCS += src/instructions/op_aff.c
SRCS += src/instructions/utils_instru.c

CC := gcc

BUILD_DIR := .build

OBJ = $(SRCS:%.c=.build/%.o)

CFLAGS = -Wall -Wextra -I./include -g

LDFLAGS = -L./lib/my -lmy

PINK := \033[38;5;212m
GRE := \033[0;37m
PURP := \033[0;35m

all:
	@ cd lib/my && $(MAKE) -j --no-print-directory
	@ $(MAKE) $(NAME) -j --no-print-directory

$(NAME): $(OBJ)
	@ $(CC) -o $(NAME) $(OBJ) $(LDFLAGS) $(CFLAGS) $(NCFLAGS)
	@ echo -e "$(PURP)===--- $(PINK)COMPILED$(GRE) < $@ > $(PURP)---===$(GRE)"

$(BUILD_DIR)/%.o: %.c
	@ mkdir -p $(dir $@)
	@ $(CC) $(CFLAGS) -c -o $@ $< $(LDFLAGS)
	@ echo -e "$(PINK)COMPILED$(GRE) $<"

tests_run:
	echo "test"

clean:
	@ cd lib/my && $(MAKE) clean -j --no-print-directory
	@ $(RM) $(SRC:.c=.gcda)
	@ $(RM) $(SRC:.c=.gcno)
	@ $(RM) $(OBJ) $(TOBJ)
	@ $(RM) *.a
	@ echo "$(PINK)CLEANED$(GRE)"

fclean: clean
	@ cd lib/my && $(MAKE) fclean -j --no-print-directory
	@ $(RM) $(NAME)
	@ $(RM) -r $(BUILD_DIR)
	@ $(RM) *.a
	@ echo "$(PINK)FORCE CLEANED $(GRE)"

.PHONY: clean fclean

re: fclean
	@ cd lib/my && $(MAKE) fclean -j --no-print-directory
	@ $(MAKE) all -j --no-print-directory

.PHONY: re
