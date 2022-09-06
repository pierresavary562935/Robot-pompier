#include "fonctions.h"

//----------------------------------------------------------------------------------------------//
//        Fonction d'initialisation de la map pour le pathfinding vers une case inexploré       //
//------------------------------------ ---------------------------------------------------------//
void initCarteVFEU2(sMap * pMap, sRobot * pRobot){

  char element;



  pRobot->carteV2 = malloc(pMap->TAILLE_Y * sizeof(int*));
  for(int u = 0; u < pMap->TAILLE_Y; u++){
    pRobot->carteV2[u] = malloc(pMap->TAILLE_X * sizeof(int));
  }


  for(int i = 0 ; i < pMap->TAILLE_Y ; i++){
    for(int j = 0 ; j < pMap->TAILLE_X ; j++){
      element = pMap->tab[i][j];
      //printf("element = %c\n",element );
      if(element == ' '){
        //printf("vide\n" );
        pRobot->carteV2[i][j] = VIDE;
      }
      if(element == 'x'){
        pRobot->carteV2[i][j] = MUR;
      }
      if(element == 'P'){
        //printf("E\n" );
        pRobot->carteV2[i][j] = DEPART;
      }
      if(element == 'D'){
        pRobot->carteV2[i][j] = MUR;
      }
      if(element == '1' || element == '2' || element == '3'){
        pRobot->carteV2[i][j] = VIDE;
      }
      //printf("nv element = %d\ni= %d, j= %d\n",pRobot->carteV[6][39],i,j);
    }
  }

}

//--------------------------------------------------------------------------------------------------------------//
//         Fonction de pathfinding <=> remplir la map de nombre allant de 0 (case inexploré) au robot           //
//--------------------------------------------------------------------------------------------------------------//
void fillCarteVFEU2(sMap * pMap, sRobot * pRobot){

  int idx = 0;
  int targetReached = 0;
  int fini = 0;

while(fini == 0){
  for(int i = 0 ; i < pMap->TAILLE_Y ; i++){
    for(int j = 0 ; j < pMap->TAILLE_X ; j++){
      if(pRobot->carteVFEU[i][j] == '#'){
        pRobot->carteV2[i][j] = 0;
        fini = 1;
      }
    }
  }
}




  while(targetReached == 0){

    for(int i = 0 ; i < pMap->TAILLE_Y ; i++){
      for(int j = 0 ; j < pMap->TAILLE_X ; j++){

        if(pRobot->carteV2[i][j] == idx){
          //printf("i = %d // j = %d // pMapY = %d // pMapX = %d // idx = %d\n", i,j,pMap->TAILLE_Y,pMap->TAILLE_X, idx);

          if(i+1 >= 0 && i+1 < pMap->TAILLE_Y && j >= 0 && j < pMap->TAILLE_X){
            //printf("1\n");
            if(pRobot->carteV2[i+1][j] == -1)
              pRobot->carteV2[i+1][j] = idx + 1;
          }

          if(i-1 >= 0 && i-1 < pMap->TAILLE_Y && j >= 0 && j < pMap->TAILLE_X){
            //printf("2\n");
            if(pRobot->carteV2[i-1][j] == -1)
              pRobot->carteV2[i-1][j] = idx + 1;
          }

          if(i >= 0 && i < pMap->TAILLE_Y && j+1 >= 0 && j+1 < pMap->TAILLE_X){
            //printf("3\n");
            if(pRobot->carteV2[i][j+1] == -1)
              pRobot->carteV2[i][j+1] = idx + 1;
          }

          if(i >= 0 && i < pMap->TAILLE_Y && j-1 >= 0 && j-1 < pMap->TAILLE_X){
            //printf("4\n");
            if(pRobot->carteV2[i][j-1] == -1)
              pRobot->carteV2[i][j-1] = idx + 1;
          }

      }
    }
  }
  idx++;

  targetReached = 1;
  for(int i = 0 ; i < pMap->TAILLE_Y ; i++){
    for(int j = 0 ; j < pMap->TAILLE_X ; j++){
      if(pRobot->carteV2[i][j] == -1)
        targetReached = 0;
    }
  }
  if(pRobot->carteV2[pRobot->pos_x][pRobot->pos_y] != -4){
      //printf("coucouu %d\n",pRobot->carteV[pRobot->pos_x][pRobot->pos_y]);
      targetReached = 1;
  }


}

}

//--------------------------------------------------------------------------------------------------------------//
//            Fonction de pathfinding <=> déplacer le robot de sa position jusqu'à une case inexploré           //
//--------------------------------------------------------------------------------------------------------------//
void findPathVFEU(sMap * pMap,sRobot * pRobot){

while(pRobot->carteV2[pRobot->pos_x][pRobot->pos_y] != 0){
  //printf("test : %d \n",pRobot->carteV[pRobot->pos_x-1][pRobot->pos_y]);
  //si case au dessus est = case au dessous + 1
  if(pRobot->carteV2[pRobot->pos_x-1][pRobot->pos_y] < pRobot->carteV2[pRobot->pos_x][pRobot->pos_y] && pRobot->carteV2[pRobot->pos_x-1][pRobot->pos_y] >= 0 ){
    moveRobotV(NORD, pMap, pRobot);
  }else if(pRobot->carteV2[pRobot->pos_x][pRobot->pos_y-1] < pRobot->carteV2[pRobot->pos_x][pRobot->pos_y] && pRobot->carteV2[pRobot->pos_x][pRobot->pos_y-1] >= 0){
    moveRobotV(GAUCHE, pMap, pRobot);
  }else if(pRobot->carteV2[pRobot->pos_x][pRobot->pos_y+1] < pRobot->carteV2[pRobot->pos_x][pRobot->pos_y] && pRobot->carteV2[pRobot->pos_x][pRobot->pos_y+1] >= 0){
    moveRobotV(DROITE, pMap, pRobot);
  }else{
    if(pMap->tab[pRobot->pos_x+1][pRobot->pos_y] != 'x'){
    moveRobotV(SUD, pMap, pRobot);
  }else{
    moveRobotV(NORD, pMap, pRobot);
  }
  }
  displayAllMap(pMap, pRobot);
  //displayMap(pMap, pRobot);
  usleep(FPS);
}

}
