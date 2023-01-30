/** @file Categorias.hh
    @brief Especificación de la clase Categorias
*/

#ifndef _CATEGORIAS_HH_
#define _CATEGORIAS_HH_

#ifndef NO_DIAGRAM
#include <iostream>
#include <vector>
#endif
using namespace std;

/** @class Categorias
    @brief Representa las categorias con sus respectivos niveles de los torneos
*/
class Categorias
{
public:


    //Constructora

    /** @brief Creadora por defecto.

      Se ejecuta automáticamente al declarar categorias.
      \pre <em>cierto</em>
      \post El resultado es una matriz y un vector
    */
    Categorias();

     /** @brief Creadora con valores concretos
      Da un tamaño al vector y a la matriz
      \pre c >= 1, k >= 4
      \post El resultado es una matriz y un vector
    */
    Categorias(const int& c,const int& k);



     //Consultoras

    /** @brief Consultora del valor de una posicion de la matriz
      \pre <em>cierto</em>
      \post El resultado es un entero que se encuentra en la posicion i,j de la matriz
    */
    int puntos(int i, int j);

    /** @brief Consultora del nombre de la categoria
      \pre Para todo h >= 1, h <= C
      \post El resultado es un string que representa el nombre de la categoria h
    */
    string cat_nom(int h);

    /** @brief Consultora
      \pre <em>cierto</em>
      \post Devuelve el entero que representa el tamaño de un vector de la matriz. Devuelve K (numero de niveles).
    */
    int tamany();



    //Lectura e inicializacion de los parametros implicitos

    /** @brief Operación de lectura

      \pre <em>cierto<em>
      \post Se ha inicializado el vector y la matriz del parametro implicito
    */
    void leer_categorias();



     //Escritura

    /** @brief Operación de escritura

      \pre <em>cierto</em>
      \post Se ha escrito el nombre de las categorias seguido de los puntos de cada nivel de dicha categoria.
    */
    void escribir_categorias();

private:
    vector <vector<int> > categorias; //i = categoria | j = niveles
    vector <string> ident_cat; //1-C nombre de las categorias
};

#endif
