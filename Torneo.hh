/** @file Torneo.hh
    @brief Especificación de la clase Torneo
*/

#ifndef _TORNEO_HH_
#define _TORNEO_HH_
#include "Cjt_Jugadores.hh"
#ifndef NO_DIAGRAM
#include<iostream>
#include"Categorias.hh"
#include<map>
#include<vector>
#include "BinTree.hh"
#endif
using namespace std;

/** @class Torneo
    @brief Representa las caracteristicas de un torneo

    Todas las operaciones son de <b>coste constante</b>
*/


class Torneo
{
public:
    //Constructoras

    /** @brief Creadora por defecto.
     *
      Se ejecuta automáticamente al declarar un torneo.
      \pre <em>cierto</em>
      \post El resultado es un torneo con todos sus atributos inicializados a cero.
    */
    Torneo();

    /** @brief Creadora con valores concretos.

      \pre <em>cierto</em>
      \post El resultado es un Torneo con nombre nom y categoria cat.
    */
    Torneo(const string& nom,int cat);




     //Consultoras

    /** @brief Consultora del nombre
     *
      \pre <em>cierto</em>
      \post El resultado es el nombre del torneo.
    */
    string consul_id_torneo()const;

    /** @brief Consultora
     *
      \pre <em>cierto</em>
      \post El resultado es un bool que representa si el torneo tiene una edición anterior.
      \post Si iniciat == TRUE, quiere decir que existe una edición anterior del torneo.
    */
    bool iniciat();

    /** @brief Consultora de la categoria
     *
      \pre <em>cierto</em>
      \post El resultado de esta operación nos devuelve el entero que representa
      \post la categoría a la que percete el torneo.
    */
    int consul_cate();




     //Modificadoras

     /** @brief Modificadora
      *
      \pre  Dado n = nº jugadores, 0 < max < 2*n-1 (coincide con el numero de resultados del input)
      \pre valor es el string que cada nodo del árbol tendrá y en cada recursión max augmenta en uno.
      \post Se crea un árbol que representa los resultados. Inicialmente los jugadores participados
      \post en cada partido se desconocen, por eso se asigna un 0 en ambos int del segundo pair.

    */
    void hacer_cuadro_resultados(BinTree<pair<string,pair<int,int> > >& res, int& max, string valor);

    /** @brief Modificadora
     *
      \pre iz y de, es el entero que representa el jugador del vector. Por lo tanto 0 <= iz y de < nº jugadores.
      \pre El string s, hace referencia al resultado del partido entre iz y de.
      \pree El booleano ojo si es TRUE, analiza y modifica los sets de los jugadores iz y de. Si es FALSE, simplemente nos dice quién ha ganado.
      \post Este operacion además de decirnos quien ha ganado, TRUE si gana iz, FALSE, en el caso contrario, también actualiza las estadísticas
      \post de los jugadores iz y de.
    */
    bool analizar_resultados(const string& s, int iz, int de,bool ojo);


    /** @brief Modificadora de los atributos
     *
      \pre <em>cierto</em>
      \post Se crea un árbol de resultados con los inputs llamando a la funcion hacer_cuadro_resultados.
      \post Una vez creada el arbol con los resultados y los jugadores de cada partido, se llama a muestra_final para imprimir los resultados en preorden.
      \post Posteriormente se actualiza dicho árbol haciendo una doble recursion sobre el árbol de empajejamiento
      \post y el árbol para asignar los jugadores de cada partido. A la par que se asigna los jugadores (con la fucion analizar_resultados), también se modifica
      \post el vector de struct en el cual se hayan los jugadores de la actual edición.
      \post Una vez que se haya asigando a cada jugador sus sets
      \post ganados y perdidos, matches ganados y perdidos y juegos ganados y perdidos.
      \post Ahora falta asignar los puntos de cada jugador. Para hacer dicha tarea se llama a la funcion poner_puntos en el cual pasamos el arbol de resultados
      \post ya que en dicho arbol tenemos los jugadores de cada nivel.
      \post Una vez tenemos los puntos de cada jugadores, se imprime los jugadores cuya puntuacion no haya sido nula.
      \post finalmente, se actualiza los datos de cada jugador en el conjunt de jugadores, donde se haya el ranking.
      \post Una vez actualizado los datos de cada jugador que haya participado en el torneo, se reorganiza el ranking.
    */
    void finalizar(Cjt_Jugadores& Js, Categorias cat);

    /** @brief Modificadora
     *
      \pre <em>cierto</em>
      \pre El metodo empleado es una doble recursion en post orden, para saber el ganador del siguente nodo. El caso base es cuando res (arbo de resultados) este vacio.
      \post Esta operacion se llama dentro de finalizar. El resultado es un arbol de resultados, donde esten los jugadores que han participado en cada match.
      */
    void actualizar_arboles(BinTree<pair<string,pair<int,int> >>& res, BinTree<int>& a);

    /** @brief Modificadora
     *
      \pre <em>cierto</em>
      \pre max es el tamaño de un vector de la matriz de puntos de la clase Categorias. 0 <= j < max
      \post Esta acción, hace una recursion en preorden, poniendo los puntos de cada jugador del arbol de resultados en funcion del ganador del nodo anterior.
      */
    void poner_puntos(const BinTree<pair<string,pair<int,int> >>& res,int pos, int j, int max, Categorias catr);

    /** @brief Modificadora
     *
      \pre Se ha hecho un baja_torneo t, y el torneo t tiene una edicion anterior.
      \post Se restan los puntos de los jugadores que hayan participado en la edicion anteiror y posteriormente se reordena el vector de ranking.
      */
    void restar_puntos(Cjt_Jugadores& Js);


    /** @brief Modificadora
     *
      \pre Se ha hecho un baja_jugador p.
      \post Si el jugador p se encuentra en la edicion anterior del torneo, entonces se pone a cero sus puntos ganados.
      */
    void eliminar_jugador(const string& g);


    //Lectura

    /** @brief Operación de lectura

      \pre a es el árbol que será modificado en funcián de max (#jugadores)
      \post numero indica el valor de cada nodo. acu_dere es el parametro 2^(-1). Al iniciar es 2. Prof es la profundidad
      \post El arbol a, es el arbol que representa el emparejamiento al iniciar torneo.
    */
    void leer_arbol_inicial(BinTree<int>& a, int numero,const int& max,int acu_dere,int prof);

    /** @brief Operación de lectura

      \pre <em>cierto</em>
      \post Se ha inicializado el torneo con n jugadores ordenados por su ranking actual. Se ponen esos jugadores en un vector de struct
      \post en el cual tienen todas sus estadisticas a cero y al string se le asigna el nombre que se haya en la posicion del ranking del conjunto de jugadores (ranking general).
      \post Finalmente se muestran el cuadro de emparejamiento.
    */
    void iniciar_torneo(int n ,Cjt_Jugadores& Js);

    //Escritura

    /** @brief Operación de escritura

      \pre <em>cierto</em>
      \post imprime el cuadro oficial de resultados
    */
    void muestra_final(const BinTree<pair<string,pair<int,int> > >& res);

    /** @brief Operación de escritura

      \pre <em>cierto</em>
      \post imprime el cuadro de emparejamiento inicial
    */
    void mostrar_cuadro_inicial(const BinTree<int>& a);


private:

    string torneo;
    int cate;
    bool edi;
    vector<AUXI> r_actual;
    vector<pair<string,int>> vec_anterior;
    BinTree <int> emparejamiento;
    int mida_tor;
};

#endif
