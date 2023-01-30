#include "Cjt_Jugadores.hh"
#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;

    Cjt_Jugadores::Cjt_Jugadores(){
        mida = 0;
    }

    void Cjt_Jugadores::nuevo_jugador(const string& p){
        Jugador g;
        pair< map<string,Jugador>::iterator, bool > r = mjug.insert(make_pair(p,g));
        if(r.second){
            ++mida;
            mjug[p].mod_ranking(mida);
            ranking.push_back(make_pair(p,make_pair(0,mida)));
            cout << mida << endl;
        }
        else{
            cout << "error: ya existe un jugador con ese nombre" << endl;
        }
    }

    void Cjt_Jugadores::eliminar_jugador(const string& id){
        int i = mjug[id].consul_raking()-1;
        for(int j = i; j < mida - 1; ++j){
            --ranking[j+1].second.second;
            ranking[j] = ranking[j+1];
            mjug[ranking[j].first].mod_ranking(j+1);
        }
        mjug.erase(id);
        ranking.pop_back();
        --mida;
        cout << mida << endl;
    }

    int Cjt_Jugadores::consultar_mida()const {
        return mida;
    }

    bool Cjt_Jugadores::existe_jugador(const string& id){
        map<string,Jugador>::iterator it = mjug.find(id);
        if(it != mjug.end()) return true;
        else return false;
    }

     void Cjt_Jugadores::consultar_jugador(const string& id){
         cout << id << " ";
         mjug[id].escribir_jugador();
    }

    void Cjt_Jugadores::escribir_jugadores(){
        map<string,Jugador>::iterator it = mjug.begin();
        while(it != mjug.end()){
            cout << (*it).first << " ";
            (*it).second.escribir_jugador();
            ++it;
        }
    }

    void Cjt_Jugadores::escribir_ranking(){
        for(int i = 1; i <= mida; ++i){
            string id = ranking[i-1].first;
            int n = mjug[id].consul_puntos();
            cout << i << " " << id << " " << n << endl;
        }
    }
    void Cjt_Jugadores::leer_jugadores(const int& p){
        string s;
        mida += p;
        for(int i = 1; i <= p; ++i){
            cin >> s;
            Jugador g;
            g.mod_ranking(i);
            mjug[s] = g;
            ranking.push_back(make_pair(s,make_pair(0,i)));
        }
    }

    string Cjt_Jugadores::consultar_rkn(const int& rkn){
        return ranking[rkn-1].first;
    }

    bool Cjt_Jugadores::comp(const pair<string,pair<int,int>>& a,const pair<string,pair<int,int>>& b){
            if(a.second.first == b.second.first ) return a.second.second < b.second.second;
            else return a.second.first > b.second.first;
    }

    void Cjt_Jugadores::actualizar_ranking(){
        sort(ranking.begin(),ranking.end(),comp);

        for(int i = 0; i < mida; ++i){
            string g = ranking[i].first;
            ranking[i].second.second = i+1;
            mjug[g].mod_ranking(i+1);
        }
    }

    void Cjt_Jugadores::Actua_Tor(){
       actualizar_ranking();
    }

    void Cjt_Jugadores::actualizar_datosS(string nom,int ws,int ls, int wm, int lm, int wg, int lg, int pts){
         mjug[nom].actualizar_datos(ws,ls,wm,lm,wg,lg,pts);
    }



    void Cjt_Jugadores::modificar_puntos(const string& f, int pts){
        mjug[f].modif_puntos(pts);
        int h = mjug[f].consul_raking() -1;
        ranking[h].second.first -= pts;
    }

    int Cjt_Jugadores::consultar_puntos(const string& g){
        return mjug[g].consul_puntos();
    }


    void Cjt_Jugadores::restar_global(const string& h, int restar){
            mjug[h].modif_puntos(restar);
            int g = mjug[h].consul_raking();
            ranking[g-1].second.first -= restar;
    }

    int Cjt_Jugadores::consul_posi(const string& g){
        return mjug[g].consul_raking();
    }

    void Cjt_Jugadores::modif_rank_puntos(int j, int pts) {
        ranking[j].second.first += pts;
    }
