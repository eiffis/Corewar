/*
** EPITECH PROJECT, 2025
** B-CPE-200-REN-2-1-corewar-enzo.iffis
** File description:
** op_st
*/

#include "corewar.h"

void op_st(arena_t *arena, process_list_t *process)
{
    int value = process->args[0];
    int index = process->read_args[1];
    args_type_t type = process->arg_types[1];

    if (type == T_REG && index >= 1 && index <= REG_NUMBER)
        process->registers[index - 1] = value;
    if (type == T_IND)
        write_int_in_memory(arena->arena, (process->pc +
            (index % IDX_MOD)) % MEM_SIZE, value);
    process->cycles_to_wait = op_tab[process->current_opcode - 1].nbr_cycles;
}
