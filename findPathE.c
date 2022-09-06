#include "fonctions.h"

//----------------------------------------------------------------------------------------//
//        Fonction d'initialisation de la map pour le pathfinding vers l'EXTINCTEUR       //
//------------------------------------ ---------------------------------------------------//
void initCarteE(sMap * pMap, sRobot * pRobot){

  char element;

  pRobot->carteV = malloc(pMap->TAILLE_Y * sizeof(int*));
  for(int u = 0; u < pMap->TAILLE_Y; u++){
    pRobot->carteV[u] = malloc(pMap->TAILLE_X * sizeof(int));
  }

  for(int i = 0 ; i < pMap->TAILLE_Y ; i++){
    for(int j = 0 ; j < pMap->TAILLE_X ; j++){

      element = pMap->tab[i][j];

      if(element == ' '){
        pRobot->carteV[i][j] = VIDE;
      }
      if(element == 'x'){
        pRobot->carteV[i][j] = MUR;
      }
      if(element == 'E'){
        pRobot->carteV[i][j] = EXTINCTEUR;
      }
      if(element == 'D'){
        pRobot->carteV[i][j] = DEPART;
      }
      if(element == '1' || element == '2' || element == '3'){
        pRobot->carteV[i][j] = FEU;
      }

    }
  }

}

//------------------------------------------//
//      Fonction d'affichage de la map      //
//------------------------------------------//
void displayCarteE(sMap * pMap, sRobot * pRobot){

  int y = 0;
  printf("-------------------\n");

  for(int i = 0; i < pMap->TAILLE_Y;i++){
    for(int x = 0; x < pMap->TAILLE_X; x++){
        printf("%4d",pRobot->carteV[y][x] );
      }
      printf("\n");
      y++;
    }

}

//--------------------------------------------------------------------------------------------------------------//
//      Fonction de pathfinding <=> remplir la map de nombre allant de 0 (l'EXTINCTEUR) à l'entrée de la map    //
//--------------------------------------------------------------------------------------------------------------//
void fillCarteE(sMap * pMap, sRobot * pRobot){

  int idx = 0;
  int targetReached = 0;

  while(targetReached == 0){

    for(int i = 0 ; i < pMap->TAILLE_Y ; i++){
      for(int j = 0 ; j < pMap->TAILLE_X ; j++){

        if(pRobot->carteV[i][j] == idx){

          if(i+1 >= 0 && i+1 < pMap->TAILLE_Y && j >= 0 && j < pMap->TAILLE_X){

            if(pRobot->carteV[i+1][j] == -1)
              pRobot->carteV[i+1][j] = idx + 1;
          }

          if(i-1 >= 0 && i-1 < pMap->TAILLE_Y && j >= 0 && j < pMap->TAILLE_X){

            if(pRobot->carteV[i-1][j] == -1)
              pRobot->carteV[i-1][j] = idx + 1;
          }

          if(i >= 0 && i < pMap->TAILLE_Y && j+1 >= 0 && j+1 < pMap->TAILLE_X){

            if(pRobot->carteV[i][j+1] == -1)
              pRobot->carteV[i][j+1] = idx + 1;
          }

          if(i >= 0 && i < pMap->TAILLE_Y && j-1 >= 0 && j-1 < pMap->TAILLE_X){

            if(pRobot->carteV[i][j-1] == -1)
              pRobot->carteV[i][j-1] = idx + 1;
          }

      }
    }
  }
  idx++;

  targetReached = 1;
  for(int i = 0 ; i < pMap->TAILLE_Y ; i++){
    for(int j = 0 ; j < pMap->TAILLE_X ; j++){
      if(pRobot->carteV[i][j] == -1)
        targetReached = 0;
    }
  }
  if(pRobot->carteV[pRobot->pos_x][pRobot->pos_y] != -4){
      targetReached = 1;
  }
}
}
