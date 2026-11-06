#include <stdio.h>
#include <stdlib.h>
#include "maze.h"
#include "generator.h"

// Generation aleatoire du labyrinthe (partie de Darius)
// Principe : une "taupe" creuse au hasard en sautant de 2 cases,
// et revient en arriere quand elle est coincee.
int maze_generate(Maze *maze, int width, int height) {
    int x, y;
    int px, py;                       // position de la taupe
    int dx[4] = {0, 0, -1, 1};        // haut, bas, gauche, droite
    int dy[4] = {-1, 1, 0, 0};
    int d, nx, ny;
    int possibles[4];                 // directions ou la taupe peut aller
    int nbPossibles;

    // 1. Reserver la grille avec la fonction d'Ayman
    if (maze_create(maze, width, height) == 0) {
        return 0;
    }

    // 2. Tout remplir de murs
    for (y = 0; y < height; y = y + 1) {
        for (x = 0; x < width; x = x + 1) {
            (*maze).cells[y][x] = '#';
        }
    }

    // 3. La pile : le chemin parcouru par la taupe (pour revenir en arriere)
    int *pileX = NULL;
    int *pileY = NULL;
    int nb = 0;
    int tailleMax = ((width - 1) / 2) * ((height - 1) / 2);   // nombre de salles

    pileX = (int *)calloc(tailleMax, sizeof(int));
    pileY = (int *)calloc(tailleMax, sizeof(int));
    if (pileX == NULL || pileY == NULL) {
        fprintf(stderr, "Erreur d allocation\n");
        free(pileX);
        free(pileY);
        maze_destroy(maze);
        return 0;
    }

    // 4. La taupe commence en (1, 1)
    (*maze).cells[1][1] = '.';
    pileX[0] = 1;
    pileY[0] = 1;
    nb = 1;

    // 5. Tant que la pile n'est pas vide, la taupe creuse
    while (nb > 0) {
        // la taupe est sur la derniere salle de la pile
        px = pileX[nb - 1];
        py = pileY[nb - 1];

        // a. chercher les directions possibles :
        //    salle a 2 cases, dans la grille, et encore un mur
        nbPossibles = 0;
        for (d = 0; d < 4; d = d + 1) {
            nx = px + 2 * dx[d];
            ny = py + 2 * dy[d];
            if (nx > 0 && nx < width - 1 && ny > 0 && ny < height - 1
                && (*maze).cells[ny][nx] == '#') {
                possibles[nbPossibles] = d;
                nbPossibles = nbPossibles + 1;
            }
        }

        if (nbPossibles == 0) {
            // b. coincee : on recule
            nb = nb - 1;
        } else {
            // c. direction au hasard parmi les possibles
            d = possibles[rand() % nbPossibles];
            nx = px + 2 * dx[d];
            ny = py + 2 * dy[d];

            (*maze).cells[py + dy[d]][px + dx[d]] = '.';   // le mur du milieu
            (*maze).cells[ny][nx] = '.';                   // la nouvelle salle

            // on avance : la nouvelle salle va au bout de la pile
            pileX[nb] = nx;
            pileY[nb] = ny;
            nb = nb + 1;
        }
    }

    free(pileX);
    free(pileY);

    // 6. Placer le depart et la sortie
    (*maze).cells[1][1] = 'S';
    (*maze).cells[height - 2][width - 2] = 'E';

    return 1;
}
