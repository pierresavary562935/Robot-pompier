#include "fonctions.h"

//----------------------------------------------------------------------------------------//
//                  Fonction de déplacement du robot dans les 4 directions                //
//------------------------------------ ---------------------------------------------------//
void moveRobotV(int dir, sMap* pMap, sRobot* pRobot){
  switch (dir) {

    case NORD :
    scanFire(pMap, pRobot);
    pMap->tab[pRobot->pos_x][pRobot->pos_y] = ' ';
    pRobot->pos_x = pRobot->pos_x-1;
    pMap->tab[pRobot->pos_x][pRobot->pos_y] = pRobot->statut;
    pRobot->dplcmt = pRobot->dplcmt+1;
    //displayMap(pMap, pRobot);
    displayAllMap(pMap, pRobot);
    usleep(FPS);
    break;

    case DROITE :
    scanFire(pMap, pRobot);
    pMap->tab[pRobot->pos_x][pRobot->pos_y] = ' ';
    pRobot->pos_y = pRobot->pos_y+1;
    pMap->tab[pRobot->pos_x][pRobot->pos_y] = pRobot->statut;
    pRobot->dplcmt = pRobot->dplcmt+1;
    //displayMap(pMap, pRobot);
    displayAllMap(pMap, pRobot);
    usleep(FPS);
    break;

    case SUD :
    scanFire(pMap, pRobot);
    pMap->tab[pRobot->pos_x][pRobot->pos_y] = ' ';
    pRobot->pos_x = pRobot->pos_x+1;
    pMap->tab[pRobot->pos_x][pRobot->pos_y] = pRobot->statut;
    pRobot->dplcmt = pRobot->dplcmt+1;
    //displayMap(pMap, pRobot);
    displayAllMap(pMap, pRobot);
    usleep(FPS);
    break;

    case GAUCHE :
    scanFire(pMap, pRobot);
    pMap->tab[pRobot->pos_x][pRobot->pos_y] = ' ';
    pRobot->pos_y = pRobot->pos_y-1;
    pMap->tab[pRobot->pos_x][pRobot->pos_y] = pRobot->statut;
    pRobot->dplcmt = pRobot->dplcmt+1;
    //displayMap(pMap, pRobot);
    displayAllMap(pMap, pRobot);
    usleep(FPS);
    break;

  }
}

//----------------------------------------------------------------------------------------//
//                  Fonction de déplacement du robot jusqu'à l'EXTINCTEUR                 //
//------------------------------------ ---------------------------------------------------//
void findPathE(sMap* pMap, sRobot* pRobot){

    pRobot->statut = 'R';


if(pRobot->pos_x == 0 && pRobot->carteVFEU[pRobot->pos_x+1][pRobot->pos_y] == '#'){
  pRobot->pos_x = pRobot->pos_x+1;
  moveRobotV(SUD, pMap, pRobot);
}else if(pRobot->pos_x == pMap->TAILLE_Y-1 && pRobot->carteVFEU[pRobot->pos_x-1][pRobot->pos_y] == '#'){

      pRobot->pos_x = pRobot->pos_x-1;
      moveRobotV(NORD, pMap, pRobot);
    }else if(pRobot->carteVFEU[pRobot->pos_x][pRobot->pos_y-1] == '#'){
      pRobot->pos_y = pRobot->pos_y-1;
      moveRobotV(GAUCHE, pMap, pRobot);
    }else if(pRobot->carteVFEU[pRobot->pos_x][pRobot->pos_y+1] == '#'){

      pRobot->pos_y = pRobot->pos_y+1;
      moveRobotV(DROITE, pMap, pRobot);
    }

    pMap->tab[pRobot->pos_x][pRobot->pos_y] = pRobot->statut;
    pRobot->dplcmt = pRobot->dplcmt+1;
    //displayMap(pMap, pRobot);
    displayAllMap(pMap, pRobot);
    usleep(FPS);


    while(pMap->tab[pRobot->pos_x][pRobot->pos_y] != pMap->tab[pRobot->pos_x_E][pRobot->pos_y_E]){

      //si case au dessus est = case au dessous + 1
      if(pRobot->carteV[pRobot->pos_x-1][pRobot->pos_y] < pRobot->carteV[pRobot->pos_x][pRobot->pos_y] && pRobot->carteV[pRobot->pos_x-1][pRobot->pos_y] >= 0 && pRobot->carteV[pRobot->pos_x-1][pRobot->pos_y] != -4){
        moveRobotV(NORD, pMap, pRobot);
      }else if(pRobot->carteV[pRobot->pos_x][pRobot->pos_y-1] < pRobot->carteV[pRobot->pos_x][pRobot->pos_y] && pRobot->carteV[pRobot->pos_x][pRobot->pos_y-1] >= 0){
        moveRobotV(GAUCHE, pMap, pRobot);
      }else if(pRobot->carteV[pRobot->pos_x][pRobot->pos_y+1] < pRobot->carteV[pRobot->pos_x][pRobot->pos_y] && pRobot->carteV[pRobot->pos_x][pRobot->pos_y+1] >= 0){
        moveRobotV(DROITE, pMap, pRobot);
      }else{
        moveRobotV(SUD, pMap, pRobot);
      }
      displayAllMap(pMap, pRobot);
      //displayMap(pMap, pRobot);
      usleep(FPS);

}

pRobot->statut = 'P';
pMap->tab[pRobot->pos_x][pRobot->pos_y] = pRobot->statut;

displayAllMap(pMap, pRobot);
discover(pMap, pRobot);

}

//----------------------------------------------------------------------------------------//
//                   Fonction de mémorisation des cases déjà explorés                     //
//------------------------------------ ---------------------------------------------------//
void scanFire(sMap * pMap, sRobot * pRobot){

//printf("coucou\n" );
    if(pRobot->carteVFEU[pRobot->pos_x][pRobot->pos_y] == '#'){
      pRobot->carteVFEU[pRobot->pos_x][pRobot->pos_y] = '-';
    }
    //printf("coucou1\n" );
    if(pRobot->carteVFEU[pRobot->pos_x][pRobot->pos_y+1] == '#' && pRobot->carteV[pRobot->pos_x][pRobot->pos_y+1] != 'x' ){
      pRobot->carteVFEU[pRobot->pos_x][pRobot->pos_y+1] = '-';
    }
    //printf("coucou2\n" );
    if(pRobot->carteVFEU[pRobot->pos_x][pRobot->pos_y-1] == '#' && pRobot->carteV[pRobot->pos_x][pRobot->pos_y-1] != 'x'){
      pRobot->carteVFEU[pRobot->pos_x][pRobot->pos_y-1] = '-';
    }
    //printf("coucou3\n" );
    if(pRobot->carteVFEU[pRobot->pos_x-1][pRobot->pos_y] == '#' && pRobot->carteV[pRobot->pos_x-1][pRobot->pos_y] != 'x'){
      pRobot->carteVFEU[pRobot->pos_x-1][pRobot->pos_y] = '-';
    }
    //printf("coucou4\n" );
    if((pRobot->carteVFEU[pRobot->pos_x+1][pRobot->pos_y] == '#' || pRobot->carteVFEU[pRobot->pos_x+1][pRobot->pos_y] == 'D')  && pRobot->carteV[pRobot->pos_x+1][pRobot->pos_y] != 'x'){
      pRobot->carteVFEU[pRobot->pos_x+1][pRobot->pos_y] = '-';
    }
    //printf("coucou5\n" );
    if(pMap->tab[pRobot->pos_x][pRobot->pos_y+1] == '1' || pMap->tab[pRobot->pos_x][pRobot->pos_y-1] == '1' || pMap->tab[pRobot->pos_x+1][pRobot->pos_y] == '1' || pMap->tab[pRobot->pos_x-1][pRobot->pos_y] == '1'){
      printf("feu trouvé !\n");
      return;
    }

    //printf("coucou6\n" );


}

//----------------------------------------------------------------------------------------//
//   Fonction de déplacement et de découverte de la carte du robot à la recherche du feu  //
//----------------------------------------------------------------------------------------//
void discover(sMap * pMap, sRobot * pRobot){

  int targetReached = 0;

while(targetReached == 0){

  //printf("\n%d\n",dirAleatoire );

  if(pRobot->carteVFEU[pRobot->pos_x-1][pRobot->pos_y] == '#' && pMap->tab[pRobot->pos_x-1][pRobot->pos_y] != 'x'){
    moveRobotV(NORD,pMap, pRobot);
  }else if(pRobot->carteVFEU[pRobot->pos_x][pRobot->pos_y+1] == '#' && pMap->tab[pRobot->pos_x][pRobot->pos_y+1] != 'x'){
    moveRobotV(DROITE,pMap, pRobot);
  }else if(pRobot->carteVFEU[pRobot->pos_x+1][pRobot->pos_y] == '#' && pMap->tab[pRobot->pos_x+1][pRobot->pos_y] != 'x'){
    moveRobotV(SUD,pMap, pRobot);
  }else if(pRobot->carteVFEU[pRobot->pos_x][pRobot->pos_y-1] == '#' && pMap->tab[pRobot->pos_x][pRobot->pos_y-1] != 'x'){
    moveRobotV(GAUCHE,pMap, pRobot);
  }else{

    initCarteVFEU2(pMap, pRobot);
    fillCarteVFEU2(pMap, pRobot);
    findPathVFEU(pMap, pRobot);

  }
  if(pMap->tab[pRobot->pos_x][pRobot->pos_y+1] == '1' || pMap->tab[pRobot->pos_x][pRobot->pos_y-1] == '1' || pMap->tab[pRobot->pos_x+1][pRobot->pos_y] == '1' || pMap->tab[pRobot->pos_x-1][pRobot->pos_y] == '1'){
    printf("feu trouvé !!\n");

    char element;
    for(int i = 0 ; i < pMap->TAILLE_Y ; i++){
      for(int j = 0 ; j < pMap->TAILLE_X ; j++){
        element = pMap->tab[i][j];
        //printf("element = %c\n",element );

        if(element == '1' || element == '2' || element == '3'){
          pMap->tab[i][j] = ' ';
        }
        //printf("nv element = %d\ni= %d, j= %d\n",pRobot->carteV[6][39],i,j);
      }
    }

    displayAllMap(pMap, pRobot);
    targetReached++;
  }
}
}
