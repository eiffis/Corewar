/*
** EPITECH PROJECT, 2025
** B-CPE-200-REN-2-1-corewar-enzo.iffis
** File description:
** op_zjmp
*/

#include "corewar.h"

void op_zjmp(arena_t *arena, process_list_t *process)
{
    int offset = process->args[0] % IDX_MOD;

    (void) arena;
    if (process->carry == 1){
        process->pc = (process->pc + offset) % MEM_SIZE;
        if (process->pc < 0)
            process->pc += MEM_SIZE;
    } else {
        process->pc = (process->pc + 3) % MEM_SIZE;
    }
    process->cycles_to_wait = op_tab[process->current_opcode - 1].nbr_cycles;
}
