#include "Torneo.hh"
#include<iostream>
#include<vector>
using namespace std;

    Torneo::Torneo(){}

    Torneo::Torneo(const string& nom, int cat){
        torneo = nom;
        cate = cat;
        edi = false;
    }

    string Torneo::consul_id_torneo()const{
        return torneo;
    }

    int Torneo::consul_cate(){
        return cate;
    }

    bool Torneo::iniciat(){
        return edi;
    }

    void Torneo::leer_arbol_inicial(BinTree<int>& a, int numero,const int& max,int acu_dere,int prof){
        bool mirar = (acu_dere - numero + 1 <= max);
        if (not mirar){
            a = BinTree<int>(numero);
        }
        else if(mirar){
            BinTree<int> iz;
            BinTree<int> de;
            int numero_dere = acu_dere - numero + 1;
            acu_dere *= 2;
            ++prof;
            leer_arbol_inicial(iz,numero,max,acu_dere,prof);
            leer_arbol_inicial(de,numero_dere,max,acu_dere,prof);
            a = BinTree<int>(numero,iz,de);
        }
    }

    void Torneo::iniciar_torneo(int n,Cjt_Jugadores& Js){
        int rkn;
        string f;
        r_actual = vector<AUXI>(n);
        for(int i = 0; i < n; ++i){
            cin >> rkn;
            f = Js.consultar_rkn(rkn);
            r_actual[i].nombre = f;
            r_actual[i].WS = 0;
            r_actual[i].LS = 0;
            r_actual[i].WM = 0;
            r_actual[i].LM = 0;
            r_actual[i].WG = 0;
            r_actual[i].LG = 0;
        }
        BinTree<int> a;
        leer_arbol_inicial(a,1,n,2,0);
        emparejamiento = a;
        mostrar_cuadro_inicial(emparejamiento);
        mida_tor = n;
        cout << endl;
    }


    void Torneo::mostrar_cuadro_inicial(const BinTree<int>& a){
        if(a.left().empty() and a.right().empty()) cout << a.value() << "." << r_actual[(a.value()-1)].nombre;
        else{
        if(not a.left().empty()){
             cout << "(";
             mostrar_cuadro_inicial(a.left());
             cout << " ";
        }
        if(not a.right().empty()) mostrar_cuadro_inicial(a.right());
        cout << ")";
        }
    }


    void Torneo::hacer_cuadro_resultados(BinTree<pair<string,pair<int,int> > >& res, int& max, string valor){
        if(max == 0)return;
        else{
            BinTree<pair<string,pair<int,int> > > izq;
            BinTree<pair<string,pair<int,int> > > dere;
            string i, d;
            cin >> i;
            if(i != "0") hacer_cuadro_resultados(izq,--max,i);
            cin >> d;
            if(d != "0") hacer_cuadro_resultados(dere,--max,d);
            res = BinTree<pair<string,pair<int,int> >>(make_pair(valor,make_pair(0,0)),izq,dere);
        }
    }

    bool Torneo::analizar_resultados(const string& s, int iz, int de, bool ojo){
            int a, b;
            int w, m;
            int aux1, aux2;
            aux1 = aux2 = 0;
            a = b = 0;
            int mida = s.size();
            if(mida > 3){
                int i = 1;
                while(i < mida){
                   if(s[i] == '-'){
                        w = (s[i-1] - '0');
                        m = (s[i+1] - '0');
                        a += w;
                        b += m;

                        if(w > m) {
                            if(ojo){
                                ++r_actual[iz-1].WS;
                                ++r_actual[de-1].LS;
                            }
                            ++aux1;
                        }
                        else if(w < m){
                            if(ojo){
                                ++r_actual[de-1].WS;
                                ++r_actual[iz-1].LS;
                            }
                            ++aux2;
                        }
                    }
                    i += 4;
                }

                if(ojo){
                    r_actual[iz-1].WG += a;
                    r_actual[iz-1].LG += b;

                    r_actual[de-1].WG += b;
                    r_actual[de-1].LG += a;
                }

                if(aux1>aux2) {
                    if(ojo){
                        ++r_actual[iz-1].WM;
                        ++r_actual[de-1].LM;
                    }
                    return true;
                }
                else if(aux2>aux1){
                    if(ojo){
                        ++r_actual[de-1].WM;
                        ++r_actual[iz-1].LM;
                    }

                    return false;
                }
                else if(aux2>aux1){
                       if(ojo){
                        ++r_actual[de-1].WM;
                        ++r_actual[iz-1].LM;
                    }
                        return false;
                }
            }
            else{
                if(s[0] == '1'){
                    if(ojo){
                        ++r_actual[iz-1].WM;
                        ++r_actual[de-1].LM;
                    }
                    return true;
                }else{

                    if(ojo){
                        ++r_actual[de-1].WM;
                        ++r_actual[iz-1].LM;
                    }
                    return false;
                }
            }
            return true;
    }

    void Torneo::actualizar_arboles(BinTree<pair<string,pair<int,int> >>& res, BinTree<int>& a){
             if(res.empty()) return;
             else{
                BinTree<int> l, r;
                l = a.left();
                r = a.right();
                BinTree<pair<string,pair<int,int> >> Rl, Rr;
                Rl = res.left();
                Rr = res.right();
                actualizar_arboles(Rl,l);
                actualizar_arboles(Rr,r);

                if(analizar_resultados(res.value().first,l.value(),r.value(),true)){
                    a = BinTree<int>(l.value(),l,r);
                }
                else {
                    a = BinTree<int>(r.value(),l,r);
                }

                pair<string,pair<int,int> > f = pair<string,pair<int,int> >(make_pair(res.value().first,make_pair(l.value(),r.value())));
                res = BinTree<pair<string,pair<int,int> >>(f,Rl,Rr);
            }

    }


    void Torneo::muestra_final(const BinTree<pair<string,pair<int,int> > >& res){
        cout <<"(" << res.value().second.first << "." << r_actual[res.value().second.first-1].nombre << " vs " << res.value().second.second << "." << r_actual[res.value().second.second -1].nombre << " " << res.value().first;
        if(not res.left().empty()){
            muestra_final(res.left());
        }
        if(not res.right().empty()){
            muestra_final(res.right());
        }
        cout << ")";
    }

    void Torneo::poner_puntos(const BinTree<pair<string,pair<int,int> >>& res,int pos, int j, int max,  Categorias catr){
        if(res.empty()) return;
        else {
            if(res.value().second.first != pos and j < max){
                r_actual[res.value().second.first -1].puntos = catr.puntos(cate-1,j);
            }
            else if(j < max){
                r_actual[res.value().second.second -1].puntos = catr.puntos(cate-1,j);
            }
            int h = res.value().second.first;
            int k = res.value().second.second;
            ++j;
            poner_puntos(res.left(),h,j,max,catr);
            poner_puntos(res.right(),k,j,max,catr);
        }
    }


    void Torneo::restar_puntos(Cjt_Jugadores& Js){
        int mida = vec_anterior.size();
        for(int i = 0; i < mida; ++i){
            if(Js.existe_jugador(vec_anterior[i].first)){
                    int k = vec_anterior[i].second;
                    Js.modificar_puntos(vec_anterior[i].first,k);
                    }
            }
        Js.actualizar_ranking();
    }

    void Torneo::finalizar(Cjt_Jugadores& Js,Categorias categoria){
        BinTree <pair<string,pair<int,int> > > res;
        string g;
        cin >> g;
        int c = 2*(mida_tor)-1;
        hacer_cuadro_resultados(res,c,g);
        actualizar_arboles(res,emparejamiento);
        muestra_final(res);


        if(analizar_resultados(res.value().first,res.value().second.first,res.value().second.second,false)){
            r_actual[res.value().second.first -1].puntos = categoria.puntos(cate-1,0);
            r_actual[res.value().second.second -1].puntos = categoria.puntos(cate-1,1);
        }else{
            r_actual[res.value().second.first -1].puntos = categoria.puntos(cate-1,1);
            r_actual[res.value().second.second -1].puntos = categoria.puntos(cate-1,0);
        }
        int A = res.value().second.first;
        int B = res.value().second.second;
        int j = 2;
        int max = categoria.tamany();
        poner_puntos(res.left(),A,j,max,categoria);
        poner_puntos(res.right(),B,j,max,categoria);
        cout << endl;

        for(int f = 0 ; f < mida_tor; ++f) {
            if(r_actual[f].puntos != 0){
                cout << f+1 << "." << r_actual[f].nombre << " " << r_actual[f].puntos << endl;
            }
        }

        if(edi){
            int mida_ant = vec_anterior.size();
            for(int i = 0; i< mida_ant; ++i){
                if(vec_anterior[i].second != 0){
                    Js.restar_global(vec_anterior[i].first,vec_anterior[i].second);
                }
            }
            vector<pair<string,int>> vec_aux(mida_tor);
            for(int i = 0; i < mida_tor; ++i){
                vec_aux[i] = make_pair(r_actual[i].nombre,r_actual[i].puntos);
            }
            vec_anterior = vec_aux;

        }
        else{
            edi = true;
            vector<pair<string,int>> vec_aux(mida_tor);
            for(int i = 0; i < mida_tor; ++i){
                vec_aux[i] = make_pair(r_actual[i].nombre,r_actual[i].puntos);
            }
            vec_anterior = vec_aux;
        }
        string RR;
        int Wss, Lss, Wmm,Lmm,Wgg,Lgg,pts;
        for(int i = 0; i < mida_tor; ++i){
            RR = r_actual[i].nombre;
            Wss = r_actual[i].WS;
            Lss = r_actual[i].LS;
            Wmm = r_actual[i].WM;
            Lmm = r_actual[i].LM;
            Wgg = r_actual[i].WG;
            Lgg = r_actual[i].LG;
            pts = r_actual[i].puntos;
            Js.actualizar_datosS(RR,Wss,Lss,Wmm,Lmm,Wgg,Lgg,pts);
            int j = Js.consul_posi(RR)-1;
            Js.modif_rank_puntos(j,pts);
        }
        Js.Actua_Tor();
    }

    void Torneo::eliminar_jugador(const string& g){
        int mida = vec_anterior.size();
        int i = 0;
        while(i < mida) {
            if(vec_anterior[i].first != g){
                ++i;
            }
            else{
                vec_anterior[i].second = 0;
                i = mida;
            }
        }
    }
