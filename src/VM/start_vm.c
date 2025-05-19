/*
** EPITECH PROJECT, 2025
** B-CPE-200-REN-2-1-corewar-enzo.iffis
** File description:
** start_vm
*/

#include "corewar.h"

static
void update_cycle(arena_t *arena)
{
    arena->count_cycles++;
    arena->count_cycle_to_die++;
}

static
void handle_lives_and_cycle_to_die(arena_t *arena)
{
    if (arena->nb_live >= NBR_LIVE) {
        arena->cycle_to_die -= CYCLE_DELTA;
        arena->nb_live = 0;
    }
}

static
bool should_end_game(arena_t *arena)
{
    if (arena->nb_process <= 0 || arena->cycle_to_die <= 0
        || arena->nb_process <= 0 || arena->count_cycles == arena->dump_cycles)
        return true;
    return false;
}

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

static
void reset_live_champions(arena_t *arena)
{
    for (int i = 0; i < arena->nb_champ; i++)
        arena->champ_tab[i].is_alive = false;
}

static
void cycle_to_die_reached(arena_t *arena)
{
    check_dead_process(arena, arena->count_cycles);
    reset_live_champions(arena);
    arena->count_cycle_to_die = 0;
    arena->nb_check++;
    handle_lives_and_cycle_to_die(arena);
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
        if (arena->count_cycles == arena->dump_cycles
            || (arena->game_is_over && arena->dump_cycles != -1))
            dump_arena(arena);
    }
}
