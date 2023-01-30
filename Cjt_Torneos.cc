#include "Cjt_Torneos.hh"
#include<iostream>
#include<map>
using namespace std;


    Cjt_Torneos::Cjt_Torneos(){
        mida = 0;
    }

    void Cjt_Torneos::nuevo_torneo(const Torneo& tor,const string& id){
        map_torneos.insert(make_pair(id,tor));
        ++mida;
    }

    //void Cjt_Torneos::iniciar_torneos(string t, int n){}

    void Cjt_Torneos::eliminar_torneo(const string& id,Cjt_Jugadores& JK){
        if(map_torneos[id].iniciat()){
            map_torneos[id].restar_puntos(JK);
        }
        map_torneos.erase(id);
        --mida;
    }

    void Cjt_Torneos::iniciar_torneoS(const string& t, int n, Cjt_Jugadores Js){
        map_torneos[t].iniciar_torneo(n,Js);
    }

  /*  void Cjt_Torneos::actualizar_ini(const string& t, const Torneo& torn){
        map_torneos.insert(make_pair(t,torn));
    }*/

    int Cjt_Torneos::mida_torneos()const{
        return mida;
    }

    bool Cjt_Torneos::existe_torneo(const string& id){
        map<string,Torneo>::iterator ite = map_torneos.find(id);
        if(ite != map_torneos.end()) return true;
        else return false;
    }


    void Cjt_Torneos::escribir_torneos(Categorias catr){
        cout << mida << endl;
        int g;
        map<string,Torneo>::iterator itr = map_torneos.begin();
        while(itr != map_torneos.end()){
            g = (*itr).second.consul_cate();
            cout << (*itr).second.consul_id_torneo() << " " << catr.cat_nom(g) << endl;
            ++itr;
        }
    }

    void Cjt_Torneos::leer_torneos(const int& t){
        string s;
        int c;
        for(int i = 0; i < t; ++i){
            cin >> s >> c;
            Torneo tor(s,c);
            map_torneos.insert(make_pair(s,tor));
            ++mida;
        }
    }

    void Cjt_Torneos::finalizar_torneo(const string& t, Cjt_Jugadores& Js,const Categorias& cat){
        map_torneos[t].finalizar(Js,cat);
    }

    void Cjt_Torneos::bajar_jugador_tor(const string& f){
        map<string,Torneo>::iterator it = map_torneos.begin();
        for(;it != map_torneos.end();++it){
            (*it).second.eliminar_jugador(f);
        }
    }
