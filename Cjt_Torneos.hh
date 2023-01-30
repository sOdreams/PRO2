/** @file Cjt_Torneos.hh
    @brief Especificación de la clase Cjt_Torneos
*/

#ifndef _CJT_TORNEOS_HH_
#define _CJT_TORNEOS_HH_
#include "Torneo.hh"
#ifndef NO_DIAGRAM
#include <map>
#include "Categorias.hh"
#include"Cjt_Jugadores.hh"
#include <iostream>
using namespace std;
#endif

/** @class Cjt_Torneos
    @brief Representa las caracteristicas de un conjunto de torneos

    Todas las operaciones son de <b>coste constante</b>
*/


class Cjt_Torneos
{
public:


    //Constructoras

    /** @brief Creadora por defecto.
     *
      Se ejecuta automáticamente al declarar Cjt_Torneos.
      \pre <em>cierto</em>
      \post El resultado es una matriz y un vector
    */
    Cjt_Torneos();

    /** @brief Creadora con valores concretos.
     *
      Se ejecuta automáticamente al declarar un conjunto de torneos.
      \pre <em>cierto</em>
      \post El resultado es un conjunto de torneos con torneos sin inicializar y un vector que representa los nombres de la categorias
    */



    //Modificadoras

    /** @brief Modificadora de los
     *
      \pre tor no existe en el parametro implícito
      \post El parámetro implícito se le añade un torneo tor
    */
    void nuevo_torneo(const Torneo& tor, const string& id);

    /** @brief Modificadora/Inicializadora
     *
      \pre El torneo con identificador t existe en el map. n>= 0
      \post El torneo con identificador es iniciado con n jugadores
    */
    void iniciar_torneoS(const string& t, int n,  Cjt_Jugadores Js);

    /** @brief Modificadora de los atributos
     *
      \pre el Torneo con nombre id existe en el parametro implícito
      \post el torneo con nombre id es eliminado del parametro implicito, pero si dicho torneo tiene una edicion anterior
      \post a los jugadores de esa edicion anterior se les restan los puntos en el conjunto jugadores general que es donde se encuentra el ranking.
      \post Una vez restado los puntos, se reorganiza el vector de ranking del conjunto jugaodres.
    */
    void eliminar_torneo(const string& id, Cjt_Jugadores& JK);

    /** @brief Modificadora de los atributos
     *
      \pre <em>cierto</em>
      \post Se finaliza el torneo de identificador t y todo lo que esa accion implica.
    */
    void finalizar_torneo(const string& t, Cjt_Jugadores& Js,const Categorias& cat);

    /** @brief Modificadora de los atributos
     *
      \pre <em>cierto</em>
      \post Se ha hecho un recorrido por todos los torneos del cjn_Torneos
      \post y en todos aquellos torneos en los que el jugador f aparecia en la edicion anterior, sus puntos han sido reemplazados por ceros.
    */
    void bajar_jugador_tor(const string& f);




    //Consultoras

    /** @brief Consultora del los torneos totales
      \pre <em>cierto</em>
      \post El resultado es el numero de elementos del mapa del parametro implicito
    */
    int mida_torneos()const;

    /** @brief Consultora la existencia de un torneo con nombre id
      \pre <em>cierto</em>
      \post El resultado es true si existe un torneo de nombre id
    */
    bool existe_torneo(const string& id);

    /** @brief Consultora.
      \pre <em>cierto</em>
      \post Devuelve un Torneo cuyo identificador es t;
    */


    //Escritura de torneos

    /** @brief Operación de escritura

      \pre <em>cierto</em>
      \post Se han escrito el map del torneos del parametro implícito en el canal
      standard de salida.
    */
    void escribir_torneos( Categorias catr);


    //Lectura e inicializacion del parametro implícito

    /** @brief Operación de lectura

      \pre <em>cierto</em> t >= 0
      \post Se ha inicializado el mapa del parametro implicito con exactamente t elementos
    */
    void leer_torneos(const int& t);

private:
    map <string, Torneo> map_torneos;
    int mida;
};

#endif
