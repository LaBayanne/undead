#include <stdlib.h>
#include <stdio.h>
#include "controleur.h"
#include "fonctions.h"

void controleur_jeu(Partie *partie)
{
  while (!fin_jeu(&partie->grille))
  {
    system("clear");
    afficher_jeu(partie);
    interaction(partie);
  }
}

void deplacement(int direction, Pos *pos, Grille *grille)
{
  //on deplace le curseur en fonction de la position
  switch (direction)
  {
    case HAUT:
      //si on n'est pas au bord de la grille
      if (pos->y!=0)
      {
        pos->y--;
      }
      break;
    case BAS:
      //si on n'est pas au bord de la grille
      if (pos->y!=grille->nb_case_y-1)
      {
        pos->y++;
      }
      break;
    case GAUCHE:
      //si on n'est pas au bord de la grille
      if (pos->x!=0)
      {
        pos->x--;
      }
      break;
    case DROITE:
      //si on n'est pas au bord de la grille
      if (pos->x!=grille->nb_case_x-1)
      {
        pos->x++;
      }
      break;
  }
}

char read_char()
{
  char touche='0';
  scanf("%c", &touche);
  return touche;
}

int char_to_direction(char caractere)
{
  //on retourne la direction correspondante à la touche
  switch (caractere)
  {
    case HAUT_C:
      return HAUT;
      break;
    case BAS_C:
      return BAS;
      break;
    case GAUCHE_C:
      return GAUCHE;
      break;
    case DROITE_C:
      return DROITE;
      break;
    default:
      return NONE;
  }
}

int char_to_perso(int caractere)
{
  //on retourne le perso correspondant à la touche
  switch (caractere)
  {
    case ZOMBIE_C:
      return ZOMBIE;
      break;
    case VAMPIRE_C:
      return VAMPIRE;
      break;
    case FANTOME_C:
      return FANTOME;
      break;
    default:
      return NONE;
  }
}

void poser_perso(int perso, Grille *grille, Pos *pos)
{
  int position=pos_tab(pos->x,pos->y, grille);
  if (grille->tab_grille[position]!='/' && grille->tab_grille[position]!='\\')
  {
    switch (perso)
    {
      case ZOMBIE:
        grille->tab_grille[position]='Z';
        break;
      case VAMPIRE:
        grille->tab_grille[position]='V';
        break;
      case FANTOME:
        grille->tab_grille[position]='F';
        break;
      }
    }
}

int fin_jeu(Grille *grille)
{
  //on teste si la grille correspond à la grille solution
  return comparer_tableau(grille->tab_grille, grille->nb_case_total, grille->tab_grille_solution, grille->nb_case_total);
}

int comparer_tableau(char tab_a[], int taille_a, char tab_b[], int taille_b)
{
  if (taille_b!=taille_a)
  {
    return 0;
  }
  //on compare case à case
  for (int i=0; i<taille_a;i++)
  {
    if (tab_a[i]!=tab_b[i])
    {
      return 0;
    }
  }
  return 1;
}

void interaction(Partie *partie)
{
  int touche='0', perso='0', direction=NONE;
  touche=read_char();
  direction=char_to_direction(touche);
  deplacement(direction, &partie->pos_curseur, &partie->grille);
  perso=char_to_perso(touche);
  poser_perso(perso, &partie->grille, &partie->pos_curseur);
}
