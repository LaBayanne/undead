#ifndef FONCTIONS_H
#define FONCTIONS_H

#include "struct.h"

char char_at_pos(int const x, int const y, Grille *grille);
void afficher_nb_perso(Partie *partie);
void afficher_grille(Grille *grille, Pos *pos_curseur);
void afficher_curseur(int const x, int const y, Pos *pos_curseur);
void afficher_jeu(Partie *partie);

#endif
