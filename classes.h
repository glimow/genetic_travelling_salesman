#include <cstdlib>
#include <iostream>

using namespace std;

class Individu{
  
  void mutation(); // fait muter l'individu
  float adaptation(); // renvoie la valeur de la fonction d'adaptation pour cet individu

};

Individu operator*(Individu const& a, Individu const& b);


class Population{

private:
  
  vector<Individu> pop; //Individus stockés dans la population, vecteur d'individus

public:

  Population selection(int p, int type); //retourne une population de p individus
  // sélectionnés par la méthode type
  void reproduction(); //fait se reproduire entre eux les individus de la Population de p éléments
  Population selectBestIndv(int q);

};


// Individu traveling_salesman(Population pop,int type);
//  P = Pk.selection(p)
//  P.reproduction()
//  Pk+1 = Pk.selectBestIndv(q) + P.selectBestIndv(n-q)
//  Test d'arrêt

//this->pop = rand() ==== Constructeur alétoire d'individu
