#include <cstdlib>
#include <iostream>
#include <vector>
using namespace std;

class Individu{
  void mutation(); // fait muter l'individu
  float adaptation(); // renvoie la valeur de la fonction d'adaptation pour cet individu
};

Individu operator*(Individu const& a, Individu const& b){};


class Population{
private:
  vector<Individu> pop; //Individus stockés dans la population, vecteur d'individus
public:
  Population selection(int p, int type); //retourne une population de p individus
  // sélectionnés par la méthode type
  void reproduction(); //fait se reproduire entre eux les individus de la Population de p éléments
  Population selectBestIndv(int q);
};

class Chemin : public Individu{
  private:
    vector<int> path;
  public:
    void mutation(){
      //Index de la mutation flip
      int mutationIndex = rand() % this->path.size() - 1;
      //Création des deux sous vecteurs que l'on va flipper
      vector<int> beginning(this->path.begin(), this->path.begin() + mutationIndex);
      vector<int> ending(this->path.begin() + mutationIndex + 1, this->path.end());
      //flip des vecteurs
      ending.insert( ending.end(), beginning.begin(), beginning.end() );
      this->path = ending;
    };

    float adaptation(){
      float adaptation = 0; // l'adpatation est l'inverse de la distance du chemin
      for(int i = 1, i < this->path.size(), i++){
        //somme des distances entre les villes
        adaptation += distance(this->path[i-1],this->path[i])
      };
      return 1.0/adaptation;
    };
};


// Individu traveling_salesman(Population pop,int type);
//  P = Pk.selection(p)
//  P.reproduction()
//  Pk+1 = Pk.selectBestIndv(q) + P.selectBestIndv(n-q)
//  Test d'arrêt

//this->pop = rand() ==== Constructeur alétoire d'individu
