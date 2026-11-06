#ifndef GENERATOR_H
#define GENERATOR_H

#include "maze.h"

// Cree un labyrinthe aleatoire (partie de Darius)
// width et height doivent etre impairs (ex : 21 et 11)
// Retourne 1 si tout va bien, 0 en cas d'erreur
int maze_generate(Maze *maze, int width, int height);

#endif
