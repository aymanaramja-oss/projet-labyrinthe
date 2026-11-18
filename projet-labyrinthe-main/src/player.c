#include <stdio.h>
#include "maze.h"
#include "player.h"

int player_init(Maze *maze, Player *player) {
    for (int y = 0; y < (*maze).height; y = y + 1) {
        for (int x = 0; x < (*maze).width; x = x + 1) {
            if ((*maze).cells[y][x] == 'S') {
                (*player).x = x;
                (*player).y = y;
                (*player).keys = 0;
                return 1;
            }
        }
    }

    printf("Erreur : pas de depart dans le labyrinthe\n");
    return 0;
}

int player_move(Maze *maze, Player *player, char touche) {
    int x = (*player).x;
    int y = (*player).y;

    if (touche == 'z') {
        y = y - 1;
    }
    if (touche == 's') {
        y = y + 1;
    }
    if (touche == 'q') {
        x = x - 1;
    }
    if (touche == 'd') {
        x = x + 1;
    }

    if (x < 0 || x >= (*maze).width || y < 0 || y >= (*maze).height) {
        return 0;
    }

    char case_visee = (*maze).cells[y][x];

    if (case_visee == '#') {
        return 0;
    }

    if (case_visee == 'D' && (*player).keys == 0) {
        printf("La porte est fermee, il faut une cle.\n");
        return 0;
    }

    if (case_visee == 'D') {
        (*player).keys = (*player).keys - 1;
        (*maze).cells[y][x] = '.';
        printf("Porte ouverte !\n");
    }

    if (case_visee == 'K') {
        (*player).keys = (*player).keys + 1;
        (*maze).cells[y][x] = '.';
        printf("Cle ramassee !\n");
    }

    (*player).x = x;
    (*player).y = y;

    if (case_visee == 'E') {
        return 2;
    }

    if (case_visee == 'T') {
        for (int ligne = 0; ligne < (*maze).height; ligne = ligne + 1) {
            for (int colonne = 0; colonne < (*maze).width; colonne = colonne + 1) {
                if ((*maze).cells[ligne][colonne] == 'T' && (ligne != y || colonne != x)) {
                    (*player).x = colonne;
                    (*player).y = ligne;
                    printf("Teleportation !\n");
                    return 1;
                }
            }
        }
    }

    return 1;
}
