#ifndef STRUCT_H
#define STRUCT_H

typedef unsigned int uint;

enum {HAUT, BAS, GAUCHE, DROITE, NONE};
enum {ZOMBIE, VAMPIRE, FANTOME};

#define ZOMBIE_C 'e'
#define VAMPIRE_C 'r'
#define FANTOME_C 't'

#define HAUT_C 'z'
#define BAS_C 's'
#define GAUCHE_C 'q'
#define DROITE_C 'd'

struct pos
{
  int x;
  int y;
};
typedef struct pos Pos;

struct grille
{
  int nb_case_x;
  int nb_case_y;
  int nb_case_total;
  char *tab_grille;
  char *tab_grille_solution;
  char *tab_nb_persos;
  uint taille_tab_persos;
};
typedef struct grille Grille;

struct partie
{
  int nb_ghost, nb_vampire, nb_zombies;
  int level, nb_levels;
  Grille grille;
  Pos pos_curseur;
};
typedef struct partie Partie;

#endif
