#include "fonctions.h"
#include <stdlib.h>
#include <stdio.h>

char char_at_pos(int const x, int const y, Grille *grille)
{
  /*on calcule une position uni-dimensionnelle à partir d'une position
  multi-dimensionnelle*/
  int pos=y*grille->nb_case_x + x;
  return grille->tab_grille[pos];
}

void afficher_nb_perso(Partie *partie)
{
  //on affiche sur une ligne le nombre de persos à placer
  printf("\n");
  printf("Z:%d  F:%d  V:%d\n\n", partie->nb_zombies, partie->nb_ghost, partie->nb_vampire);
}

void afficher_grille(Grille *grille, Pos *pos_curseur)
{
  //on affiche la grille ligne par ligne
  for (unsigned int y=0;y<grille->nb_case_y;y++)
  {
    for (unsigned int x=0;x<grille->nb_case_x;x++)
    {
      //on affiche ou non le curseur
      afficher_curseur(x,y, pos_curseur);
      printf("%c ",char_at_pos(x ,y , grille));
    }
    //quand on arrive au bout d'une ligne, on revient à la ligne
    printf("\n");
  }
  printf("\n");
}

void afficher_curseur(int const x, int const y, Pos *pos_curseur)
{
  //si la position x et y correspond à la position du curseur, on l'affiche
  if (x==pos_curseur->x && y==pos_curseur->y)
  {
    printf("!");
  }
  else
  {
    printf(" ");
  }
}

void afficher_jeu(Partie *partie)
{
  //on affiche le jeu
  afficher_nb_perso(partie);
  afficher_grille(&partie->grille, &partie->pos_curseur);
}
