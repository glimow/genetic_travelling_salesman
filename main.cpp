// #include <stdlib.h>
#include <iostream>
#include "parsing.cpp"
#include "classes.cpp"
#include <algorithm>
#include <random>

using namespace std;


int TYPE_SELECT = 0;
int PERCENT_SELECT = 10;
int PERCENT_KEEP = 4;


template <class Individu> Individu geneticalResult(Population<Individu> pop, int type, float percent_select, float percent_keep){
  Population<Individu> Pk = pop;
  for (size_t i = 0; i < 5000; i++){ // Condition d'arrêt
    Population<Individu> P = Pk.selection(percent_select, type);
    // P.reproduction(1, 1);
    // P = P.selectBestIndv(100-percent_keep);
    // Pk = Pk.selectBestIndv(percent_keep);
    // Pk.pop.insert(Pk.pop.end(), P.pop.begin(), P.pop.end());
  };
  return Pk.pop[0];
};

void printVector(vector<int> vect){
  cout << "[ " ;
  for (size_t i = 0; i < vect.size(); ++i) {
    cout << vect[i] << " ; " ;
  }
  cout << "]" << endl;
}


Population<Chemin> init(vector<vector<int> > m, int nb_individu){
  vector<int> initialpath(m.size());
  iota(begin(initialpath),end(initialpath), 0);
  auto engine = default_random_engine{};
  Population<Chemin> initialPop;
  initialPop.m = m;
  vector<Chemin> individus(m.size());
  for (size_t i = 0; i < m.size(); i++) {
    individus[i].path = initialpath;
    individus[i].pm = & m;
    shuffle(begin(individus[i].path), end(individus[i].path), engine);
  }
  initialPop.pop = individus;
  return initialPop;
}


int main(int argc, char const *argv[]) {
  cout << "trying to open " << argv[1] << endl;
  vector<vector<int> > m = parse(argv[1]);
  Population<Chemin> initialPop;
  initialPop = init(m, 10);
  printVector(initialPop.pop[1].path);
  Chemin result;
  result =  geneticalResult<Chemin>(initialPop, 0, 50,50);
  // cout << "adapatation : " << result << endl;
  printVector(result.path);
  return 0;
}
