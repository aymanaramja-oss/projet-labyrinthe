#include <stdio.h>
#include <stdlib.h>
#include "maze.h"

int maze_create(Maze *maze, int width, int height) {
    if (maze == NULL || width <= 0 || height <= 0) {
        return 0;
    }

    (*maze).width = width;
    (*maze).height = height;

    (*maze).cells = malloc(height * sizeof(char *));
    if ((*maze).cells == NULL) {
        return 0;
    }

    for (int y = 0; y < height; y = y + 1) {
        (*maze).cells[y] = malloc(width * sizeof(char));
        
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

void maze_destroy(Maze *maze) {
    if (maze == NULL || (*maze).cells == NULL) {
        return;
    }

    for (int y = 0; y < (*maze).height; y = y + 1) {
        free((*maze).cells[y]);
    }

    free((*maze).cells);

    (*maze).cells = NULL;
    (*maze).width = 0;
    (*maze).height = 0;
}
