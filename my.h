/*
** EPITECH PROJECT, 2019
** my_sokoban
** File description:
** h-desu
*/

#ifndef _MY_H_
#define _MY_H_

char **my_str_to_word_array(char const *str);
int start(char **map, int height, int lenght, char *buf);
int p_finder(char **map, int *P);
int up(char **map, int *P, int height, int lenght);
int down(char **map, int *P, int height, int lenght);
int left(char **map, int *P, int height, int lenght);
int right(char **map, int *P, int height, int lenght);
int x_finder(char **map);
int good_finder(char **map, char **map_backup);
int o_placer(char **map, char **map_backup, int height, int lenght);
int x_locked(char **map);
int to_small(void);

#endif
