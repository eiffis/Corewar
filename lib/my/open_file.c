/*
** EPITECH PROJECT, 2024
** top
** File description:
** open_file
*/

#include "my.h"

int get_size_file(char *filepath)
{
    int fd = 0;
    char buff[30000];
    int readed = 0;

    fd = open(filepath, O_RDONLY);
    if (fd == -1)
        return 84;
    readed = read(fd, buff, 30000);
    close(fd);
    return readed;
}

char *open_file(char *filepath)
{
    int fd = 0;
    char *buff = NULL;
    int size = get_size_file(filepath);

    if (size == 84)
        return NULL;
    fd = open(filepath, O_RDONLY);
    if (fd == -1)
        return NULL;
    buff = malloc(sizeof(char) * size + 1);
    if (buff == NULL)
        return NULL;
    read(fd, buff, size);
    buff[size] = '\0';
    close(fd);
    return buff;
}
