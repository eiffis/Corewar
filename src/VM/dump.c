/*
** EPITECH PROJECT, 2025
** B-CPE-200-REN-2-1-corewar-enzo.iffis
** File description:
** dump
*/

#include "corewar.h"

static
void print_byte_in_hex(unsigned char byte)
{
    char digits[16] = "0123456789ABCDEF";

    write(1, &digits[(byte / 16)], 1);
    write(1, &digits[byte % 16], 1);
}

static
void print_ascii_to_hex(unsigned char *str, int len)
{
    for (int d = 0; d < len; d++)
        print_byte_in_hex(str[d]);
    write(1, "\n", 1);
}

void dump_arena(arena_t *arena)
{
    int index = 0;

    while (1) {
        if (index + 32 > MEM_SIZE)
            break;
        print_ascii_to_hex(&arena->arena[index], 32);
        index += 32;
    }
    print_ascii_to_hex(&arena->arena[index], MEM_SIZE - index);
}
