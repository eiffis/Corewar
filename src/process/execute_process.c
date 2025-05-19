/*
** EPITECH PROJECT, 2024
** parsing_arguments.c
** File description:
** parses input arguments
*/
#include "corewar.h"

char read_coding_byte_part(char coding_byte, int i)
{
    int first = ((coding_byte & (1 << (8 - (i * 2 + 1)))) != 0);
    int second = ((coding_byte & (1 << (8 - (i * 2 + 2)))) != 0);
    char res = (first | second) != 0;

    res <<= first;
    if (res == 2)
        res <<= second;
    return res;
}

int read_coding_byte(char instruction, char coding_byte,
    args_type_t *arg_types)
{
    if (!(op_tab[(int) instruction - 1].coding_byte)) {
        for (int i = 0; i < MAX_ARGS_NUMBER; i++)
            arg_types[i] = op_tab[instruction - 1].type[i];
        return 1;
    }
    for (int i = 0; i < MAX_ARGS_NUMBER; i++) {
        arg_types[i] = read_coding_byte_part(coding_byte, i);
        if (!(arg_types[i] & op_tab[instruction - 1].type[i]) &&
            arg_types[i] != op_tab[instruction - 1].type[i])
            return 0;
    }
    return 1;
}

void execution(arena_t *arena, process_list_t *process)
{
    int offset = get_arguments(arena, process);

    (instru_tab[process->current_opcode - 1])(arena, process);
    if (op_tab[process->current_opcode - 1].offset)
        process->pc = (process->pc + offset) % MEM_SIZE;
}

void read_byte(arena_t *arena, process_list_t *process)
{
    int fail = (process->cycles_to_wait != 0);

    if (fail) {
        process->cycles_to_wait--;
        return;
    }
    if (!fail && (arena->arena[process->pc] < 1 ||
        arena->arena[process->pc] > 16))
        fail = 1;
    else
        process->current_opcode = arena->arena[process->pc];
    if (!fail && !read_coding_byte(process->current_opcode,
        arena->arena[(process->pc + 1) % MEM_SIZE], process->arg_types))
        fail = 1;
    if (fail)
        process->pc = (process->pc + 1) % MEM_SIZE;
    else
        execution(arena, process);
}

void cycle_processes(arena_t *arena)
{
    process_list_t *tmp = arena->process;

    for (; tmp != NULL; tmp = tmp->next)
        read_byte(arena, tmp);
}
