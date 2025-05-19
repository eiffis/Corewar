/*
** EPITECH PROJECT, 2025
** B-CPE-200-REN-2-1-corewar-enzo.iffis
** File description:
** main
*/
#include "../include/corewar.h"

int main(int ac, char **av)
{
    arena_t arena;

    if (av[1] && my_strcmp(av[1], "-h") == 0){
        print_helper("src/helper/helper.txt");
        return 0;
    }
    init_arena(&arena);
    if (parse_arguments(&arena, ac, av) == 84)
        return 84;
    for (int i = 0; i < arena.nb_champ; i++) {
        arena.champ_tab[i].code =
            read_champion_code(arena.champ_tab[i].filepath,
            &arena.champ_tab[i].header.prog_size);
        if (!arena.champ_tab[i].code)
            return 84;
    }
    start_game(&arena);
    free_arena(&arena);
    return 0;
}
