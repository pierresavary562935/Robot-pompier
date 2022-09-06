#include "fonctions.h"

//--------------------------------------------------------------------------------------------------------------//
//         Fonction de chargement du fichier (map) et de son tranfert dans un tableau de caractère              //
//--------------------------------------------------------------------------------------------------------------//
sMap * loadFile(sRobot* pRobot){

  FILE* fichier = NULL;

  char element;
  int j = 0;

sMap *  pMap = malloc(sizeof(sMap));


  fichier = fopen("map.txt", "r");

  if(fichier != NULL){
    printf("Fichier bien ouvert !\n");
    fscanf(fichier,"%d:%d",&pMap->TAILLE_X, &pMap->TAILLE_Y); //on lit la taille de la map

    element = fgetc(fichier); // lecture du caractere fin de ligne
    //puis on passe a la ligne et on lit tout le fichier
  pMap->tab = malloc(pMap->TAILLE_Y * sizeof(char*));
  for(int u = 0; u < pMap->TAILLE_Y; u++){
    pMap->tab[u] = malloc(pMap->TAILLE_X * sizeof(char));
  }

    do{

      for(int i = 0 ; i < pMap->TAILLE_X ; i++){
        element = fgetc(fichier);

        if(element == '\n'){
          element = fgetc(fichier);
          j++;
        }
        if(element == 'D'){
          pRobot->pos_x = j;
          pRobot->pos_y = i;
        }
        if(element == 'E'){
          pRobot->pos_x_E = j;
          pRobot->pos_y_E = i;
        }
        if(j >= pMap->TAILLE_Y){
          break;
        }
        pMap->tab[j][i] = element;
      }
    }while(element != EOF);
  }else{
    printf("Fichier mal ouvert...\n");
    exit(EXIT_FAILURE);
  }

  fclose(fichier);

  return pMap;


}


//------------------------------------------//
//      Fonction d'affichage de la map      //
//------------------------------------------//
void displayMap(sMap* pMap, sRobot* pRobot){

  int vie = 0;
  int y = 0;
  system("clear");
  printf("--------------------------------------------------\n");
  printf("\t     \x1b[32m LIFE : %d \x1b[0m|||\x1b[34m Vitesse : %d \x1b[0m\n",vie, pRobot->dplcmt);
  for(int i = 0; i < pMap->TAILLE_Y;i++){
    for(int x = 0; x < pMap->TAILLE_X; x++){
      //printf("%d %d",x,y );
        printf("%c",pMap->tab[y][x] );
      }
      printf("\n");
      y++;
    }



}
