/*
** EPITECH PROJECT, 2025
** B-CPE-200-REN-2-1-corewar-enzo.iffis
** File description:
** op_or
*/

#include "corewar.h"

void op_or(arena_t *arena, process_list_t *process)
{
    int first_arg = process->args[0];
    int second_arg = process->args[1];
    int third_arg = process->read_args[2];
    int res = first_arg | second_arg;

    (void) arena;
    if (!res)
        process->carry = 1;
    else
        process->carry = 0;
    if (third_arg > 0 && third_arg <= 16)
        process->registers[third_arg - 1] = res;
    process->cycles_to_wait = op_tab[process->current_opcode - 1].nbr_cycles;
}
