#include "fonctions.h"

int main(int argc, char const *argv[]) {

  sRobot * pRobot = malloc(sizeof(sRobot));

  sMap * pMap = loadFile(pRobot);
  initCarteE(pMap, pRobot);
  initCarteVFEU(pMap, pRobot);
  fillCarteE(pMap, pRobot);
  findPathE(pMap, pRobot);






  return 0;
}
