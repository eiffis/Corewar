/*
** EPITECH PROJECT, 2025
** B-CPE-200-REN-2-1-corewar-enzo.iffis
** File description:
** op_add
*/

#include "corewar.h"

void op_add(arena_t *arena, process_list_t *process)
{
    int first_value = process->args[0];
    int second_value = process->args[1];
    int reg_idx = process->read_args[2];

    (void) arena;
    if (reg_idx >= 1 && reg_idx <= REG_NUMBER) {
        process->registers[reg_idx - 1] = first_value + second_value;
        process->carry = (process->registers[reg_idx - 1] ? 0 : 1);
    }
    process->cycles_to_wait = op_tab[process->current_opcode - 1].nbr_cycles;
}
