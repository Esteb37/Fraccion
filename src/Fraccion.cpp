/*
  Proyecto de Programación Orientada a objetos
  @Autor: Esteban Padilla Cerdio
  @Fecha de creación: 07/01/2021
  @Última modificación: 10/01/2021
  @Archivo: Fraccion.cpp
*/

/*
  Clase para la representación de fracciones como tipo de dato y su uso en
  operaciones aritméticas.
*/

#include "Fraccion.h"
#include <iostream>
#include <string>

#pragma once

using namespace std;

/*
-------------------------Constructores-----------------------------------------
  Constructor default, genera una fracción con valor 0/1
*/
Fraccion::Fraccion():num(0),den(1){};

/*
  Constructor que genera una fracción con numerador y denominador específico
  @param int num - numerador
         int den - denominador
*/
Fraccion::Fraccion(int n,int d){
  setNum(n);
  setDen(d);
  simplificar();
};


/*
------------------------------Getters y Setters--------------------------------

  Obtiene el denominador de la fracción
  @return denominador
*/
int Fraccion::getDen() const{return den;}

/*
  Obtiene el numerador de la fracción
  @return numerador
*/
int Fraccion::getNum() const{return num;}

/*
  Asigna un entero al denominador de la fracción
  @param int d - denominador
*/
void Fraccion::setDen(int d){den = d;}


/*
  Asigna un entero al numerador de la fracción
  @param int n - numerador
*/
void Fraccion::setNum(int n){num = n;}


/*
----------------------------Herramientas de Clase------------------------------

  Imprime la fracción en la consola
  @return la función en formato string
*/
string Fraccion::imprimir(){
  string s = aString();
  cout<<s;
  return s;
}

/*
  Transforma la fracción en una string
  @return la función en formato string
*/
string Fraccion::aString() const{
  string s = to_string(num)+"/"+to_string(den);
  return s;
}

/*
  Calcula el valor decimal de la fracción
  @return el valor decimal
*/
float Fraccion::aDecimal() const{
  return (float)num/(float)den;
}

/*
  Compara la fracción a otra según su valor en decimal
  @param Fraccion f - la fracción con la que se comparará
  @return 1 si es mayor, 0 si son iguales, -1 si la otra es mayor
*/
int Fraccion::comparar(Fraccion const&f){
  float d1 = aDecimal();
  float d2 = f.aDecimal();
  return d1>d2 ? 1 : d1<d2 ? -1 : 0;

}

/*
  Genera una copia de la fracción
  @return objeto de fraccion
*/
Fraccion Fraccion::copiar(){
  Fraccion copia(num,den);
  return copia;
}


/*
  Simplifica la fracción a sus valores enteros más pequeños, si tanto numerador
  como denominador tienen signos negativos, los elimina. Si solo uno de ellos
  lo tiene, lo mueve al numerador.
*/
void Fraccion::simplificar(){

  //Se obtiene el máximo común divisor de la fracción
  int divisor = mcd(num,den);

  //Se reducen los elementos de la fracción según el divisor
  num/=divisor;
  den/=divisor;

  //Si el divisor es negativo y el numerador positivo,
  //invertir los signos de ambos para asegurar que el
  //signo se quede en el numerador
  if(den<0&&num>0){
    num*=-1;
    den*=-1;
  }

}

/*
  Calcula el mínimo común divisor entre dos números
  @param int a, int b, los números para calcular el mcd
  @return el mínimo común múltiplo
*/
int Fraccion::mcd(int num,int den){

  //Utiliza el algoritmo de Euclides de forma recursiva
    if (den != 0)
      return mcd(den, num % den);
    else
      return num;
}



/*
----------------------Herramientas de aritmética de fracciones------------------

  Suma esta fracción con otra
  @param const f - otra fracción
  @return una fracción equivalente a la suma
*/
Fraccion Fraccion::sum(Fraccion const &f){
  //Se obtiene un denominador en común
  int mult = den*f.getDen();

  //Se transforman los numeradores segun el denominador común
  int sum = mult/den*num+mult/f.getDen()*f.getNum();

  Fraccion res(sum,mult);
  return res;
}

/*
  Resta esta fracción con otra
  @param const f - otra fracción
  @return una fracción equivalente a la resta
*/
Fraccion Fraccion::sub(Fraccion const &f){
  //Se obtiene un denominador en común
  int mult = den*f.getDen();

  //Se transforman los numeradores segun el denominador común
  int sum = mult/den*num-mult/f.getDen()*f.getNum();


  Fraccion res(sum,mult);
  return res;
}

/*
  Divide esta fracción por otra
  @param const f - otra fracción
  @return una fracción equivalente a la división
*/
Fraccion Fraccion::div(Fraccion const &f){

  //Multiplicación cruzada
  int n = num*f.getDen();
  int d = den*f.getNum();

  Fraccion res(n,d);
  return res;
}

/*
  Multiplica esta fracción con otra
  @param const f - otra fracción
  @return una fracción equivalente a la multiplicación
*/
Fraccion Fraccion::mult(Fraccion const &f){

  //Multiplicación directa
  int n = num*f.getNum();
  int d = den*f.getDen();

  Fraccion res(n,d);
  return res;
}



/*
--------------------Sobrecarga de operadores aritméticos-----------------------

  Operador multiplicativo
*/
Fraccion Fraccion::operator*(Fraccion const &f){
  return mult(f);
}
/*
  Operador divisor
*/
Fraccion Fraccion::operator/(Fraccion const &f){
  return div(f);
}

/*
  Operador de adición
*/
Fraccion Fraccion::operator+(Fraccion const &f){
  return sum(f);
}

/*
  Operador de sustracción
*/
Fraccion Fraccion::operator-(Fraccion const &f){
  return sub(f);
}



/*
--------------------Sobrecarga de operadores de comparación---------------------

  Comparador mayor que
*/
bool Fraccion::operator>(Fraccion const &f){
  return aDecimal()>f.aDecimal();
}

/*
  Comparador menor que
*/
bool Fraccion::operator<(Fraccion const &f){
  return aDecimal()<f.aDecimal();
}

/*
  Comparador mayor o igual que
*/
bool Fraccion::operator>=(Fraccion const &f){
  return aDecimal()>=f.aDecimal();
}

/*
  Comparador menor o igual que
*/
bool Fraccion::operator<=(Fraccion const &f){
  return aDecimal()<=f.aDecimal();
}

/*
  Comparador exactamente igual que
*/
bool Fraccion::operator==(Fraccion const &f){
  return aDecimal()==f.aDecimal();
}

/*
  Comparador diferente que
*/
bool Fraccion::operator!=(Fraccion const &f){
  return aDecimal()!=f.aDecimal();
}
