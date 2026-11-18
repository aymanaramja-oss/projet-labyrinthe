#include <stdlib.h>
#include "maze.h"
#include "generator.h"

int creuser(Maze *maze, int x, int y) {
    int dx[4] = {0, 0, -2, 2};
    int dy[4] = {-2, 2, 0, 0};
    int debut = rand() % 4;

    (*maze).cells[y][x] = '.';

    for (int i = 0; i < 4; i = i + 1) {
        int d = (debut + i) % 4;
        int nx = x + dx[d];
        int ny = y + dy[d];

        if (nx > 0 && nx < (*maze).width - 1 && ny > 0 && ny < (*maze).height - 1 && (*maze).cells[ny][nx] == '#') {
            (*maze).cells[y + dy[d] / 2][x + dx[d] / 2] = '.';
            creuser(maze, nx, ny);
        }
    }

    return 1;
}

int maze_generate(Maze *maze, int width, int height) {
    if (maze_create(maze, width, height) == 0) {
        return 0;
    }

    for (int y = 0; y < height; y = y + 1) {
        for (int x = 0; x < width; x = x + 1) {
            (*maze).cells[y][x] = '#';
        }
    }

    creuser(maze, 1, 1);

    (*maze).cells[1][1] = 'S';
    (*maze).cells[height - 2][width - 2] = 'E';

    return 1;
}