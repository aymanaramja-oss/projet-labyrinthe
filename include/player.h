#ifndef PLAYER_H
#define PLAYER_H

#include "maze.h"

typedef struct {
    int x;
    int y;
    int keys;
} Player;

int player_init(Maze *maze, Player *player);
int player_move(Maze *maze, Player *player, char touche);

#endif
