/** @file Jugador.hh
    @brief Especificación de la clase Jugador
*/


#ifndef _JUGADOR_HH_
#define _JUGADOR_HH_
#ifndef NO_DIAGRAM
#include <iostream>
#include <map>
#include <string>
#endif
using namespace std;

/** @class Jugador
    @brief Representa las caracteristicas/estadisticas de un jugador

    Todas las operaciones son de <b>coste constante</b>
*/

class Jugador
{
public:


    //Constructoras

    /** @brief Creadora por defecto.

      Se ejecuta automáticamente al declarar un jugador.
      \pre <em>cierto</em>
      \post El resultado es un jugador con todos sus atributos inicializados a cero
    */
    Jugador();



    //Modificadoras

    /** @brief Modificadora de los atributos
      \pre <em>cierto</em>
      \post El parámetro implícito a actualizar sus atributos.
    */
    void actualizar_datos(int ws,int ls, int wm, int lm, int wg, int lg, int pts);

    /** @brief Modificadora del ranking
      \pre <em>cierto</em>
      \post j pasa a ser el valor del atributo Rk del jugador
    */
    void mod_ranking(const int& j);

    /** @brief Modificadora del ranking
      \pre <em>cierto</em>
      \post Se le restan pts al atributo puntos del jugador.
      */
    void modif_puntos(int pts);



    //Consultoras

    /** @brief Consultora de los puntos
      \pre <em>cierto</em>
      \post El resultado son los puntos del parámetro implícito
    */
    int consul_puntos() const;

   /** @brief Consultora de los puntos
      \pre <em>cierto</em>
      \post El resultado son los puntos del parámetro implícito
    */
    int consul_raking()const;



    //Escritura de jugador

    /** @brief Operación de escritura

      \pre <em>cierto</em>
      \post Se han escrito los atributos del parámetro implícito en el canal
      standard de salida.
    */
    void escribir_jugador() const;

private:
    int Rk;
    int Ps;
    int WS;
    int LS;
    int Ts;
    int WM;
    int LM;
    int WG;
    int LG;
};

#endif
