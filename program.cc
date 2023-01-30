/** @file pro2_practica.cc
    @brief Programa principal para la practica <em>GestiÃ³n de un circuito de tenis</em>.
*/
#include "BinTree.hh"
#include "Categorias.hh"
#include "Cjt_Jugadores.hh"
#include "Cjt_Torneos.hh"
#include "Torneo.hh"
#ifndef NO_DIAGRAM

#endif
using namespace std;

int main(){
    int C,K,T,P;

    //lectura de categorias
    cin >> C >> K;
    Categorias cat(C,K);
    cat.leer_categorias();
    //vector< vector<int> > PC;
    //PC = cat.pasar_puntos();

    //lectura de torneos
    //vector<string> ides;
    //ides = cat.pasar_vector();
    cin >> T;
    Cjt_Torneos Ts;
    Ts.leer_torneos(T);

    //lectura de jugadores
    cin >> P;
    Cjt_Jugadores Js;
    Js.leer_jugadores(P);

    //repertorio de comandos
    string comando;
    cin >> comando;
    while(comando != "fin") {
        if(comando == "nuevo_jugador" or comando == "nj") {
            string p;
            cin >> p;
            cout << "#" << comando << " " <<  p << endl;
            Js.nuevo_jugador(p);
        }
        else if(comando == "nuevo_torneo" or comando == "nt") {
            int n;
            string t;
            cin >> t >> n;
            cout << "#" << comando << " " << t << " " << n << endl;
            if(n > C or n <= 0) cout << "error: la categoria no existe" << endl;
            else if (Ts.existe_torneo(t)) cout <<"error: ya existe un torneo con ese nombre" << endl;
            else {
                Torneo tor(t,n);
                Ts.nuevo_torneo(tor,t);
                cout << Ts.mida_torneos() << endl;
            }
        }
        else if(comando == "baja_jugador" or comando == "bj") {
            string p;
            cin >> p;
            cout << "#" << comando << " " <<  p << endl;
            if(Js.existe_jugador(p)){
                Js.eliminar_jugador(p);
                Ts.bajar_jugador_tor(p);
            }else cout << "error: el jugador no existe"<< endl;
        }
        else if(comando == "baja_torneo" or comando == "bt") {
                string t;
                cin >> t;
                cout << "#" << comando << " " << t << endl;
                if(not Ts.existe_torneo(t)) cout << "error: el torneo no existe" << endl;
                else {
                    Ts.eliminar_torneo(t,Js);
                    cout << Ts.mida_torneos() << endl;
                }
        }
        else if(comando == "iniciar_torneo" or comando == "it") {
                string t;
                cin >> t;
                cout << "#" << comando << " " << t << endl;
                //Torneo torn = Ts.copiar_torneo(t);
                int n;
                cin >> n;
                Ts.iniciar_torneoS(t,n,Js);
                /*
                vector<string> rf(n);
                for(int i = 0; i < n; ++i){
                    cin >> rkn;
                    f = Js.consultar_rkn(rkn);
                    rf[i] = f;
                }
                torn.copiar_vran(rf);
                torn.iniciar_torneo(n);
                Ts.actualizar_ini(t,torn);
                */
        }

        else if(comando == "finalizar_torneo" or comando == "ft") {
                string t;
                cin >> t;
                cout << "#" << comando << " " << t << endl;
                Ts.finalizar_torneo(t,Js,cat);
                //Js.Actua_Tor(Ts.pasar_INFO(t));
                /*
                Torneo tn = Ts.copiar_torneo(t);
                BinTree<string> res;
                leer_res(res);
                tn.analizar_resultados(res);
                Cjt_Jugadores jug = tn.pasar_jugadores();
                jug.escribir_jugadores();
                */
        }
        else if(comando == "listar_ranking" or comando == "lr") {
                cout << "#" << comando << endl;
                Js.escribir_ranking();
        }
        else if(comando == "listar_jugadores" or comando == "lj") {
                cout << "#" << comando << endl;
                cout << Js.consultar_mida() << endl;
                Js.escribir_jugadores();
        }
        else if(comando == "consultar_jugador" or comando == "cj"){
            string p;
            cin >> p;
            cout << "#" << comando << " " << p << endl;
            if(Js.existe_jugador(p)){
                Js.consultar_jugador(p);
            }else cout << "error: el jugador no existe" << endl;
        }
        else if(comando == "listar_torneos" or comando == "lt"){
            cout << "#" << comando << endl;
            Ts.escribir_torneos(cat);
        }
        else if(comando == "listar_categorias" or comando == "lc") {
                cout << "#" << comando << endl;
                cat.escribir_categorias();
        }
        cin >> comando;
    }
}
