/*
** EPITECH PROJECT, 2025
** B-CPE-200-REN-2-1-corewar-enzo.iffis
** File description:
** free_arena
*/
#include "corewar.h"

void free_processes(arena_t *arena)
{
    process_list_t *tmp = arena->process;
    process_list_t *tmp2 = NULL;

    while (tmp) {
        tmp2 = tmp->next;
        free(tmp);
        tmp = tmp2;
    }
}

void free_champions(arena_t *arena)
{
    for (int i = 0; i < MAX_CHAMP; i++) {
        if (arena->champ_tab[i].code)
            free(arena->champ_tab[i].code);
        if (arena->champ_tab[i].filepath)
            free(arena->champ_tab[i].filepath);
    }
}

void free_arena(arena_t *arena)
{
    free_processes(arena);
    free_champions(arena);
}
