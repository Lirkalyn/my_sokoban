/*
** EPITECH PROJECT, 2019
** r
** File description:
** r
*/

#include <ncurses.h>

void my_popup(char *str)
{
    int c;
    _Bool out = 0;

    initscr();              // Initialise la structure WINDOW et autres paramètres 
    mvprintw((LINES / 2), (COLS / 2), str);
    //printw("Hello World");  // Écrit Hello World à l'endroit où le curseur logique est positionné
    refresh();              // Rafraîchit la fenêtre courante afin de voir le message apparaître
    keypad(stdscr, TRUE);
    while (out == 0) {
        c = getch();                // On attend que l'utilisateur appui sur une touche pour quitter
            //printf("touch = %d\n", c);
            if (c == KEY_LEFT)
                printf("lefty");
            if (c == ' ') {
                out = 1;
                endwin();
            }
            else {
                refresh();
            }
    }
    //printf("test = %d", c);
    //endwin();               // Restaure les paramètres par défaut du terminal
}

int main(void)
{
    my_popup("test");
    return 0;
}