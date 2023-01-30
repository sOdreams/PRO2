#include "Categorias.hh"
#include<vector>
#include<iostream>

using namespace std;

    Categorias::Categorias(){}

    Categorias::Categorias(const int& c, const int& k){
        categorias = vector< vector<int> > (c,vector<int>(k));
        ident_cat = vector<string> (c);
    }

    int Categorias::puntos(int i,int j){
        return categorias[i][j];
    }

    string Categorias::cat_nom(int h){
        return ident_cat[h-1];
    }

    void Categorias::leer_categorias(){
        int c = categorias.size();
        int k = categorias[0].size();
        for(int i = 0; i < c ; ++i) cin >> ident_cat[i];
        for(int i = 0; i < c ; ++i){
            for(int j = 0; j < k; ++j) {
                cin >> categorias[i][j];
            }
        }
    }

    void Categorias::escribir_categorias(){
        int c = categorias.size();
        int k = categorias[0].size();
        cout << c << " " << k << endl;
        for(int i = 0; i < c; ++i) {
            cout << ident_cat[i];
            for(int j = 0; j < k; ++j){
                cout << " " <<categorias[i][j];
            }
            cout << endl;
        }
    }

    int Categorias::tamany(){

        return categorias[0].size();
    }
