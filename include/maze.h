#ifndef MAZE_H
#define MAZE_H

// Structure representant le labyrinthe
typedef struct {
    int width;    // Largeur (nombre de colonnes)
    int height;   // Hauteur (nombre de lignes)
    char **cells; // Grille 2D de caracteres
} Maze;

// Prototypes des fonctions
int maze_create(Maze *maze, int width, int height);
void maze_destroy(Maze *maze);
int maze_load(Maze *maze, const char *filename);

#endif
