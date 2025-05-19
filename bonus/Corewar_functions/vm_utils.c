/*
** EPITECH PROJECT, 2025
** B-CPE-200-REN-2-1-corewar-enzo.iffis
** File description:
** VM_utils
*/
#include "corewar.h"

void update_cycle(arena_t *arena)
{
    arena->count_cycles++;
    arena->count_cycle_to_die++;
}

void handle_lives_and_cycle_to_die(arena_t *arena)
{
    if (arena->nb_live >= NBR_LIVE) {
        arena->cycle_to_die -= CYCLE_DELTA;
        arena->nb_live = 0;
    }
}

bool should_end_game(arena_t *arena)
{
    if (arena->nb_process <= 0 || arena->cycle_to_die <= 0
        || arena->nb_process <= 0 || arena->count_cycles == arena->dump_cycles)
        return true;
    return false;
}

void reset_live_champions(arena_t *arena)
{
    for (int i = 0; i < arena->nb_champ; i++)
        arena->champ_tab[i].is_alive = false;
}

void cycle_to_die_reached(arena_t *arena)
{
    check_dead_process(arena, arena->count_cycles);
    reset_live_champions(arena);
    arena->count_cycle_to_die = 0;
    arena->nb_check++;
    handle_lives_and_cycle_to_die(arena);
}
