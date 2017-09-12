#include "fonctions.h"
#include <stdlib.h>
#include <stdio.h>

char char_at_pos(const int x, const int y, Grille *grille)
{
  //on cherche la position correspondante
  int pos=pos_tab(x,y, grille);
  //puis on affiche le caractère correspondant
  return grille->tab_grille[pos];
}

int pos_tab(const int x, const int y, Grille *grille)
{
  /*on calcule une position uni-dimensionnelle à partir d'une position
  multi-dimensionnelle*/
  return y*grille->nb_case_x + x;
}

void afficher_nb_perso(Partie *partie)
{
  //on affiche sur une ligne le nombre de persos à placer
  printf(" Z:%d  V:%d  F:%d\n\n", partie->nb_zombies, partie->nb_vampire, partie->nb_ghost);
}

void afficher_grille(Grille *grille, Pos *pos_curseur)
{
  //on affiche la grille ligne par ligne
  printf("   ");
  uint i=0;
  //en affichant les nombres de persos sur les bords
  for (;i<grille->nb_case_x;i++)
  {
    printf(" %c ", grille->tab_nb_persos[i]);
  }
  printf("\n");
  for (uint y=0;y<grille->nb_case_y;y++)
  {
    printf(" %c ", grille->tab_nb_persos[i++]);
    for (uint x=0;x<grille->nb_case_x;x++)
    {
      //on affiche ou non le curseur
      afficher_curseur(x,y, pos_curseur);
      printf("%c ",char_at_pos(x ,y , grille));
    }
    printf(" %c ", grille->tab_nb_persos[i++]);
    //quand on arrive au bout d'une ligne, on revient à la ligne
    printf("\n");
  }
  printf("   ");
  for (;i<grille->taille_tab_persos;i++)
  {
    printf(" %c ", grille->tab_nb_persos[i]);
  }

  printf("\n\n");
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

void afficher_controles()
{
  printf("Haut : %c | Bas : %c | Gauche : %c | Droite : %c\n\n",HAUT_C, BAS_C, GAUCHE_C, DROITE_C);
  printf("Zombie : %c | Vampire : %c | Fantome : %c\n\n",ZOMBIE_C, VAMPIRE_C, FANTOME_C);
}

void afficher_jeu(Partie *partie)
{
  //on affiche le jeu
  afficher_nb_perso(partie);
  afficher_grille(&partie->grille, &partie->pos_curseur);
  afficher_controles();
}
