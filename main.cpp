#include <cstlib>
#include <iostream.h>
#include <"classes.cpp">

int TYPE_SELECT = 0;
int PERCENT_SELECT = 10;
int PERCENT_KEEP = 4;


Individu geneticalResult(Population pop, int type, float percent_select, float percent_keep){
  Population Pk = new pop;
  while (true){ // Condition d'arrêt
    Population P = Pk.selection(percent_select);
    P.reproduction();
    Pk = Pk.selectBestIndv(percent_keep) + P.selectBestIndv(100-percent_keep);
  };
};
