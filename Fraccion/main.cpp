/*
  Proyecto de Programación Orientada a objetos
  @Autor: Esteban Padilla Cerdio
  @Fecha de creación: 07/01/2021
  @Última modificación: 10/01/2021
  @Archivo: main.cpp
*/

/*

  NOTA -> Esta versión únicamente trabaja con archivos CSV que siguen el
            siguiente formato de filas, columnas y fracciones

                                1/2,1/2,1/2
                                1/2,1/2,1/2
                                1/2,1/2,1/2

*/


#include "Fraccion.h"
#include "Fraccion.cpp"

#include "MatFrac.h"
#include "MatFrac.cpp"

#include <iostream>

using namespace std;



int main() {

  //Rutas de origen y destino para las matrices
  string rm1,rm2,rsum,rsub,rmult,rdiv;

  //Obtención de rutas de origen
  cout<<"------------Actividad Diagnostico-----------\n";
  cout<<"\nEscriba la ruta al archivo con la primera matriz: ";
  cin>>rm1;
  cout<<"\nEscriba la ruta al archivo con la primera matriz: ";
  cin>>rm2;

  //Creación de matrices a partir de archivos
  MatFrac matrix1(rm1);
  MatFrac matrix2(rm2);

  //Verificar que las matrices sean del mismo tamaño
  if(!matrix1.comparar(matrix2)){
    return 0;
  }


  //Impresión de las matrices de origen
  cout<<"\n---Matriz 1---\n\n";
  matrix1.imprimir();
  cout<<endl;

  cout<<"---Matriz 2---\n\n";
  matrix2.imprimir();
  cout<<endl;

  //Obtención de rutas de destino para las matrices resultantes
  cout<<"\nEscriba la ruta para generar el archivo con la SUMA: ";
  cin>>rsum;
  cout<<"\nEscriba la ruta para generar el archivo con la RESTA: ";
  cin>>rsub;
  cout<<"\nEscriba la ruta para generar el archivo con la MULTIPLICACION: ";
  cin>>rmult;
  cout<<"\nEscriba la ruta para generar el archivo con la DIVISION: ";
  cin>>rdiv;

  //Matrices resultantes
  MatFrac sum,sub,mult,div;

  //Realizar operaciones y exportar los resultados
  cout<<"\n---Suma---\n\n";
  sum = matrix1+matrix2;
  sum.imprimir();
  sum.exportar(rsum);
  cout<<endl;

  cout<<"---Resta---\n\n";
  sub = matrix1-matrix2;
  sub.imprimir();
  sub.exportar(rsub);
  cout<<endl;

  cout<<"---Mult---\n\n";
  mult = matrix1*matrix2;
  mult.imprimir();
  div.exportar(rdiv);
  cout<<endl;

  cout<<"---Div---\n\n";
  div = matrix1/matrix2;
  mult.exportar(rmult);
  div.imprimir();

  return 0;


}
