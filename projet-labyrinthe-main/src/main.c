#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "maze.h"
#include "generator.h"
#include "player.h"

void afficher(Maze *maze, Player *player) {
    printf("\n");
    for (int y = 0; y < (*maze).height; y = y + 1) {
        for (int x = 0; x < (*maze).width; x = x + 1) {
            if (x == (*player).x && y == (*player).y) {
                printf("P");
            } else {
                printf("%c", (*maze).cells[y][x]);
            }
        }
        printf("\n");
    }
    printf("Cles : %d\n", (*player).keys);
}

int main(int argc, char *argv[]) {
    Maze mon_labyrinthe;
    Player joueur;
    int choix = 0;
    int ok = 0;
    int resultat = 1;
    char touche = ' ';


    printf("1. Jouer le niveau 1\n");
    printf("2. Jouer un labyrinthe aleatoire\n");
    printf("Choix : ");
    if (scanf("%d", &choix) != 1) {
        return 1;
    }

    if (choix == 2) {
        ok = maze_generate(&mon_labyrinthe, 21, 11);
    } else {
        ok = maze_load(&mon_labyrinthe, "maps/niveau1.txt");
    }

    if (ok == 0) {
        printf("Echec du chargement du labyrinthe.\n");
        return 1;
    }

    if (player_init(&mon_labyrinthe, &joueur) == 0) {
        maze_destroy(&mon_labyrinthe);
        return 1;
    }

    while (resultat != 2 && touche != 'x') {
        afficher(&mon_labyrinthe, &joueur);
        printf("Deplacement (z q s d, x pour quitter) : ");
        if (scanf(" %c", &touche) != 1) {
            touche = 'x';
        }

        if (touche != 'x') {
            resultat = player_move(&mon_labyrinthe, &joueur, touche);
        }
    }

    if (resultat == 2) {
        afficher(&mon_labyrinthe, &joueur);
        printf("\nBravo, vous avez trouve la sortie !\n");
    }

    maze_destroy(&mon_labyrinthe);
    printf("Memoire liberee.\n");
    return 0;
}
