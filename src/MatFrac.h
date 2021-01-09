/*
  Proyecto de Programación Orientada a objetos
  @Autor: Esteban Padilla Cerdio
  @Fecha de creación: 07/01/2021
  @Última modificación: 10/01/2021
  @Archivo: MatFrac.h
*/

/*
  Clase para la representación de matrices de fracciones y sus herramientas
  para transformación y operación aritmética

  //NOTA -> Esta versión únicamente trabaja con archivos CSV que siguen el
            siguiente formato de filas, columnas y fracciones

                                1/2,1/2,1/2
                                1/2,1/2,1/2
                                1/2,1/2,1/2

*/

#include "Fraccion.h"

#include <iostream>
#include <string>
#include <vector>
using namespace std;

#pragma once


//Declaración a futuro de las clases utilizadas
Fraccion fraccion;

class MatFrac{

  public:

    /*
-------------------------Constructores-----------------------------------------
      Constructor default, genera una matriz vacía de dimensiones 0x0
    */
    MatFrac();

    /*
      Constructor que genera una matriz de rxc con fracciones de valor 0/1
    */
    MatFrac(int,int);

    /*
      Constructor que genera una matriz de forma dinámica según los datos
      de un archivo CSV
    */
    MatFrac(string);



    /*
------------------------------Getters y Setters--------------------------------

      Obtiene la cantidad de filas de la matriz
      @return  número de filas
    */
    int getRows() const;

    /*
      Obtiene la cantidad de columnas de la matriz
      @return número de columnas
    */
    int getCols() const;

    /*
      Establece la cantidad de filas de la matriz
      @param int r - número de filas
    */
    void setRows(int);

    /*
      Establece la cantidad de columnas de la matriz
      @param int c - número de columnas
    */
    void setCols(int);

    /*
      Obtiene el objeto de Fracción en el índice especificado por coordenadas
      de la matriz
      @param int i - coordenada en y
             int j - coordenada en x
      @return el objeto de fracción en ese índice
    */
    Fraccion getFrac(int,int) const;

    /*
      Establece un objeto de Fracción en el índice especificado por coordenadas
      @param  Fraccion f - la fracción a establecer
              int i - coordenada en y
              int j - coordenada en x
    */
    void setFrac(Fraccion,int,int);



    /*
----------------------------Herramientas de Clase------------------------------

      Imprime la matriz en la consola separada por filas y columnas
    */
    void imprimir();

    /*
      Extrae la información de un archivo CSV y genera una matriz con sus datos
      y dimensiones
      @param string ruta - la ruta al archivo CSV
    */
    void readData(string);


    /*
      Transforma la matriz a formato CSV y escribe el resultado en un
      archivo en la ruta especificada
      @param string ruta - la ruta al archivo CSV de destino
    */
    void exportar(string);

    /*
      Compara las dimensiones de la matriz con las dimensiones de otra para
      verificar si son iguales
      @param MatFrac otra - la segunda matriz para comparar
      @return si sus dimensiones son iguales
    */
    bool comparar(MatFrac const &);

    /*
      Transforma la matriz a una string con columnas separadas por espacios y
      filas separadas por newlines
      @return la string generada
    */
    string aString();

    /*
      Transforma la matriz a una string con columnas separadas por comas y
      filas separadas por newlines
      @return la string generada
    */
    string aCsv();

    /*
      Transforma la matriz a una string con columnas separadas por el caracter
      especificado filas separadas por newlines
      @param string c - el caracter de separación
      @return la string generada
    */
    string join(string);



    /*
----------------------Herramientas de aritmética de fracciones------------------

      Suma esta matriz con otra, elemento por elemento
      @param MatFrac other - otra matriz
      @return una matriz equivalente a la suma de elementos
    */
    MatFrac sum(MatFrac const &);

    /*
      Resta esta matriz con otra, elemento por elemento
      @param MatFrac other - otra matriz
      @return una matriz equivalente a la resta de elementos
    */
    MatFrac sub(MatFrac const &);

    /*
      Multiplica esta matriz con otra, elemento por elemento
      @param MatFrac other - otra matriz
      @return una matriz equivalente a la multiplicación de elementos
    */
    MatFrac mult(MatFrac const &);

    /*
      Divide esta matriz por otra, elemento por elemento
      @param MatFrac other - otra matriz
      @return una matriz equivalente a la división de elementos
    */
    MatFrac div(MatFrac const &);



    /*
--------------------Sobrecarga de operadores aritméticos-----------------------

      Operador de adición
    */
    MatFrac operator+(MatFrac const &);

    /*
      Operador de sustracción
    */
    MatFrac operator-(MatFrac const &);

    /*
      Operador multiplicativo
    */
    MatFrac operator*(MatFrac const &);

    /*
      Operador divisor
    */
    MatFrac operator/(MatFrac const &);

  private:

    /*
      Atributos
      número de filas y columnas de la matriz
    */
    int rows, cols;

    /*
      Matriz dinámica para guardar los elementos del objeto
    */
    vector<vector<Fraccion>>  matrix;




};
