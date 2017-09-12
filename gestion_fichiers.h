#ifndef GESTION_FICHIERS_H
#define GESTION_FICHIERS_H

#include "struct.h"

int jump_line(FILE *fichier);
void init_level(Partie *partie);
void search_level(FILE *fichier, int level);
void init_nb_persos(FILE *fichier, Partie *partie);
void copier_grille(FILE *fichier, int taille_tab, char tab_grille[]);
void init_tab_persos(FILE *fichier, Grille *grille);
void init_grille(FILE *fichier, Grille *grille);

#endif
