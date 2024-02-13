/*
** EPITECH PROJECT, 2024
** B-CPE-110-NCY-1-1-settingup-liam.delazzer [WSL: Ubuntu]
** File description:
** algo
*/

#include "../includes/my.h"


void checkthemap(settingup *setup)
{
    for (int i = 0; i < setup->rows; i++)
        setup->S[i][0] = (setup->M[i][0] == '.') ? 1 : 0;
    for (int j = 0; j < setup->cols; j++)
        setup->S[0][j] = (setup->M[0][j] == '.') ? 1 : 0;
}

int findsquare(settingup *setup, int i, int j)
{
    if (setup->M[i][j] == '.') {
        return min(setup->S[i][j - 1], setup->S[i - 1][j],
        setup->S[i - 1][j - 1]) + 1;
    } else {
        return 0;
    }
}

void parcourthemap(settingup *setup)
{
    for (int i = 1; i < setup->rows; i++) {
        for (int j = 1; j < setup->cols; j++) {
            setup->S[i][j] = findsquare(setup, i, j);
        }
    }
}

void stockmaxsquare(settingup *setup, int i, int j)
{
    if (setup->maxsquare < setup->S[i][j]) {
        setup->maxsquare = setup->S[i][j];
        setup->max_i = i;
        setup->max_j = j;
    }
}

void algo(settingup *setup)
{
    checkthemap(setup);
    parcourthemap(setup);
    findbiggestsquare(setup);
    printallmap(setup);
}
