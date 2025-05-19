/*
** EPITECH PROJECT, 2025
** B-CPE-200-REN-2-1-corewar-enzo.iffis
** File description:
** utils
*/

#include "corewar.h"

int endian_to_endian(int nb, int nbbytes)
{
    int res = 0;
    char shft = 0;
    char storage = 0;

    for (int d = nbbytes - 1; d >= 0; d--) {
        shft = (char) (nb >> (8 * (nbbytes - 1 - d)));
        storage = 0;
        for (int i = 7; i >= 0; --i)
            storage |= ((1 * ((shft & (1 << i)) != 0)) << i);
        res <<= 8;
        for (int i = 7; i >= 0; --i)
            res |= (storage & (1 << i));
    }
    return res;
}

static
bool is_cor(char *file)
{
    int len = my_strlen(file);

    if (len < 4 || my_strcmp(&file[len - 4], ".cor"))
        return false;
    return true;
}

int read_header(header_t *head, char *file)
{
    FILE *fd = fopen(file, "r");

    if (!fd)
        return my_puterr(INVALID_HEADER_ERR, 84);
    if (!is_cor(file)) {
        fclose(fd);
        return my_puterr(NOT_A_COR_FILE_ERR, 84);
    }
    if (!fread(head, sizeof(header_t), 1, fd)) {
        fclose(fd);
        return my_puterr(INVALID_HEADER_ERR, 84);
    }
    head->magic = endian_to_endian(head->magic, 4);
    if (head->magic != COREWAR_EXEC_MAGIC) {
        fclose(fd);
        return my_puterr(WRONG_MAGIC_ERR, 84);
    }
    head->prog_size = endian_to_endian(head->prog_size, 4);
    fclose(fd);
    return 0;
}

int is_in_str(char character, char *str)
{
    int len = my_strlen(str);

    for (int i = 0; i < len; i++) {
        if (character == str[i])
            return 1;
    }
    return 0;
}

int is_uint(char *str)
{
    int len = my_strlen(str);

    for (int i = 0; i < len; i++) {
        if (!is_in_str(str[i], "0123456789"))
            return 0;
    }
    return 1;
}
