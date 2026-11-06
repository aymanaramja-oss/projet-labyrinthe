#include <stdio.h>
#include <stdlib.h>
#include "maze.h"

// Lecture du fichier texte avec la syntaxe (*maze).
int maze_load(Maze *maze, const char *filename) {
    // 1. Ouvrir le fichier
    FILE *fichier = fopen(filename, "r");
    if (fichier == NULL) {
        printf("Erreur : impossible d'ouvrir le fichier %s\n", filename);
        return 0;
    }

    // 2. Lire les dimensions
    int largeur, hauteur;
    if (fscanf(fichier, "%d %d\n", &largeur, &hauteur) != 2) {
        printf("Erreur : format de fichier invalide\n");
        fclose(fichier);
        return 0;
    }

    // 3. Creer la grille en memoire
    if (maze_create(maze, largeur, hauteur) == 0) {
        fclose(fichier);
        return 0;
    }

    // 4. Remplir la grille case par case
    for (int y = 0; y < hauteur; y = y + 1) {
        for (int x = 0; x < largeur; x = x + 1) {
            char c = fgetc(fichier);

            if (c == '\n') {
                c = fgetc(fichier);
            }

            if (c == EOF) {
                printf("Erreur : fin de fichier inattendue\n");
                maze_destroy(maze);
                fclose(fichier);
                return 0;
            }

            // Ecriture avec la syntaxe (*maze).
            (*maze).cells[y][x] = c;
        }
    }

    // 5. Fermer le fichier
    fclose(fichier);
    return 1;
}
