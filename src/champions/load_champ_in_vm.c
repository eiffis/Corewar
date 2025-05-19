/*
** EPITECH PROJECT, 2025
** B-CPE-200-REN-2-1-corewar-enzo.iffis
** File description:
** load_champ_in_vm
*/

#include "corewar.h"

unsigned char convert_cond_byte(char hex_byte[], int i, unsigned char byte)
{
    if (hex_byte[i] >= 'a' && hex_byte[i] <= 'f')
            byte |= hex_byte[i] - 'a' + 10;
        else if (hex_byte[i] >= 'A' && hex_byte[i] <= 'F')
            byte |= hex_byte[i] - 'A' + 10;
    return byte;
}

unsigned char turn_to_byte(char hex_byte[], int i, unsigned char byte)
{
    if (hex_byte[i] >= '0' && hex_byte[i] <= '9')
        byte |= hex_byte[i] - '0';
    else {
        byte = convert_cond_byte(hex_byte, i, byte);
        }
    return byte;
}

static
unsigned char hex_to_byte(char *hex_str, int pos)
{
    char hex_byte[3];
    unsigned char byte = 0;

    hex_byte[0] = hex_str[pos];
    hex_byte[1] = hex_str[pos + 1];
    hex_byte[2] = '\0';
    for (int i = 0; i < 2; i++) {
        byte <<= 4;
        byte = turn_to_byte(hex_byte, i, byte);
    }
    return byte;
}

void champ_in_vm(int code_size, arena_t *arena, champion_t *champion,
    int load_adress)
{
    for (int j = 0; j < code_size; j++){
        arena->arena[(load_adress + j) % MEM_SIZE] =
            hex_to_byte(champion->code, j * 2);
    }
}

void load_champions(arena_t *arena)
{
    int spacing = MEM_SIZE / arena->nb_champ;
    int load_adress = 0;
    champion_t *champion;
    int code_size = 0;

    for (int i = 0; i < arena->nb_champ; i++){
        champion = &arena->champ_tab[i];
        load_adress = i * spacing;
        if (champion->load_adress != 0)
            load_adress = champion->load_adress;
        champion->pc_start = load_adress;
        code_size = champion->header.prog_size;
        champ_in_vm(code_size, arena, champion, load_adress);
        create_process(arena, load_adress, champion->id);
    }
}
