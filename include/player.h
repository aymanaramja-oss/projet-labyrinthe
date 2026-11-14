#ifndef PLAYER_H
#define PLAYER_H

#include "maze.h"

// x = colonne, y = ligne, keys = nombre de cles
typedef struct {
    int x;
    int y;
    int keys;
} Player;

// Place le joueur sur la case 'S'
// Retourne 1 si tout va bien, 0 s'il n'y a pas de depart
int player_init(Maze *maze, Player *player);

// Deplace le joueur avec une touche : z (haut), s (bas), q (gauche), d (droite)
// Retourne 0 si bloque, 1 si deplace, 2 si la sortie est atteinte
int player_move(Maze *maze, Player *player, char touche);

#endif
