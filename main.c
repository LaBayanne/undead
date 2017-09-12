#include <stdio.h>
#include <stdlib.h>
#include "struct.h"
#include "gestion_fichiers.h"
#include "controleur.h"

int main (int argc, char *argv[])
{
  system("clear");

  Partie partie;
  partie.level=2;

	init_level(&partie);

  controleur_jeu(&partie);

  free(partie.grille.tab_grille);
  free(partie.grille.tab_grille_solution);

  return EXIT_SUCCESS;
}
