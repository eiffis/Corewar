/*
** EPITECH PROJECT, 2025
** B-CPE-200-REN-2-1-corewar-enzo.iffis
** File description:
** check_dead_process
*/

#include "corewar.h"

process_list_t *handle_process_life(arena_t *arena, process_list_t *prev,
    process_list_t *current, int current_cycle)
{
    int diff = current_cycle - current->last_live_cycle;
    int champion_id = current->owner_id;
    int is_dead = diff >= arena->cycle_to_die;
    process_list_t *next = current->next;

    if (is_dead) {
        if (prev)
            prev->next = next;
        else
            arena->process = next;
        arena->nb_process--;
        if (champion_id >= 0 && champion_id < arena->nb_champ)
            arena->champ_tab[champion_id].nb_process--;
        free(current);
        return prev;
    } else {
        return current;
    }
}

void check_dead_process(arena_t *arena, int current_cycle)
{
    process_list_t *current = arena->process;
    process_list_t *prev = NULL;
    process_list_t *next;

    while (current) {
        next = current->next;
        prev = handle_process_life(arena, prev, current, current_cycle);
        current = next;
    }
}
