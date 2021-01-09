/*
  Proyecto de Programación Orientada a objetos
  @Autor: Esteban Padilla Cerdio
  @Fecha de creación: 07/01/2021
  @Última modificación: 10/01/2021
  @Archivo: Fraccion.h
*/

/*
  Clase para la representación de fracciones como tipo de dato y su uso en
  operaciones aritméticas.
*/

#include <iostream>
#include <string>
using namespace std;

#pragma once


class Fraccion{

  public:
    /*
-------------------------Constructores-----------------------------------------
    Constructor default, genera una fracción con valor 0/1
    */
    Fraccion();

    /*
    Constructor que genera una fracción con numerador y denominador específico
    @param int num - numerador
           int den - denominador
    */
    Fraccion(int,int);



    /*
------------------------------Getters y Setters--------------------------------

    Obtiene el denominador de la fracción
    @return denominador
    */
    int getDen() const;

    /*
    Obtiene el numerador de la fracción
    @return numerador
    */
    int getNum() const;

    /*
    Asigna un entero al denominador de la fracción
    @param int d - denominador
    */
    void setDen(int);

    /*
    Asigna un entero al numerador de la fracción
    @param int n - numerador
    */
    void setNum(int);



    /*
----------------------------Herramientas de Clase------------------------------

      Imprime la fracción en la consola
      @return la función en formato string
    */
    string imprimir();

    /*
      Transforma la fracción en una string
      @return la función en formato string
    */
    string aString() const;

    /*
      Calcula el valor decimal de la fracción
      @return el valor decimal
    */
    float aDecimal() const;

    /*
      Compara la fracción a otra según su valor en decimal
      @param Fraccion f - la fracción con la que se comparará
      @return 1 si es mayor, 0 si son iguales, -1 si la otra es mayor
    */
    int comparar(Fraccion const&);

    /*
      Genera una copia de la fracción
      @return objeto de fraccion
    */
    Fraccion copiar();


    /*
----------------------Herramientas de aritmética de fracciones------------------

      Suma esta fracción con otra
      @param const f - otra fracción
      @return una fracción equivalente a la suma
    */
    Fraccion sum(Fraccion const &);

    /*
      Resta esta fracción con otra
      @param const f - otra fracción
      @return una fracción equivalente a la resta
    */
    Fraccion sub(Fraccion const &);

    /*
      Multiplica esta fracción con otra
      @param const f - otra fracción
      @return una fracción equivalente a la multiplicación
    */
    Fraccion mult(Fraccion const &);

    /*
      Divide esta fracción por otra
      @param const f - otra fracción
      @return una fracción equivalente a la división
    */
    Fraccion div(Fraccion const &);



    /*
--------------------Sobrecarga de operadores aritméticos-----------------------

      Operador multiplicativo
    */
    Fraccion operator*(Fraccion const &);

    /*
      Operador divisor
    */
    Fraccion operator/(Fraccion const &);

    /*
      Operador de adición
    */
    Fraccion operator+(Fraccion const &);

    /*
      Operador de sustracción
    */
    Fraccion operator-(Fraccion const &);



    /*
--------------------Sobrecarga de operadores de comparación---------------------

      Comparador mayor que
    */
    bool operator>(Fraccion const &);

    /*
      Comparador menor que
    */
    bool operator<(Fraccion const &);

    /*
      Comparador mayor o igual que
    */
    bool operator>=(Fraccion const &);

    /*
      Comparador menor o igual que
    */
    bool operator<=(Fraccion const &);

    /*
      Comparador exactamente igual que
    */
    bool operator==(Fraccion const &);

    /*
      Comparador diferente que
    */
    bool operator!=(Fraccion const &);

  private:

    /*
      Atributos
      denominador y numerador de la fracción
    */
    int den,num;

    /*
      Calcula el mínimo común divisor entre dos números
      @param int a, int b, los números para calcular el mcd
      @return el mínimo común múltiplo
    */
    int mcd(int,int);

    /*
      Simplifica la fracción a sus valores enteros más pequeños, si tanto numerador
      como denominador tienen signos negativos, los elimina. Si solo uno de ellos
      lo tiene, lo mueve al numerador.
    */
    void simplificar();

};
