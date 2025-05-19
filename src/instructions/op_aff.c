/*
** EPITECH PROJECT, 2025
** B-CPE-200-REN-2-1-corewar-enzo.iffis
** File description:
** op_aff
*/

#include "corewar.h"

void op_aff(arena_t *arena, process_list_t *process)
{
    int character = process->args[0] % 256;

    (void) arena;
    my_putchar(character);
    process->cycles_to_wait = op_tab[process->current_opcode - 1].nbr_cycles;
}
