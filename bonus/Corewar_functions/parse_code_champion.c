/*
** EPITECH PROJECT, 2025
** B-CPE-200-REN-2-1-corewar-enzo.iffis
** File description:
** parse_code_champion
*/

#include "corewar.h"

static
int read_big_endian(int fd)
{
    unsigned char buff[4];

    if (read(fd, buff, 4) != 4)
        return -1;
    return (buff[0] << 24) | (buff[1] << 16) | (buff[2] << 8) | buff[3];
}

void byte_in_hex(unsigned char byte, char *buf)
{
    char digits[17] = "0123456789abcdef";

    buf[0] = digits[(byte / 16)];
    buf[1] = digits[byte % 16];
}

char *ascii_to_hex(char *str, int prog_sz)
{
    int len = prog_sz;
    char *hexa_code = malloc(sizeof(char) * (prog_sz * 2 + 1));

    for (int d = 0; d < len; d++) {
        byte_in_hex(str[d], &hexa_code[d * 2]);
    }
    hexa_code[prog_sz * 2] = '\0';
    free(str);
    return hexa_code;
}

char *read_champion_code(char const *filepath, int *code_size)
{
    int fd = open(filepath, O_RDONLY);
    int magic;
    int prog_size;
    char *code;

    if (fd < 0)
        return NULL;
    magic = read_big_endian(fd);
    (void) magic;
    lseek(fd, PROG_NAME_LENGTH + 4, SEEK_CUR);
    prog_size = read_big_endian(fd);
    lseek(fd, COMMENT_LENGTH + 4, SEEK_CUR);
    code = malloc(sizeof(char) * (prog_size + 1));
    if (!code || read(fd, code, prog_size) != prog_size)
        return NULL;
    close(fd);
    *code_size = prog_size;
    code = ascii_to_hex(code, prog_size);
    return code;
}
