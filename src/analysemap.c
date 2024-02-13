/*
** EPITECH PROJECT, 2024
** B-CPE-110-NCY-1-1-settingup-liam.delazzer [WSL: Ubuntu]
** File description:
** analysemap
*/

#include "../includes/my.h"

int min(int a, int b, int c)
{
    int m = a;

    if (m > b)
        m = b;
    if (m > c)
        m = c;
    return m;
}

int get_map_rows(char *filepath)
{
    int fd = open(filepath, O_RDONLY);
    char *buffer = malloc(sizeof(char) * 100000);
    int size = 0;
    int rows = 0;

    if (fd == -1)
        return (84);
    size = read(fd, buffer, 100000);
    if (size == -1)
        return (84);
    buffer[size] = '\0';
    close(fd);
    for (int i = 0; buffer[i] != '\0'; i++) {
        if (buffer[i] == '\n')
            rows++;
    }
    return (rows - 1);
}

int countbefornextline(char *buffer, int i)
{
    int count = 0;

    for (; buffer[i] != '\n'; i++) {
        count++;
    }
    return (count + 1);
}

int get_map_cols(char *filepath)
{
    int fd = open(filepath, O_RDONLY);
    char *buffer = malloc(sizeof(char) * 100000);
    int size = 0;
    int cols = 0;
    int i = 0;

    if (fd == -1)
        return (84);
    size = read(fd, buffer, 100000);
    if (size == -1)
        return (84);
    buffer[size] = '\0';
    close(fd);
    i = countbefornextline(buffer, i);
    for (; buffer[i] != '\n'; i++) {
        cols++;
    }
    return (cols);
}
