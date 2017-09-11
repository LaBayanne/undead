#ifndef STRUCT_H
#define STRUCT_H

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
  char *tab_grille;
};
typedef struct grille Grille;

struct partie
{
  int nb_ghost, nb_vampire, nb_zombies;
  Grille grille;
  Pos pos_curseur;
};
typedef struct partie Partie;

#endif
