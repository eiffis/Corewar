/*
** EPITECH PROJECT, 2025
** B-CPE-200-REN-2-1-corewar-enzo.iffis
** File description:
** start_vm
*/

#include "corewar.h"
#include "../corewar_bonus.h"

void print_winner(arena_t *arena)
{
    int winner_id = arena->last_champ_alive;
    champion_t *winner;

    if (winner_id >= 0 && winner_id < arena->nb_champ){
        winner = &arena->champ_tab[winner_id];
        my_putstr("The player ");
        my_put_nbr(winner->id);
        my_putchar('(');
        my_putstr(winner->header.prog_name);
        my_putstr(") has won\n");
    }
    return;
}

void start_game(arena_t *arena)
{
    load_champions(arena);
    while (!arena->game_is_over){
        cycle_processes(arena);
        update_cycle(arena);
        if (arena->count_cycle_to_die >= arena->cycle_to_die)
            cycle_to_die_reached(arena);
        if (should_end_game(arena)) {
            arena->game_is_over = true;
            print_winner(arena);
        }
        if (arena->count_cycles == arena->dump_cycles)
            dump_arena(arena);
    }
}
