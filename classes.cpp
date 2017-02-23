#include <stdlib.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/*
class Individu{
  public:
    void mutation(); // fait muter l'individu
    float adaptation() const; // renvoie la valeur de la fonction d'adaptation pour cet individu
};*/

template <class Individu>  bool compareIndividus(const Individu& g, const Individu& d){
  return g.adaptation() < d.adaptation();
};


template <class Individu> class Population{
private:
public:
  vector<Individu> pop; //Individus stockés dans la population, vecteur d'individus
  Population selectBestIndv(int q){
    sort(this->pop.begin(), this->pop.end(), compareIndividus<Individu>);
    vector<Individu> nouvellePop(this->pop.begin(),this->pop.begin()+q);
    Population resultPop;
    resultPop.pop = nouvellePop;
    return resultPop;
  };

  Population selection(int p, int type); //retourne une population de p individus
  // sélectionnés par la méthode type
  void reproduction(); //fait se reproduire entre eux les individus de la Population de p éléments
};

//class individu:
class Chemin
{
  public:
    vector<int> path;
    void mutation(){
      //Index de la mutation flip
      int mutationIndex = rand() % this->path.size() - 1;
      //Création des deux sous vecteurs que l'on va flipper
      swap(this->path[mutationIndex],this->path[mutationIndex+1]);
    };

    float adaptation() const{
      float adaptation = 0; // l'adpatation est l'inverse de la distance du chemin
      for(int i = 1; i < this->path.size(); i++){
        //somme des distances entre les villes
        adaptation += m[this->path[i-1]][this->path[i]];
      };
      return 1.0/adaptation;
    };

    unsigned size(){
      return this->path.size();
    };

    vector<int> getPath(){
      return this->path;
    };
};

Chemin operator*(Chemin a, Chemin b){
  int hybridationIndex = rand() % a.size() - 1;
  Chemin c;
  vector<int> cpath(a.size());
  c.path =cpath;
  //Copying the A path until we reach hybridationIndex
  for(int i=0 ; i<hybridationIndex ; i++){
    c.path[i] = a.path[i];
  };
  //Copying the remaining elmts from second path, checking that they are not
  //already present
  int oldIndex = 0;
  for(int i=0 ; i<a.size(); i++){
    // check if the actual element is in the list
    bool allowed = true;
    for (size_t j = 0; j < c.size(); j++) {
      if (c.path[j] == b.path[j]) {
          allowed = false;
          break;
      };
    };
    // if the actual elmt is not in the list
    if (allowed){
      c.path[hybridationIndex + oldIndex] = b.path[i];
      oldIndex ++;
    };
  };
  return c;
};



// Individu traveling_salesman(Population pop,int type);
//  P = Pk.selection(p)
//  P.reproduction()
//  Pk+1 = Pk.selectBestIndv(q) + P.selectBestIndv(n-q)
//  Test d'arrêt

//this->pop = rand() ==== Constructeur alétoire d'individu
