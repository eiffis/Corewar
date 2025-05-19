/*
** EPITECH PROJECT, 2025
** B-CPE-200-REN-2-1-corewar-enzo.iffis
** File description:
** op_live
*/

#include "corewar.h"

void print_live(int id, char *name)
{
    my_putstr("The player ");
    my_put_nbr(id);
    my_putchar('(');
    my_putstr(name);
    my_putstr(") is alive\n");
}

void op_live(arena_t *arena, process_list_t *process)
{
    int arg = process->args[0];

    arena->nb_live++;
    process->last_live_cycle = arena->count_cycles;
    for (int i = 0; i < arena->nb_champ; i++){
        if (arena->champ_tab[i].id == arg){
            arena->champ_tab[i].count_live++;
            arena->champ_tab[i].last_live_cycle = arena->count_cycles;
            arena->last_champ_alive = i;
            arena->champ_tab[i].is_alive = true;
            print_live(arena->champ_tab[i].id,
                arena->champ_tab[i].header.prog_name);
            process->last_live_cycle = arena->count_cycles;
            break;
        }
    }
    process->cycles_to_wait = op_tab[process->current_opcode - 1].nbr_cycles;
}
