#ifndef FONCTIONS_H
#define FONCTIONS_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

//CONSTANTES DE DIRECTIONS
#define NORD 1
#define DROITE 2
#define SUD 3
#define GAUCHE 4

//NOMBRE D'IMAGE EN MICROSECONDE
#define FPS 70000

//CONSTANTES POUR LES TABLEAUX D'ENTIERS carteV et carteV2
#define VIDE -1
#define MUR -2
#define EXTINCTEUR 0
#define DEPART -4
#define FEU -5

//STRUCTURE MAP
// TAILLE_X <=> largeur de la map
// TAILLE_X <=> longueur de la map
// char **tab <=> tableau de caractère stockant la map
typedef struct str_map{
  int TAILLE_X;
  int TAILLE_Y;
  char **tab;
}sMap;

//STRUCTURE ROBOT
// pos_x <=> position actuel du robot en x
// pos_y <=> position actuel du robot en y
// pos_x_E <=> position de l'EXTINCTEUR en x
// pos_y_E <=> position de l'EXTINCTEUR en y
// dir <=> direction du robot (NORD, DROITE, SUD, GAUCHE)
// statut <=> statut du robot, avant d'avoir trouvé le feu = 'R', après = 'P'
// int **carteV <=> tableau d'entier servant à trouver l'EXTINCTEUR
// int **carteV2 <=> tableau d'entier servant à trouver le feu
// char **carteVFEU <=> tableau de caractère stockant la vision du robot
// int dplcmt <=> nombre de déplacement jusqu'au feu
typedef struct str_coordRobot{
  int pos_x;
  int pos_y;
  int pos_x_E;
  int pos_y_E;
  int dir;
  char statut;
  int **carteV;
  int **carteV2;
  char **carteVFEU;
  int dplcmt;

}sRobot;

//Dans loadMap.c
// Fonctions de chargement et d'affichage de la map
sMap * loadFile(sRobot* pRobot);
void displayMap(sMap* pMap, sRobot* pRobot); //Fonction d'affichage de char **tab

//Dans findPathE.c
// Fonctions de création de la carte Virtuelle et de pathfinding pour aller à l'EXTINCTEUR
void initCarteE(sMap * pMap, sRobot * pRobot);//Fonction d'initialisation de int **carteV
void displayCarteE(sMap * pMap, sRobot * pRobot);//Fonction d'affichage de int **carteV
void fillCarteE(sMap * pMap, sRobot * pRobot);//Fonction de pathfinding pour trouver le chemin du feu

//Dans robot.c
// Fonction de déplacement du robot pour trouver l'EXTINCTEUR puis le feu
void moveRobotV(int dir, sMap* pMap, sRobot* pRobot);//Fonction de déplacement dans les 4 directions
void findPathE(sMap* pMap, sRobot* pRobot);//Fonction de déplacements pour aller jusqu'a l'EXTINCTEUR
void scanFire(sMap * pMap, sRobot * pRobot);//Fonction de mémorisation des cases explorées
void discover(sMap * pMap, sRobot * pRobot);//Fonction de déplacements pour aller jusqu'au feu

//Dans robotVision.c
//Fonctions de création de la carte Virtuelle pour aller au feu
void initCarteVFEU(sMap * pMap, sRobot * pRobot);//Fonction d'initialisation de char **carteVFEU
void displayCarteVFEU(sMap * pMap, sRobot * pRobot);//Fonction d'affichage de char **carteVFEU

//Dans findFire.c
//Fonctions de pathfinding pour aller aux endroits inexplorés et trouver le feu
void initCarteVFEU2(sMap * pMap, sRobot * pRobot);
void fillCarteVFEU2(sMap * pMap, sRobot * pRobot);
void findPathVFEU(sMap * pMap, sRobot * pRobot);


//Dans displayAllMap.c
// Fonction d'affichage des maps (vision réel + vision robot)
void displayAllMap(sMap * pMap, sRobot * pRobot);



#endif
