/*
** EPITECH PROJECT, 2025
** B-CPE-200-REN-2-1-corewar-enzo.iffis
** File description:
** init_arena
*/

#include "corewar.h"


void init_arena(arena_t *arena)
{
    for (int i = 0; i < MEM_SIZE; i++)
        arena->arena[i] = 0;
    arena->count_cycle_to_die = 0;
    arena->count_cycles = 0;
    arena->cycle_to_die = CYCLE_TO_DIE;
    arena->game_is_over = false;
    arena->last_champ_alive = 0;
    arena->nb_champ = 0;
    arena->nb_live = 0;
    arena->nb_process = 0;
    arena->nb_check = 0;
    arena->new_process_id = 1;
    arena->process = NULL;
}
