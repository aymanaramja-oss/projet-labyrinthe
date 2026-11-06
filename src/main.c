#include <stdio.h>
#include <stdlib.h>
#include <time.h>          // AJOUT DARIUS
#include "maze.h"
#include "generator.h"     // AJOUT DARIUS

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

    // AJOUT DARIUS : generer un labyrinthe aleatoire
    srand(time(NULL));
    if (maze_generate(&mon_labyrinthe, 21, 11) == 1) {
        printf("\nLabyrinthe genere :\n\n");

        for (int y = 0; y < mon_labyrinthe.height; y = y + 1) {
            for (int x = 0; x < mon_labyrinthe.width; x = x + 1) {
                printf("%c", mon_labyrinthe.cells[y][x]);
            }
            printf("\n");
        }

        maze_destroy(&mon_labyrinthe);
    } else {
        printf("Echec de la generation du labyrinthe.\n");
    }
    // FIN AJOUT DARIUS

    return 0;
}
