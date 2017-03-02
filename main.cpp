#include <stdlib.h>
#include <iostream>

#include "classes.cpp"
using namespace std;

int TYPE_SELECT = 0;
int PERCENT_SELECT = 10;
int PERCENT_KEEP = 4;


template <class Individu> Individu geneticalResult(Population<Individu> pop, int type, float percent_select, float percent_keep){
  Population<Individu> Pk = pop;
  while (true){ // Condition d'arrêt
    Population<Individu> P = Pk.selection(percent_select);
    P.reproduction();
    Pk = Pk.selectBestIndv(percent_keep) + P.selectBestIndv(100-percent_keep);
  };
};
