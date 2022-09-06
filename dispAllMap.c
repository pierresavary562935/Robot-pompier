#include "fonctions.h"

//------------------------------------------//
//      Fonction d'affichage des maps       //
//------------------------------------------//
void displayAllMap(sMap * pMap, sRobot * pRobot){
  usleep(FPS);
  int vie = 10;
  system("clear");

  printf("\n\t\t\t\t\t      LIFE : \x1b[32m%d\x1b[0m || MOVES : \x1b[34m%d\x1b[0m\n",vie,pRobot->dplcmt);

  for(int i = 0; i < pMap->TAILLE_Y;i++){

    for(int x = 0; x < pMap->TAILLE_X; x++){

      if(pMap->tab[i][x] == 'R'){
        printf("\x1b[34m%c\x1b[0m",pMap->tab[i][x] );
      }else if(pMap->tab[i][x] == 'P'){
        printf("\x1b[31m%c\x1b[0m",pMap->tab[i][x] );
      }else{
        printf("%c",pMap->tab[i][x] );
      }
    }
    printf("\t\t" );

    for(int x = 0; x < pMap->TAILLE_X; x++){

      if(pRobot->carteVFEU[i][x] == '#'){
        printf("\x1b[31m%c\x1b[0m",pRobot->carteVFEU[i][x] );
      }else if(pRobot->carteVFEU[i][x] == '-'){
        printf("\x1b[32m%c\x1b[0m",pRobot->carteVFEU[i][x] );
      }else{
        printf("%c",pRobot->carteVFEU[i][x] );
      }
    }
      printf("\n");
    }
    printf("\t\t   VISION REEL \t\t\t\t\t\t\t    VISION ROBOT\t\t         \n" );
}
