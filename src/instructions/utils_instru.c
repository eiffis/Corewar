/*
** EPITECH PROJECT, 2025
** B-CPE-200-REN-2-1-corewar-enzo.iffis
** File description:
** utils_instru
*/

#include "corewar.h"

int read_direct_value(unsigned char *arena, int pos)
{
    int res = 0;

    for (int i = 0; i < 4; i++){
        res <<= 8;
        res |= (unsigned char)arena[(pos + i) % MEM_SIZE];
    }
    return res;
}

short read_direct_value2(unsigned char *arena, int pos)
{
    short res = 0;

    res |= (unsigned char)arena[pos % MEM_SIZE] << 8;
    res |= (unsigned char)arena[(pos + 1) % MEM_SIZE];
    return res;
}

int get_value_arg(process_list_t *process, unsigned char *arena,
    int type, int value)
{
    int address;

    if (type == T_REG)
        return process->registers[value - 1];
    if (type == T_DIR)
        return value;
    if (type == T_IND){
        address = (process->pc + (value % IDX_MOD)) % MEM_SIZE;
        if (address < 0)
            address += MEM_SIZE;
        return read_direct_value(arena, address);
    }
    return 0;
}

int get_big_value_arg(process_list_t *process, unsigned char *arena,
    int type, int value)
{
    int address;

    if (type == T_REG)
        return process->registers[value - 1];
    if (type == T_DIR)
        return value;
    if (type == T_IND){
        address = (process->pc + value) % MEM_SIZE;
        if (address < 0)
            address += MEM_SIZE;
        return read_direct_value(arena, address);
    }
    return 0;
}

void write_int_in_memory(unsigned char *arena, int address, int value)
{
    int offset = 0;

    for (int i = 0; i < REG_SIZE; i++){
        offset = (address + REG_SIZE - 1 - i) % MEM_SIZE;
        if (offset < 0)
            offset += MEM_SIZE;
        arena[offset] = (value >> (8 * i)) & 0xFF;
    }
}
