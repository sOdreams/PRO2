/** @file Cjt_Jugadores.hh
    @brief Especificación de la clase Cjt_Jugadores
*/


#ifndef _CJT_JUGADORES_HH_
#define _CJT_JUGADORES_HH_
#include "Jugador.hh"
#ifndef NO_DIAGRAM
#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;
#endif
/** @class Cjt_Jugadores
    @brief Representa las caracteristicas de un conjunto de jugadores

    Todas las operaciones son de <b>coste constante</b>
*/

struct AUXI{
      string nombre;
      int puntos;
      int WS;
      int LS;
      int WM;
      int LM;
      int WG;
      int LG;
    };

class Cjt_Jugadores
{
public:


    //Constructoras

    /** @brief Creadora por defecto.
     *
      Se ejecuta automáticamente al declarar un jugador.
      \pre <em>cierto</em>
      \post El resultado es un jugador con todos sus atributos inicializados a cero
    */
    Cjt_Jugadores();



    //Modificadoras

    /** @brief Modificadora de los atributos
     *
      \pre p no existe en el parametro implícito
      \post El parámetro implícito se le añade un jugador p al vector de jugadores
    */
    void nuevo_jugador(const string& p);

    /** @brief Modificadora de los atributos
     *
      \pre p existe en el parametro implícito
      \post El parámetro implícito elimina el jugador con identificador id de su vector
    */
    void eliminar_jugador(const string& id);


    /** @brief Modificadora de los atributos
     *
      \pre <em>cierto</em>
      \post El vector ranking es sorteado con el sort de Algorithm. Posteiormente, cada jugador se le reasigna su nueva posicion del ranking.
      */
    void actualizar_ranking();

    /** @brief Modificadora de los atributos
     *
      \pre <em>cierto</em>
      \post Llama a la funcion actualizar_ranking.
      */
    void Actua_Tor();

    /** @brief Modificadora de los atributos
     *
      \pre <em>cierto</em>
      \post El jugador f, se le restan los puntos pts. Esta operacion se da al bajar un torneo.
      */
    void modificar_puntos(const string& f, int pts);

     /** @brief Modificadora de los atributos
     *
      \pre <em>cierto</em>
      \post El jugador f, se le restan los puntos pts. Esta operacion se da al finalizar un torneo.
      */
    void restar_global(const string& h, int restar);

    /** @brief Modificadora de los atributos
     *
      \pre <em>cierto</em>
      \post Al jugador de identificador nom, se le suman los sets ganados y perdidos, los matches ganados y perdidos y los juegos ganados y perdidos de un torneo.
      */
    void actualizar_datosS(string nom,int ws,int ls, int wm, int lm, int wg, int lg, int pts);

    /** @brief Modificadora de los atributos
     *
      \pre <em>cierto</em>
      \post Al elemento del ranking numero j, se le suman pts puntos.
      */
    void modif_rank_puntos(int j, int pts);

    //Consultoras

    /** @brief Consultora del los jugadores totales
      \pre <em>cierto</em>
      \post El resultado es el numero de elementos del vector del parámetro implícito
    */
    int consultar_mida()const;

    /** @brief Consultora la existencia de un jugador con identificador id
      \pre <em>cierto</em>
      \post El resultado es true si existe un jugador con identificador id
    */
    bool existe_jugador(const string& id);

    /** @brief Consultora los datos jugador con identificador id
      \pre El jugador con identificador id existe
      \post Nos devuelve los datos del jugador con identificador id por el canal de salida
    */
    void consultar_jugador(const string& id);

    /** @brief Consultora del element de la posicion rkn del vector ranking
      \pre El jugador con identificador id existe
      \post Nos devuelve el string id del jugador de la posicion rkn del ranking;
    */
    string consultar_rkn(const int& rkn);

     /** @brief Consultora
     *
      \pre <em>cierto</em>
      \post El resultado de esta operacion son los puntos del jugador con identificador g.
      */
    int consultar_puntos(const string& g);

    /** @brief Consultora
     *
      \pre <em>cierto</em>
      \post El resultado de esta operacion es la posicion del ranking del jugador con identificador g.
      */
    int consul_posi(const string& g);


    //Escritura de jugadores

    /** @brief Operación de escritura

      \pre <em>cierto</em>
      \post Se han escrito el vector del jugadores del parametro implícito en el canal
      standard de salida.
    */
    void escribir_jugadores();

    /** @brief Operación de escritura

      \pre <em>cierto</em>
      \post Se han escrito el vector que representa el ranking del parametro implícito en el canal
      standard de salida.
    */
    void escribir_ranking();



  //Lectura e inicializacion del parametro implícito

    /** @brief Operación de lectura

      \pre <em>cierto</em>
      \post Se han inicializado/rellenado el parametro implícito
    */
    void leer_jugadores(const int& p);

    static bool comp(const pair<string,pair<int,int>>& a,const pair<string,pair<int,int>>& b);

private:
    vector <pair<string,pair<int,int>> > ranking;
    map <string,Jugador> mjug;
    int mida;
};

#endif
