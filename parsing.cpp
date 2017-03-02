#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <stdlib.h>
#include <bits/stdc++.h>



using namespace std;


vector<vector<int>> parse(char* file)
{
    ifstream fichierutilisateur();

    //Ouverture d'un fichier en mode lecture
    if(fichierutilisateur.is_open())
    {

        string  ligne;
        vector<string> vec_ligne;

        while(getline(fichierutilisateur,ligne))
        {
            vec_ligne.push_back(ligne);
        }

        int n_ville =   vec_ligne.size();

        vector<vector<int> >m(n_ville);

        for(int k=0;k<n_ville;k++)
        {
            m[k].resize(n_ville);
            std::stringstream sk(vec_ligne[k]);
            for(int i=0;i<n_ville;i++)
            {
                  sk >> m[k][i];
                  cout<< m[k][i]<<" ";
            }
            cout<<endl;

        }
    return m;
    }
    else
    {
        cout << "ERREUR: Impossible d'ouvrir le fichier en lecture." <<endl;
    }
