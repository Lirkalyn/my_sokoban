/*
** EPITECH PROJECT, 2019
** my_sokoban
** File description:
** find_desu, move_desu
*/

#include <stdlib.h>
#include <ncurses.h>

int p_finder(char **map, int *P)
{
    int i;
    int j;

    for (i = 0; map[i] != NULL; i++)
        for (j = 0; map[i][j] != '\0'; j++)
            if (map[i][j] == 'P') {
                P[0] = i;
                P[1] = j;
                return 0;
            }
    return 1;
}

int up(char **map, int *P, int height, int lenght)
{
    if (map[(P[0] - 1)][P[1]] == '#')
        return 0;
    if (map[(P[0] - 1)][P[1]] == ' ' || map[(P[0] - 1)][P[1]] == 'O') {
        map[(P[0] - 1)][P[1]] = 'P';
        map[P[0]][P[1]] = ' ';
    }
    if (map[(P[0] - 1)][P[1]] == 'X') {
        if (map[(P[0] - 2)][P[1]] == 'X' || map[(P[0] - 2)][P[1]] == '#')
            return 0;
        else {
            map[(P[0] - 2)][P[1]] = 'X';
            map[(P[0] - 1)][P[1]] = 'P';
            map[P[0]][P[1]] = ' ';
        }
    }
    clear();
    for (int i = 0; map[i] != NULL; i++)
        mvprintw((((LINES - height) / 2) + i), ((COLS - lenght) / 2), map[i]);
    refresh();
}

int down(char **map, int *P, int height, int lenght)
{
    if (map[(P[0] + 1)][P[1]] == '#')
        return 0;
    if (map[(P[0] + 1)][P[1]] == ' ' || map[(P[0] + 1)][P[1]] == 'O') {
        map[(P[0] + 1)][P[1]] = 'P';
        map[P[0]][P[1]] = ' ';
    }
    if (map[(P[0] + 1)][P[1]] == 'X') {
        if (map[(P[0] + 2)][P[1]] == 'X' || map[(P[0] + 2)][P[1]] == '#')
            return 0;
        else {
            map[(P[0] + 2)][P[1]] = 'X';
            map[(P[0] + 1)][P[1]] = 'P';
            map[P[0]][P[1]] = ' ';
        }
    }
    clear();
    for (int i = 0; map[i] != NULL; i++)
        mvprintw((((LINES - height) / 2) + i), ((COLS - lenght) / 2), map[i]);
    refresh();
}

int left(char **map, int *P, int height, int lenght)
{
    if (map[P[0]][(P[1] - 1)] == '#')
        return 0;
    if (map[P[0]][(P[1] - 1)] == ' ' || map[P[0]][(P[1] - 1)] == 'O') {
        map[P[0]][(P[1] - 1)] = 'P';
        map[P[0]][P[1]] = ' ';
    }
    if (map[P[0]][(P[1] - 1)] == 'X') {
        if (map[P[0]][(P[1] - 2)] == 'X' || map[P[0]][(P[1] - 2)] == '#')
            return 0;
        else {
            map[P[0]][(P[1] - 2)] = 'X';
            map[P[0]][(P[1] - 1)] = 'P';
            map[P[0]][P[1]] = ' ';
        }
    }
    clear();
    for (int i = 0; map[i] != NULL; i++)
        mvprintw((((LINES - height) / 2) + i), ((COLS - lenght) / 2), map[i]);
    refresh();
}

int right(char **map, int *P, int height, int lenght)
{
    if (map[P[0]][(P[1] + 1)] == '#')
        return 0;
    if (map[P[0]][(P[1] + 1)] == ' ' || map[P[0]][(P[1] + 1)] == 'O') {
        map[P[0]][(P[1] + 1)] = 'P';
        map[P[0]][P[1]] = ' ';
    }
    if (map[P[0]][(P[1] + 1)] == 'X') {
        if (map[P[0]][(P[1] + 2)] == 'X' || map[P[0]][(P[1] + 2)] == '#')
            return 0;
        else {
            map[P[0]][(P[1] + 2)] = 'X';
            map[P[0]][(P[1] + 1)] = 'P';
            map[P[0]][P[1]] = ' ';
        }
    }
    clear();
    for (int i = 0; map[i] != NULL; i++)
        mvprintw((((LINES - height) / 2) + i), ((COLS - lenght) / 2), map[i]);
    refresh();
}