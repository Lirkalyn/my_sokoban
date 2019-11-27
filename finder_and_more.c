/*
** EPITECH PROJECT, 2019
** my_sokoban
** File description:
** more-desu
*/

#include <stdlib.h>
#include <ncurses.h>

int X_finder(char **map)
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

int O_placer(char **map, char **map_backup)
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
        printw(map[i]);
    refresh();
    return 0;
}