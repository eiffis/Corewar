/*
** EPITECH PROJECT, 2025
** B-CPE-200-REN-2-1-corewar-enzo.iffis
** File description:
** printhelper
*/

#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "../../include/my.h"
#include <unistd.h>
#include "stdlib.h"

void print_helper(char const *filepath)
{
    struct stat stats;
    int fd = open(filepath, O_RDONLY);
    char *buffer;
    size_t bytes_read = 0;

    if (fd == -1)
        return;
    if (stat(filepath, &stats) == -1){
        close(fd);
        return;
    }
    buffer = malloc(sizeof(char) * stats.st_size + 1);
    if (!buffer){
        close(fd);
        return;
    }
    bytes_read = read(fd, buffer, stats.st_size);
    buffer[bytes_read] = '\0';
    my_putstr(buffer);
    free(buffer);
}
