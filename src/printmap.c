/*
** EPITECH PROJECT, 2024
** B-CPE-110-NCY-1-1-settingup-liam.delazzer [WSL: Ubuntu]
** File description:
** printmap
*/

#include "../includes/my.h"

void findbiggestsquare(settingup *setup)
{
    setup->maxsquare = setup->S[0][0];
    setup->max_i = 0;
    setup->max_j = 0;
    for (int i = 0; i < setup->rows; i++) {
        for (int j = 0; j < setup->cols; j++) {
            stockmaxsquare(setup, i, j);
        }
    }
}

void printmap(settingup *setup, int i, int j)
{
    if (i >= setup->max_i - setup->maxsquare + 1 && i <= setup->max_i && j >=
    setup->max_j - setup->maxsquare + 1 && j <= setup->max_j) {
        my_printf("x");
    } else {
        my_printf("%c", setup->M[i][j]);
    }
}

void printallmap(settingup *setup)
{
    for (int i = 0; i < setup->rows; i++) {
        for (int j = 0; j < setup->cols; j++) {
            printmap(setup, i, j);
        }
        my_printf("\n");
    }
}
