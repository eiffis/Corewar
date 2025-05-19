/*
** EPITECH PROJECT, 2024
** parsing_arguments.c
** File description:
** parses input arguments
*/
#include "corewar.h"

static
int get_nb_headers(int ac, char **av)
{
    int nb_headers = 0;
    header_t tmp;

    for (int i = 1; i < ac; i++) {
        if (av[i][0] == '-' && (my_strcmp(av[i], "-a") == 0 ||
            my_strcmp(av[i], "-n") == 0 || my_strcmp(av[i], "-dump") == 0))
            i++;
        else
            nb_headers += (read_header(&tmp, av[i]) == 0);
    }
    if (nb_headers < 2)
        return my_puterr(TOO_FEW_WARRIORS_ERR, -1);
    if (nb_headers > MAX_CHAMP)
        return my_puterr(TOO_MANY_WARRIORS_ERR, -1);
    return nb_headers;
}

static
void assign_id(arena_t *arena, champion_t *champion, int id)
{
    int new_id = id;

    for (int i = 0; i < MAX_CHAMP; i++) {
        if (arena->champ_tab[i].id == new_id) {
            i = 0;
            new_id++;
        }
    }
    champion->id = new_id;
}

static
int get_champion_options(arena_t *arena, arguments_t *arguments)
{
    bool valid_nb = is_uint(arguments->av[arguments->index + 1]);
    int nb = (valid_nb ? my_getnbr(arguments->av[arguments->index + 1]) : 0);

    if (my_strcmp(arguments->av[arguments->index], "-a") == 0 && valid_nb) {
        arena->champ_tab[arguments->champion_index].load_adress = nb;
        return 1;
    }
    if (my_strcmp(arguments->av[arguments->index], "-n") == 0 && valid_nb) {
        assign_id(arena, &arena->champ_tab[arguments->champion_index], nb);
        return 1;
    }
    if (!arguments->dump &&
        my_strcmp(arguments->av[arguments->index], "-dump") == 0 && valid_nb) {
        arena->dump_cycles = nb;
        arguments->dump = 1;
        return 1;
    }
    return 0;
}

static
int parse_file(arguments_t *arguments, champion_t *champion, char *file)
{
    if (read_header(&champion->header, file) == 0) {
        champion->filepath = my_strdup(file);
        arguments->champion_index++;
        return 1;
    }
    return 0;
}

static
int read_all_files(arena_t *arena, int nb_champions, int ac, char **av)
{
    arguments_t arguments = (arguments_t) {av, 0, 0, 1};

    for (; arguments.index < ac &&
        arguments.champion_index < nb_champions; arguments.index++) {
        if (arguments.index < ac - 1 &&
            get_champion_options(arena, &arguments)) {
            arguments.index++;
            continue;
        }
        if (!parse_file(&arguments,
            &arena->champ_tab[arguments.champion_index], av[arguments.index]))
            return 84;
    }
    if (arguments.champion_index == nb_champions
        && arguments.index < ac - 1)
        return my_puterr(UNRELATED_ARG_ERR, 84);
    if (!arguments.dump)
        arena->dump_cycles = -1;
    return 0;
}

static
void init_champions_to_0(arena_t *arena)
{
    for (int i = 0; i < MAX_CHAMP; i++) {
        arena->champ_tab[i].id = -1;
        arena->champ_tab[i].load_adress = 0;
        arena->champ_tab[i].pc_start = 0;
        arena->champ_tab[i].count_live = 0;
        arena->champ_tab[i].last_live_cycle = 0;
        arena->champ_tab[i].nb_process = 0;
        arena->champ_tab[i].is_alive = 1;
        arena->champ_tab[i].code = NULL;
        arena->champ_tab[i].filepath = NULL;
    }
}

int parse_arguments(arena_t *arena, int ac, char **av)
{
    int nb_champions = get_nb_headers(ac, av);

    if (nb_champions == -1)
        return 84;
    arena->nb_champ = nb_champions;
    init_champions_to_0(arena);
    if (read_all_files(arena, nb_champions, ac, av) == 84)
        return 84;
    for (int i = 0; i < nb_champions; i++) {
        if (arena->champ_tab[i].id == -1)
            assign_id(arena, &arena->champ_tab[i], 1);
    }
    return 0;
}
