/*
** EPITECH PROJECT, 2025
** B-CPE-200-REN-2-1-corewar-enzo.iffis
** File description:
** corewar
*/

#ifndef INCLUDED_COREWAR_H
    #include "op.h"
    #include "my.h"
    #include <sys/types.h>
    #include <sys/stat.h>
    #include <fcntl.h>
    #include <stdlib.h>
    #include <unistd.h>
    #include <stdbool.h>
    #define INCLUDED_COREWAR_H
    #define MAX_CHAMP 4
    #define NOT_A_COR_FILE_ERR "INIT: not a .cor file\n"
    #define UNRELATED_ARG_ERR "INIT: arg aren't relate to any warrior\n"
    #define WRONG_MAGIC_ERR "INIT: magic isn't right\n"
    #define INVALID_HEADER_ERR "INIT: Header error\n"
    #define TOO_FEW_WARRIORS_ERR "INIT: Too few warrior\n"
    #define TOO_MANY_WARRIORS_ERR "INIT: Too many warrior\n"
    #define TOO_MANY_ARGUMENTS_ERR "INIT: Too much arg\n"

typedef struct arguments_s {
    char **av;
    int dump;
    int champion_index;
    int index;
} arguments_t;

typedef struct champion_s {
    header_t header;
    char *code;
    char *filepath;
    int id;
    int load_adress;
    int pc_start;
    int count_live;
    int last_live_cycle;
    int nb_process;
    bool is_alive;
}champion_t;

typedef struct process_list_s {
    int owner_id;
    int registers[REG_NUMBER];
    int pc;
    int carry;
    int current_opcode;
    args_type_t arg_types[MAX_ARGS_NUMBER];
    int read_args[MAX_ARGS_NUMBER];
    int args[MAX_ARGS_NUMBER];
    int cycles_to_wait;
    int last_live_cycle;
    struct process_list_s *next;
}process_list_t;

typedef struct arena_s {
    champion_t champ_tab[MAX_CHAMP];
    unsigned char arena[MEM_SIZE];
    int nb_champ;
    process_list_t *process;
    int nb_process;
    int nb_live;
    int new_process_id;
    int count_cycles;
    int cycle_to_die;
    int count_cycle_to_die;
    int nb_check;
    int last_champ_alive;
    int dump_cycles;
    bool game_is_over;
}arena_t;

typedef void (*instru_t)(arena_t *, process_list_t *);
extern const instru_t instru_tab[16];

void op_live(arena_t *arena, process_list_t *process);
void op_ld(arena_t *arena, process_list_t *process);
void op_st(arena_t *arena, process_list_t *process);
void op_add(arena_t *arena, process_list_t *process);
void op_sub(arena_t *arena, process_list_t *process);
void op_and(arena_t *arena, process_list_t *process);
void op_or(arena_t *arena, process_list_t *process);
void op_xor(arena_t *arena, process_list_t *process);
void op_zjmp(arena_t *arena, process_list_t *process);
void op_ldi(arena_t *arena, process_list_t *process);
void op_sti(arena_t *arena, process_list_t *process);
void op_fork(arena_t *arena, process_list_t *process);
void op_lld(arena_t *arena, process_list_t *process);
void op_lldi(arena_t *arena, process_list_t *process);
void op_lfork(arena_t *arena, process_list_t *process);
void op_aff(arena_t *arena, process_list_t *process);

void print_helper(char const *filepath);
int parse_arguments(arena_t *arena, int ac, char **av);
int endian_to_endian(int nb, int nbbytes);
int read_header(header_t *head, char *file);
int is_in_str(char character, char *str);
int is_uint(char *str);
void check_dead_process(arena_t *arena, int current_cycle);
void init_arena(arena_t *arena);
void print_winner(arena_t *arena);
void start_game(arena_t *arena);
char *read_champion_code(char const *filepath, int *code_size);
void load_champions(arena_t *arena);
process_list_t *create_process(arena_t *arena, int pc, int champ_id);
void cycle_processes(arena_t *arena);
int read_direct_value(unsigned char *arena, int pos);
short read_direct_value2(unsigned char *arena, int pos);
void write_int_in_memory(unsigned char *arena, int address, int value);
int get_big_value_arg(process_list_t *process, unsigned char *arena,
    int type, int value);
int get_value_arg(process_list_t *process, unsigned char *arena,
    int type, int value);
int get_arguments(arena_t *arena, process_list_t *process);
void dump_arena(arena_t *arena);
int read_value(unsigned char *buf, int size, int position);
void free_arena(arena_t *arena);
#endif
