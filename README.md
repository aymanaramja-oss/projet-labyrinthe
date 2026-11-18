# Projet Labyrinthe en C

Jeu de labyrinthe dans la console

## Compilation et lancement (Ubuntu)

    make
    ./labyrinthe

Supprimer le programme compile : `make clean`

Dependances : gcc et make.

## Utilisation

- 1 : jouer le niveau 1 (maps/niveau1.txt)
- 2 : jouer un labyrinthe genere aleatoirement
- Deplacements : z (haut), q (gauche), s (bas), d (droite), puis Entree
- x : quitter


## Organisation du code

- maze.c / maze.h : creation et liberation de la grille (malloc / free)
- file.c : chargement d'une carte depuis un fichier
- player.c / player.h : joueur, deplacements, cles, portes, teleporteurs, victoire
- generator.c / generator.h : generation aleatoire du labyrinthe
- main.c : menu et boucle de jeu

## Repartition

- Ayman : Makefile, grille, chargement des cartes
- Darius : generation aleatoire du labyrinthe
- Marie : moteur de jeu prevu au depart 

## A venir (rendu final)

affichage SDL, grille hexagonale (si possible).