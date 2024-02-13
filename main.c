/*
** EPITECH PROJECT, 2023
** main
** File description:
** main
*/

#include "includes/my.h"
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int detectchar(int filepath, settingup *setup, int i, int j)
{
    char actulchar;
    ssize_t bytesRead;

    bytesRead = read(filepath, &actulchar, sizeof(actulchar));
    while (bytesRead == sizeof(actulchar) && actulchar == '\n') {
        bytesRead = read(filepath, &actulchar, sizeof(actulchar));
    }
    if (bytesRead == sizeof(actulchar)) {
        setup->M[i][j] = actulchar;
        return 0;
    } else {
        close(filepath);
        return 1;
    }
}

int readmap(const char *filename, settingup *setup)
{
    int filepath = open(filename, O_RDONLY);
    char newline;
    ssize_t bytesRead;

    if (filepath == -1) {
        return 1;
    }
    bytesRead = read(filepath, &newline, sizeof(newline));
    while (bytesRead == sizeof(newline) && newline != '\n') {
        bytesRead = read(filepath, &newline, sizeof(newline));
    }
    for (int i = 0; i < setup->rows; i++) {
        for (int j = 0; j < setup->cols;) {
            detectchar(filepath, setup, i, j);
            j++;
        }
    }
    close(filepath);
    return 0;
}

int main(int argc, char **argv)
{
    int colums;
    int rows;
    settingup setup;

    colums = get_map_cols(argv[1]);
    rows = get_map_rows(argv[1]);
    setup.rows = rows;
    setup.cols = colums;
    if (argc != 2) {
        return 1;
    }
    if (readmap(argv[1], &setup) != 0) {
        return 0;
    }
    algo(&setup);
    return 0;
}
