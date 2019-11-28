/*
** EPITECH PROJECT, 2019
** my_sokoban
** File description:
** sokoban-desu
*/

#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <ncurses.h>
#include "my.h"

int mod(char **map, int key, _Bool *out, int height)
{
    int P[2];

    P_finder(map, P);
    if (key == KEY_UP)
        up(map, P, height);
    if (key == KEY_DOWN)
        down(map, P, height);
    if (key == KEY_LEFT)
        left(map, P, height);
    if (key == KEY_RIGHT)
        right(map, P, height);
    if (key == 'a' || key == 'b') {
        *out = 1;
        endwin();
    }
    else
        refresh();
}

int restart(char **map_backup, int height, int lenght, char *buf)
{
    clear();
    refresh();
    endwin();
    start(map_backup, height, lenght, buf);
    return 1;
}

int start(char **map, int height, int lenght, char *buf)
{
    char **map_backup = my_str_to_word_array(buf);
    int key_pos[3] = {[0 ... 2] = 0};

    initscr();
    for (int i = 0; i < height; printw(map[i++]));
    refresh();
    keypad(stdscr, TRUE);
    for (_Bool out = 0; out != 1;) {
        O_placer(map, map_backup);
        getmaxyx(stdscr, key_pos[1], key_pos[2]);
        if (key_pos[1] < height || key_pos[2] < lenght)
            to_small();
        key_pos[0] = (X_finder(map) == good_finder(map, map_backup)) ? 'a'
            : (X_locked(map) >= X_finder(map)) ? 'b' : getch();
        if (key_pos[0] == ' ')
            out = restart(map_backup, height, lenght, buf);
        else
            mod(map, key_pos[0], &out, height);
    }
    return (key_pos[0] == 'b') ? 1 : 0;
}

int check_map(char *buf, int len, int *height, int *lenght)
{
    int i;
    _Bool f = 0;

    *height = 1;
    for (i = 0; i < len; i++) {
        if (buf[i] != ' ' && buf[i] != '\n' && buf[i] != '#'
            && buf[i] != 'X' && buf[i] != 'O' && buf[i] != 'P')
            return 1;
        if (buf[i] == '\n') {
            *height += 1;
            f = 1;
        }
        else if (f == 0)
            *lenght += 1;
    }
    return 0;
}

int main(int argc, char **argv)
{
    struct stat fileStat;
    char *buf;
    int adre_readedbyte[4];
    int hei_len[2] = {[0 ... 1] = 0};
    char **test;

    if (argc != 2)
        return 84;
    if (stat(argv[1], &fileStat) < 0)
        return 84;
    buf = (char *)malloc((fileStat.st_size + 1) * sizeof(char));
    adre_readedbyte[0] = open(argv[1], O_RDONLY);
    if (adre_readedbyte[0] == -1)
        return 84;
    adre_readedbyte[1] = read(adre_readedbyte[0], buf, fileStat.st_size);
    buf[fileStat.st_size] = '\0';
    if (check_map(buf, fileStat.st_size, &hei_len[0], &hei_len[1]))
        return 84;
    return start(my_str_to_word_array(buf), hei_len[0], hei_len[1], buf);
}