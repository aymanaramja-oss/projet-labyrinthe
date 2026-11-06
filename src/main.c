#include <stdio.h>
#include <stdlib.h>
#include "maze.h"

int main() {
    Maze mon_labyrinthe;

    if (maze_load(&mon_labyrinthe, "maps/niveau1.txt") == 1) {
        printf("Carte chargee avec succes !\n\n");

        for (int y = 0; y < mon_labyrinthe.height; y = y + 1) {
            for (int x = 0; x < mon_labyrinthe.width; x = x + 1) {
                printf("%c", mon_labyrinthe.cells[y][x]);
            }
            printf("\n");
        }

        maze_destroy(&mon_labyrinthe);
        printf("\nMemoire liberee avec succes.\n");
    } else {
        printf("Echec du chargement du labyrinthe.\n");
    }

    return 0;
}
