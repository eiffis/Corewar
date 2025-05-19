/*
** EPITECH PROJECT, 2025
** B-CPE-200-REN-2-1-corewar-enzo.iffis
** File description:
** op_lld
*/

#include "corewar.h"

void op_lld(arena_t *arena, process_list_t *process)
{
    int val = process->args[0];
    int reg_idx = process->read_args[1];

    (void) arena;
    if (reg_idx >= 1 && reg_idx <= REG_NUMBER){
        process->registers[reg_idx - 1] = val;
        process->carry = (val == 0) ? 1 : 0;
    }
    process->cycles_to_wait = op_tab[process->current_opcode - 1].nbr_cycles;
}
