#include <stdio.h>
#include <stdlib.h>
#include "maze.h"

// Allocation dynamique de la grille avec la syntaxe (*maze).
int maze_create(Maze *maze, int width, int height) {
    if (maze == NULL || width <= 0 || height <= 0) {
        return 0;
    }

    // On utilise (*maze). au lieu de maze->
    (*maze).width = width;
    (*maze).height = height;

    // 1. Allocation du tableau de lignes (l'axe Y)
    (*maze).cells = malloc(height * sizeof(char *));
    if ((*maze).cells == NULL) {
        return 0;
    }

    // 2. Allocation de chaque ligne de caracteres (l'axe X)
    for (int y = 0; y < height; y = y + 1) {
        (*maze).cells[y] = malloc(width * sizeof(char));
        
        // En cas d'erreur sur une ligne, on annule tout proprement
        if ((*maze).cells[y] == NULL) {
            for (int i = 0; i < y; i = i + 1) {
                free((*maze).cells[i]);
            }
            free((*maze).cells);
            (*maze).cells = NULL;
            return 0;
        }
    }

    return 1;
}

// Liberation de la memoire avec la syntaxe (*maze).
void maze_destroy(Maze *maze) {
    if (maze == NULL || (*maze).cells == NULL) {
        return;
    }

    // 1. Liberer toutes les lignes
    for (int y = 0; y < (*maze).height; y = y + 1) {
        free((*maze).cells[y]);
    }

    // 2. Liberer le tableau principal
    free((*maze).cells);

    // Remise a zero
    (*maze).cells = NULL;
    (*maze).width = 0;
    (*maze).height = 0;
}
