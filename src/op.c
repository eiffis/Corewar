/*
** EPITECH PROJECT, 2025
** B-CPE-200-REN-2-1-corewar-enzo.iffis
** File description:
** op
*/

#include "corewar.h"

const op_t op_tab[] = {
    {1, {T_DIR, 0, 0, 0}, 1, 10, 0, 4, 1, 0},
    {2, {T_DIR | T_IND, T_REG, 0, 0}, 2, 5, 1, 4, 1, 1},
    {2, {T_REG, T_IND | T_REG, 0, 0}, 3, 5, 1, 4, 1, 1},
    {3, {T_REG, T_REG, T_REG, 0}, 4, 10, 1, 4, 1, 0},
    {3, {T_REG, T_REG, T_REG, 0}, 5, 10, 1, 4, 1, 0},
    {3, {T_REG | T_DIR | T_IND, T_REG | T_IND | T_DIR, T_REG, 0},
        6, 6, 1, 4, 1, 0},
    {3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG, 0},
        7, 6, 1, 4, 1, 0},
    {3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG, 0},
        8, 6, 1, 4, 1, 0},
    {1, {T_DIR, 0, 0, 0}, 9, 20, 0, 2, 0, 0},
    {3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG, 0},
        10, 25, 1, 2, 1, 1},
    {3, {T_REG, T_REG | T_DIR | T_IND, T_DIR | T_REG, 0},
        11, 25, 1, 2, 1, 1},
    {1, {T_DIR, 0, 0, 0}, 12, 800, 0, 2, 1, 1},
    {2, {T_DIR | T_IND, T_REG, 0, 0}, 13, 10, 1, 4, 1, 1},
    {3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG, 0},
        14, 50, 1, 2, 1, 0},
    {1, {T_DIR, 0, 0, 0}, 15, 1000, 0, 2, 1, 0},
    {1, {T_REG, 0, 0, 0}, 16, 2, 1, 4, 1, 0},
    {0, {0}, 0, 0, 0, 0, 0, 0}
};

// "live"
// "ld"
// "st"
// "add"
// "sub"
// "and"
// "or"
// "xor"
// "zjmp"
// "ldi"
// "sti"
// "fork"
// "lld"
// "lldi"
// "lfork"
// "aff"
