#include <stdlib.h>
#include <iostream.h>

class Individu{
  void mutation(); // fait muter l'individu
  float adaptation(); // renvoie la valeur de la fonction d'adaptation pour cet individu
};



class Population{
private:
  vector<Individu> pop; //Individus stockés dans la population, vecteur d'individus
public:
  Population selection(int p, int type); //retourne une population de p individus
  // séléctionés par la méthode type
  void reproduction(); //fait se reproduire entre eux les individus de la Population de p éléments
  Population selectBestIndv(int q);

};

// Individu traveling_salesman(Population pop,int type);
//  P = Pk.selection(p)
//  P.reproduction()
//  Pk+1 = Pk.selectBestIndv(q) + P.selectBestIndv(n-q)
//  Test d'arrêt
