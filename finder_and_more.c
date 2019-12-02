/*
** EPITECH PROJECT, 2019
** my_sokoban
** File description:
** more-desu
*/

#include <stdlib.h>
#include <ncurses.h>

int x_locked(char **map)
{
    int lock = 0;

    for (int i = 0; map[i] != NULL; i++)
        for (int j = 0; map[i][j] != '\n'; j++) {
            if (map[i][j] == 'X') {
                if ((map[(i - 1)][j] == 'X' || map[(i - 1)][j] == '#')
                    && (map[i][(j - 1)] == 'X' || map[i][(j - 1)] == '#'))
                    lock += 1;
                if ((map[(i - 1)][j] == 'X' || map[(i - 1)][j] == '#')
                    && (map[i][(j + 1)] == 'X' || map[i][(j + 1)] == '#'))
                    lock += 1;
                if ((map[(i + 1)][j] == 'X' || map[(i + 1)][j] == '#')
                    && (map[i][(j - 1)] == 'X' || map[i][(j - 1)] == '#'))
                    lock += 1;
                if ((map[(i + 1)][j] == 'X' || map[(i + 1)][j] == '#')
                    && (map[i][(j + 1)] == 'X' || map[i][(j + 1)] == '#'))
                    lock += 1;
            }
        }
    return lock;
}

int x_finder(char **map)
{
    int x = 0;

    for (int i = 0; map[i] != NULL; i++)
        for (int j = 0; map[i][j] != '\n'; j++) {
            if (map[i][j] == 'X')
                x += 1;
        }
    return x;
}

int good_finder(char **map, char **map_backup)
{
    int good = 0;

    for (int i = 0; map[i] != NULL; i++)
        for (int j = 0; map[i][j] != '\n'; j++) {
            if (map[i][j] == 'X')
                if (map_backup[i][j] == 'O')
                    good += 1;
        }
    return good;
}

int o_placer(char **map, char **map_backup, int height, int lenght)
{
    for (int i = 0; map[i] != NULL; i++)
        for (int j = 0; map[i][j] != '\n'; j++) {
            if (map_backup[i][j] == 'O')
                if (map[i][j] == 'P' || map[i][j] == 'X')
                    return 0;
                else
                    map[i][j] = 'O';
        }
    clear();
    for (int i = 0; map[i] != NULL; i++)
        mvprintw(i, 0, map[i]);
    refresh();
    return 0;
}

int to_small(void)
{
    char *str = "The terminal is too small, please make it bigger.";

    clear();
    mvprintw((LINES / 2), ((COLS - 49) / 2), str);
    refresh();
    return 0;
}