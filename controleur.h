#ifndef CONTROLEUR_H
#define CONTROLEUR_H

#include "struct.h"

void controleur_jeu(Partie *partie);
void deplacement(int direction, Pos *pos, Grille *grille);
char read_char();
int char_to_direction(char caractere);
int char_to_perso(int caractere);
void poser_perso(int perso, Grille *grille, Pos *pos);
int fin_jeu(Grille *grille);
int comparer_tableau(char tab_a[], int taille_a, char tab_b[], int taille_b);
void interaction(Partie *partie);

#endif
