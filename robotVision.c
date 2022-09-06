#include "fonctions.h"

//------------------------------------------------------------------------------------//
//        Fonction d'initialisation de la map pour mémoriser les déplacements         //
//------------------------------------ -----------------------------------------------//
void initCarteVFEU(sMap * pMap, sRobot * pRobot){

  char element;

  pRobot->carteVFEU = malloc(pMap->TAILLE_Y * sizeof(int*));
  for(int u = 0; u < pMap->TAILLE_Y; u++){
    pRobot->carteVFEU[u] = malloc(pMap->TAILLE_X * sizeof(int));
  }

  for(int i = 0 ; i < pMap->TAILLE_Y ; i++){
    for(int j = 0 ; j < pMap->TAILLE_X ; j++){

      element = pMap->tab[i][j];

      if(element == ' ' || element == '1' || element == '2' || element == '3'){
        pRobot->carteVFEU[i][j] = '#';
      }
      if(element == 'x'){
        pRobot->carteVFEU[i][j] = 'x';
      }
      if(element == 'E'){
        pRobot->carteVFEU[i][j] = '#';
      }
      if(element == 'D'){
        pRobot->carteVFEU[i][j] = 'D';
      }
    }
  }
}

//------------------------------------------//
//      Fonction d'affichage de la map      //
//------------------------------------------//
void displayCarteVFEU(sMap* pMap, sRobot* pRobot){

  int y = 0;
  printf("-------------------\n");

  for(int i = 0; i < pMap->TAILLE_Y;i++){
    for(int x = 0; x < pMap->TAILLE_X; x++){

        printf("%c",pRobot->carteVFEU[y][x] );
      }
      printf("\n");
      y++;
    }

}
