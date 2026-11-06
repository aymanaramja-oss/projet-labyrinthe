#ifndef MAZE_H
#define MAZE_H

typedef struct {
    int width;    
    int height;   
    char **cells; 
} Maze;

int maze_create(Maze *maze, int width, int height);
void maze_destroy(Maze *maze);
int maze_load(Maze *maze, const char *filename);

#endif
