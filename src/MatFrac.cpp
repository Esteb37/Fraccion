/*
  Proyecto de Programación Orientada a objetos
  @Autor: Esteban Padilla Cerdio
  @Fecha de creación: 07/01/2021
  @Última modificación: 10/01/2021
  @Archivo: MatFrac.cpp
*/

/*
  Clase para la representación de matrices de fracciones y sus herramientas
  para transformación y operación aritmética

  NOTA -> Esta versión únicamente trabaja con archivos CSV que siguen el
            siguiente formato de filas, columnas y fracciones

                                1/2,1/2,1/2
                                1/2,1/2,1/2
                                1/2,1/2,1/2

*/

#include "MatFrac.h"
#include <fstream>
#include <sstream>
#include <vector>
#include <iostream>
#include <string>


using namespace std;

/*
-------------------------Constructores-----------------------------------------
  Constructor default, genera una matriz vacía de dimensiones 0x0
*/
MatFrac::MatFrac():rows(0),cols(0){}

/*
  Constructor que genera una matriz de rxc con fracciones de valor 0/1
*/
MatFrac::MatFrac(int r, int c):rows(r),cols(c){

  //Por cada fila, generar un vector y agregarlo a la matriz
  for (int i = 0; i < r; i++){
    vector<Fraccion> row;

    //Por cada celda generar una fracción y agregarla a la fila
    for (int j = 0; j < c; j++){
      Fraccion f;
      row.push_back(f);
    }
    matrix.push_back(row);
  }
}

/*
  Constructor que genera una matriz de forma dinámica según los datos
  de un archivo CSV
*/
MatFrac::MatFrac(string ruta){
    readData(ruta);
}



/*
------------------------------Getters y Setters--------------------------------

  Obtiene la cantidad de filas de la matriz
  @return  número de filas
*/
int MatFrac::getRows() const{return rows;}

/*
  Obtiene la cantidad de columnas de la matriz
  @return número de columnas
*/
int MatFrac::getCols() const{return cols;}

/*
  Establece la cantidad de filas de la matriz
  @param int r - número de filas
*/
void MatFrac::setRows(int r){rows = r;}

/*
  Establece la cantidad de columnas de la matriz
  @param int c - número de columnas
*/
void MatFrac::setCols(int c){cols = c;}

/*
  Obtiene el objeto de Fracción en el índice especificado por coordenadas
  de la matriz
  @param int i - coordenada en y
         int j - coordenada en x
  @return el objeto de fracción en ese índice
*/
Fraccion MatFrac::getFrac(int i, int j) const{
  return matrix[i][j];
}

/*
  Establece un objeto de Fracción en el índice especificado por coordenadas
  @param  Fraccion f - la fracción a establecer
          int i - coordenada en y
          int j - coordenada en x
*/
void MatFrac::setFrac(Fraccion f, int i, int j){
  matrix[i][j] = f;
}



/*
----------------------------Herramientas de Clase------------------------------

  Imprime la matriz en la consola separada por filas y columnas
*/
void MatFrac::imprimir(){
  cout<<aString();
}

/*
  Extrae la información de un archivo CSV y genera una matriz con sus datos
  y dimensiones
  @param string ruta - la ruta al archivo CSV
*/
void MatFrac::readData(string ruta){

  //Obtener información del archivo origen
  ifstream file(ruta);

  //String donde se guardará el texto de cada fila del archivo
  string linestring;

  //Cantidad de filas que irá aumentando según el archivo
  rows = 0;

  //Separar el archivo por líneas y atravesar cada una de ellas
  while (getline(file, linestring))
  {

    //Transformar el texto de la línea actual a un stream
    stringstream line(linestring);

    //String donde se guardará el texto de cada celda de la fila
    string cellstring;

    //Vector que contendrá los objetos de fracciones de esta fila
    vector <Fraccion> row;

    //Cantidad de columnas que irá aumentando según el archivo
    cols = 0;

    //Separar el archivo por celdas según la coma y atravesar cada una de ellas
    while(getline(line, cellstring,','))
    {

      //Transformar el texto de la celda actual a un stream
      stringstream cell(cellstring);

      //String donde se guardará el texto de cada elemento de la fracción dentro
      //de la celda actual
      string n;

      //Variable de control para definir si se está leyendo el numerador o el
      //denominador
      bool isNum = true;

      int num,den;

      //Separar el texto de la celda en por la diagonal "/" y atravesar las
      //partes de la fracción
      while(getline(cell, n,'/'))
      {
        //Si no se ha leído el numerador, guardar el valor que se está leyendo
        //como el numerador
        if(isNum) num = stoi(n);

        //Si ya se leyó el numerador, guardarlo en el denominador
        else den = stoi(n);

        isNum = false;
      }

      //Crear fracción a partir del numerador y el denominador, y guardarla
      //en la línea actual
      Fraccion frac(num,den);
      row.push_back(frac);
      cols++;
    }

    //Guardar la línea actual en la matriz
    matrix.push_back(row);
    rows++;
  }
}

/*
  Transforma la matriz a formato CSV y escribe el resultado en un
  archivo en la ruta especificada
  @param string ruta - la ruta al archivo CSV de destino
*/
void MatFrac::exportar(string ruta){

  //Obtener string separada por comas y publicarla en el archivo
  ofstream out(ruta);
  out << aCsv();
  out.close();

}

/*
  Compara las dimensiones de la matriz con las dimensiones de otra para
  verificar si son iguales
  @param MatFrac otra - la segunda matriz para comparar
  @return si sus dimensiones son iguales
*/
bool MatFrac::comparar(MatFrac const &other){

  //Verificar que el número de filas y columnas sea igual
  if(getCols()!=other.getCols() || getRows()!=other.getRows()){
    cout<<"\nError: Las matrices deben ser de la misma dimension para poder realizar operaciones."<<endl;
    return false;
  }

  return true;

}

/*
  Transforma la matriz a una string con columnas separadas por espacios y
  filas separadas por newlines
  @return la string generada
*/
string MatFrac::aString(){

  return join(" ");
}

/*
  Transforma la matriz a una string con columnas separadas por comas y
  filas separadas por newlines
  @return la string generada
*/
string MatFrac::aCsv(){

  return join(",");
}

/*
  Transforma la matriz a una string con columnas separadas por el caracter
  especificado filas separadas por newlines
  @param string c - el caracter de separación
  @return la string generada
*/
string MatFrac::join(string c){
  string s = "";

  /*Atravesar la matriz celda por celda, concatenando su contenido a la string
  general, colocando el caracter seleccionado entre cada celda y newlines entre
  cada fila*/
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols-1; j++) {
      s+=matrix[i][j].aString()+c;
    }
    s+=matrix[i][cols-1].aString()+"\n";
  }
  return s;
}



/*
----------------------Herramientas de aritmética de fracciones------------------

  Suma esta matriz con otra, elemento por elemento
  @param MatFrac other - otra matriz
  @return una matriz equivalente a la suma de elementos
*/
MatFrac MatFrac::sum(MatFrac const &other){

  //Si las matrices son del mismo tamaño
  if(comparar(other)){

    //Generar una matriz de su mismo tamaño
    MatFrac resmat(rows,cols);

    /*Por cada elemento, realizar la operación, generando una nueva fracción
    que será colocada en la matriz resultante en su posición concordante*/
    for (int i = 0; i < rows; i++) {
      for (int j = 0; j < cols; j++) {
        Fraccion res;
        res = getFrac(i,j)+other.getFrac(i,j);
        resmat.setFrac(res,i,j);
      }
    }
    return resmat;
  }

  //Si las matrices no son del mismo tamaño, regresar la matriz original
  return *this;

}

/*
  Resta esta matriz con otra, elemento por elemento
  @param MatFrac other - otra matriz
  @return una matriz equivalente a la resta de elementos
*/
MatFrac MatFrac::sub(MatFrac const &other){

  //Si las matrices son del mismo tamaño
  if(comparar(other)){

    //Generar una matriz de su mismo tamaño
    MatFrac resmat(rows,cols);

    /*Por cada elemento, realizar la operación, generando una nueva fracción
    que será colocada en la matriz resultante en su posición concordante*/
    for (int i = 0; i < rows; i++) {
      for (int j = 0; j < cols; j++) {
        Fraccion res;
        res = getFrac(i,j)-other.getFrac(i,j);
        resmat.setFrac(res,i,j);
      }
    }
    return resmat;
  }

  //Si las matrices no son del mismo tamaño, regresar la matriz original
  return *this;
}

/*
  Multiplica esta matriz con otra, elemento por elemento
  @param MatFrac other - otra matriz
  @return una matriz equivalente a la multiplicación de elementos
*/
MatFrac MatFrac::mult(MatFrac const &other){

  //Si las matrices son del mismo tamaño
  if(comparar(other)){

    //Generar una matriz de su mismo tamaño
    MatFrac resmat(rows,cols);

    /*Por cada elemento, realizar la operación, generando una nueva fracción
    que será colocada en la matriz resultante en su posición concordante*/
    for (int i = 0; i < rows; i++) {
      for (int j = 0; j < cols; j++) {

        Fraccion res;
        res = getFrac(i,j)*other.getFrac(i,j);
        resmat.setFrac(res,i,j);
      }
    }

    return resmat;
  }

  //Si las matrices no son del mismo tamaño, regresar la matriz original
  return *this;

}

/*
  Divide esta matriz por otra, elemento por elemento
  @param MatFrac other - otra matriz
  @return una matriz equivalente a la división de elementos
*/
MatFrac MatFrac::div(MatFrac const &other){

  //Si las matrices son del mismo tamaño
  if(comparar(other)){

    //Generar una matriz de su mismo tamaño
    MatFrac resmat(rows,cols);

    /*Por cada elemento, realizar la operación, generando una nueva fracción
    que será colocada en la matriz resultante en su posición concordante*/
    for (int i = 0; i < rows; i++) {
      for (int j = 0; j < cols; j++) {

        Fraccion res;
        res = getFrac(i,j)/other.getFrac(i,j);
        resmat.setFrac(res,i,j);
      }
    }
    return resmat;
  }

  //Si las matrices no son del mismo tamaño, regresar la matriz original
  return *this;

}



/*
--------------------Sobrecarga de operadores aritméticos-----------------------

  Operador de adición
*/
MatFrac MatFrac::operator+(MatFrac const&other){
  return sum(other);
}

/*
  Operador de sustracción
*/
MatFrac MatFrac::operator-(MatFrac const&other){
  return sub(other);
}

/*
  Operador multiplicativo
*/
MatFrac MatFrac::operator*(MatFrac const&other){
  return mult(other);
}

/*
  Operador divisor
*/
MatFrac MatFrac::operator/(MatFrac const&other){
  return div(other);
}
