/*
** EPITECH PROJECT, 2025
** B-CPE-200-REN-2-1-corewar-enzo.iffis
** File description:
** corewar_bonus
*/

#ifndef INCLUDED_COREWAR_BONUS_H
    #define INCLUDED_COREWAR_BONUS_H
    #include "corewar.h"
    #include "raylib.h"

typedef enum {
    CHAMP_COLOR_1 = 0,
    CHAMP_COLOR_2,
    CHAMP_COLOR_3,
    CHAMP_COLOR_4,
    MAX_CHAMP_COLORS
} champ_color_t;

void launch_visualizer(arena_t *arena);
void draw_champ_name(arena_t *arena);
void draw_arena(arena_t *arena);
void draw_live_state(arena_t *arena);
void draw_nb_process(arena_t *arena);
void draw_cycles(arena_t *arena);
void update_cycle(arena_t *arena);
void handle_lives_and_cycle_to_die(arena_t *arena);
bool should_end_game(arena_t *arena);
void reset_live_champions(arena_t *arena);
void cycle_to_die_reached(arena_t *arena);
#endif
