#include <stdio.h>
#include <stdlib.h>
#include "struct.h"
#include "fonctions.h"


int main (int argc, char *argv[])
{
	puts("eifyj");
  system("clear");
  Partie partie;
  partie.nb_ghost=2;
  partie.nb_vampire=2;
  partie.nb_zombies=1;

  partie.grille.nb_case_x=2;
  partie.grille.nb_case_y=2;
  partie.grille.tab_grille=malloc(partie.grille.nb_case_x*partie.grille.nb_case_y*sizeof(char));
  partie.grille.tab_grille[0]='a';
  partie.grille.tab_grille[1]='b';
  partie.grille.tab_grille[2]='c';
  partie.grille.tab_grille[3]='d';
  partie.pos_curseur.x=0;
  partie.pos_curseur.y=0;

  afficher_jeu(&partie);

  free(partie.grille.tab_grille);

  return EXIT_SUCCESS;
}
