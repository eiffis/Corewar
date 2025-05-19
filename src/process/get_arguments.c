/*
** EPITECH PROJECT, 2025
** B-CPE-200-REN-2-1-corewar-enzo.iffis
** File description:
** get_argument.c
*/
#include "corewar.h"

int read_value(unsigned char *buf, int size, int position)
{
    int res = 0;

    if (buf[position] & (1 << 7)) {
        for (int i = 0; i < 4 - size; i++) {
            res <<= 8;
            res |= 255;
        }
    }
    for (int i = 0; i < size; i++) {
        res <<= 8;
        res |= (unsigned char) buf[position + i];
    }
    return res;
}

static
int get_register(arena_t *arena, process_list_t *process, int index,
    int position)
{
    int reg_number = arena->arena[position] - 1;
    int value = 0;

    if (reg_number > -1 && reg_number < REG_NUMBER)
        value = process->registers[arena->arena[position] - 1];
    process->args[index] = value;
    process->read_args[index] = reg_number + 1;
    return 1;
}

static
int get_direct(arena_t *arena, process_list_t *process, int index,
    int position)
{
    process->args[index] = read_value(arena->arena,
        op_tab[process->current_opcode - 1].dir_size, position % MEM_SIZE);
    process->read_args[index] = process->args[index];
    return op_tab[process->current_opcode - 1].dir_size;
}

static
int get_indirect(arena_t *arena, process_list_t *process, int index,
    int position)
{
    int offset = 0;

    offset = read_value(arena->arena, IND_SIZE, position);
    process->read_args[index] = offset;
    if (op_tab[process->current_opcode - 1].idx_mod)
        offset %= IDX_MOD;
    if (position + offset < 0)
        offset += MEM_SIZE;
    process->args[index] = read_value(arena->arena, DIR_SIZE,
        (position + offset) % MEM_SIZE);
    return IND_SIZE;
}

static
int get_argument(arena_t *arena, process_list_t *process, int index,
    int position)
{
    if (process->arg_types[index] == T_REG)
        return get_register(arena, process, index, position);
    if (process->arg_types[index] == T_DIR)
        return get_direct(arena, process, index, position);
    if (process->arg_types[index] == T_IND)
        return get_indirect(arena, process, index, position);
    return 0;
}

int get_arguments(arena_t *arena, process_list_t *process)
{
    int offset = 1 + op_tab[process->current_opcode - 1].coding_byte;

    for (int i = 0; i < MAX_ARGS_NUMBER; i++)
        offset += get_argument(arena, process, i,
            (process->pc + offset) % MEM_SIZE);
    return offset;
}
