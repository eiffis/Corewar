/*
** EPITECH PROJECT, 2025
** B-CPE-200-REN-2-1-corewar-enzo.iffis
** File description:
** op_lldi
*/

#include "corewar.h"

void op_lldi(arena_t *arena, process_list_t *process)
{
    int first_val = process->args[0];
    int second_val = process->args[1];
    int position = (process->pc + first_val + second_val) % MEM_SIZE;
    int reg_idx = process->read_args[2];

    if (position < 0)
        position += MEM_SIZE;
    if (reg_idx <= 1 && reg_idx >= 16) {
        process->registers[reg_idx - 1] =
            read_value(arena->arena, REG_SIZE, position);
        process->carry = (process->registers[reg_idx - 1] ? 0 : 1);
    }
    process->cycles_to_wait = op_tab[process->current_opcode - 1].nbr_cycles;
}
