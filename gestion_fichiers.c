#include <stdio.h>
#include <stdlib.h>
#include "gestion_fichiers.h"

int jump_line(FILE *fichier)
{
  char caractere;
  while ((caractere=fgetc(fichier))!='\n')
  {
    if (caractere==EOF)
    {
      return -1;
    }
  }
  return 1;
}

void init_level(Partie *partie)
{
  FILE *fichier=NULL;
  fichier=fopen("levels.txt", "r");
  if (fichier!=NULL)
  {
    fscanf(fichier, "Nb_Levels:%d", &partie->nb_levels);
    jump_line(fichier);
    search_level(fichier, partie->level);
    init_nb_persos(fichier, partie);
    init_grille(fichier, &partie->grille);
    init_tab_persos(fichier, &partie->grille);
    fclose(fichier);
  }
  else
  {
    printf("Unable to open levels.txt");
    exit(EXIT_FAILURE);
  }

  partie->pos_curseur.x=0;
  partie->pos_curseur.y=0;
}


void search_level(FILE *fichier, int level)
{
  //on cherche le niveau correspondant
  int lvl_actu=0;
  while (lvl_actu!=level)
  {
    fscanf(fichier, "Lvl:%d", &lvl_actu);
    //tan qu'on ne trouve pas on saute une ligne
    if (jump_line(fichier)==-1)
    {
      printf("Unable to find the level\n");
      exit(EXIT_FAILURE);
    }
  }
}

void init_nb_persos(FILE *fichier, Partie *partie)
{
  //on initialise le nombre de persos en fonction du fichier
  fscanf(fichier,"Z:%d V:%d F:%d", &partie->nb_zombies, &partie->nb_vampire, &partie->nb_ghost);
  fgetc(fichier);
}

void copier_grille(FILE *fichier, int taille_tab, char tab_grille[])
{
  uint j=0;
  char caractere;
  while (j<taille_tab)//tant qu'on n'a pas parcouru toute la grille
  {
    caractere=fgetc(fichier);
    if (caractere!='\n')//si le caractère lu n'est pas un retour à la ligne
    {
      tab_grille[j]=caractere;//on l'ajoute à la grille
      j++;
    }
  }
}

void init_tab_persos(FILE *fichier, Grille *grille)
{
  grille->tab_nb_persos=NULL;
  grille->taille_tab_persos=grille->nb_case_x*2+grille->nb_case_y*2;
  grille->tab_nb_persos=malloc(grille->taille_tab_persos*sizeof(char));
  if (grille->tab_nb_persos==NULL)
  {
    printf("Unable to init grid");
    exit(EXIT_FAILURE);
  }
  fgetc(fichier);
  for (uint i=0;i<=grille->taille_tab_persos;i++)
  {
    //on récupère les nombres correspondants
    grille->tab_nb_persos[i]=fgetc(fichier);
  }
}

void init_grille(FILE *fichier, Grille *grille)
{
  grille->tab_grille=NULL;
  grille->tab_grille_solution=NULL;
  //on initialise la grille en fonction du fichier

  //on lit la largeur et la hauteur
  fscanf(fichier,"X:%d Y:%d", &grille->nb_case_x, &grille->nb_case_y);

  grille->nb_case_total=grille->nb_case_x*grille->nb_case_y;
  grille->tab_grille=malloc(grille->nb_case_total*sizeof(char));
  if (grille->tab_grille==NULL)
  {
    printf("Unable to init grid");
    exit(EXIT_FAILURE);
  }
  fgetc(fichier);
  //on lit la composition de la grille et on la recopie dans le tableau
  copier_grille(fichier, grille->nb_case_total, grille->tab_grille);

  //on fait de même pour la grille solution
  grille->tab_grille_solution=malloc(grille->nb_case_total*sizeof(char));
  if (grille->tab_grille_solution==NULL)
  {
    printf("Unable to init grid");
    exit(EXIT_FAILURE);
  }
  copier_grille(fichier, grille->nb_case_total, grille->tab_grille_solution);
}
