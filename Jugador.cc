#include "Jugador.hh"
#include<iostream>
using namespace std;

    Jugador::Jugador(){
        Ps = WS = LS = WM = LM = WG = LG = Ts = 0;
    }


    int Jugador::consul_puntos() const{
        return Ps;
    }

    void Jugador::escribir_jugador() const{
        cout << "Rk:"<< Rk << " " << "Ps:" << Ps << " " << "Ts:" << Ts << " " << "WM:" << WM << " " << "LM:" << LM << " " << "WS:" << WS << " " << "LS:" << LS << " " << "WG:" << WG << " " << "LG:" << LG << endl;
    }

    void Jugador::mod_ranking(const int& j){
        Rk = j;
    }

    int Jugador::consul_raking()const{
        return Rk;
    }

    void Jugador::actualizar_datos(int ws,int ls, int wm, int lm, int wg, int lg, int pts){
        Ps += pts;
        WS += ws;
        LS += ls;
        WM += wm;
        LM += lm;
        WG += wg;
        LG += lg;
        ++Ts;
    }

    void Jugador::modif_puntos(int n){
        Ps = Ps - n;
    }
