/*
** EPITECH PROJECT, 2025
** B-CPE-200-REN-2-1-corewar-enzo.iffis
** File description:
** create_process
*/

#include "corewar.h"

void set_data_process(process_list_t *new_process, arena_t *arena,
    int pc, int champ_id)
{
    new_process->owner_id = champ_id;
    new_process->pc = pc;
    new_process->carry = 0;
    new_process->current_opcode = 0;
    new_process->cycles_to_wait = 0;
    new_process->last_live_cycle = arena->count_cycles;
}

process_list_t *create_process(arena_t *arena, int pc, int champ_id)
{
    process_list_t *new_process = malloc(sizeof(process_list_t));

    if (!new_process)
        return NULL;
    set_data_process(new_process, arena, pc, champ_id);
    for (int i = 0; i < REG_NUMBER; i++)
        new_process->registers[i] = 0;
    new_process->registers[0] = champ_id;
    new_process->next = arena->process;
    arena->process = new_process;
    arena->nb_process++;
    for (int i = 0; i < arena->nb_champ; i++) {
        if (arena->champ_tab[i].id == champ_id) {
            arena->champ_tab[i].nb_process++;
            break;
        }
    }
    return new_process;
}
