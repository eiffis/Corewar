/*
** EPITECH PROJECT, 2025
** B-CPE-200-REN-2-1-corewar-enzo.iffis
** File description:
** op_sti
*/

#include "corewar.h"

void op_sti(arena_t *arena, process_list_t *process)
{
    int reg_val = process->args[0];
    int first_offset = process->args[1];
    int second_offset = process->args[2];

    write_int_in_memory(arena->arena, (process->pc +
        ((first_offset + second_offset) % IDX_MOD)) % MEM_SIZE, reg_val);
    process->cycles_to_wait = op_tab[process->current_opcode - 1].nbr_cycles;
}
