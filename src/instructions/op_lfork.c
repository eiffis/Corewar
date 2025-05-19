/*
** EPITECH PROJECT, 2025
** B-CPE-200-REN-2-1-corewar-enzo.iffis
** File description:
** op_lfork
*/

#include "corewar.h"

void op_lfork(arena_t *arena, process_list_t *process)
{
    int position = (process->pc + process->read_args[0]) % MEM_SIZE;
    process_list_t *new_process = NULL;

    if (position < 0)
        position += MEM_SIZE;
    new_process = create_process(arena, position, process->owner_id);
    if (new_process == NULL)
        return;
    for (int i = 0; i < REG_NUMBER; i++)
        new_process->registers[i] = process->registers[i];
    process->cycles_to_wait = op_tab[process->current_opcode - 1].nbr_cycles;
}
