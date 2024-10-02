#ifndef _MAINHPP
#define _MAINHPP
#include <iostream>
#include <iostream>
#include <sstream>
#include <string>
#include <string.h>
#include <stdlib.h>
#include "../../biblioteca/funciones/strings.hpp"
#include "../../biblioteca/funciones/tokens.hpp"
#include "../../biblioteca/tads/parte1/Coll.hpp"
#include "../../biblioteca/tads/parte2/Queue.hpp"
#include "../../biblioteca/tads/parte2/List.hpp"
#include "../../biblioteca/tads/parte2/Stack.hpp"
using namespace std;

struct Categoria
{
   char idCat[3];
   char descrip[50];
   int m3Desde;  // mts cubicos
   int m3Hasta;  // mts cubicos 
   double valorM3;
};

struct Cliente
{
   int idCli; // ordenado
   char nombre[100];
   char direccion[200];
   char idCatAnt[3]; 
   int lecturaAnterior;
   unsigned char consumos[36] ;
};

struct Fecha{

};


struct Medicion
{
   int idCli;
   int lecturaActual;
   int bimestre;
};

struct Consumo
{
   int bimestre; // mes y anio
   int m3Consumidos;
};

unsigned char* encodeConsumo(Array<Consumo> arr){

};

Array<Consumo> decodeConsumo(unsigned char acumulado[]){

};

int calcularConsumoAnual(Array<Consumo> arr,int actual){

};



int busquedaBinariaCliente(FILE* f,int idCli)
{
   // idx del primer registro
   int i=0;

   // idx del ultimo registro
   int j=fileSize<Cliente>(f)-1;

   // idx promedio (a calcular)
   int k;

   bool encontrado = false;
   while( i<=j && !encontrado)
   {
      // idx posicion promedio
      k=(i+j)/2;

      // leo el registro en la posicion promedio
      seek<Cliente>(f,k);
      Cliente c = read<Cliente>(f);

      if( idCli>c.idCli )
      {
         i = k+1;
      }
      else
      {
         if( idCli<c.idCli )
         {
            j = k-1;
         }
         else
         {
            encontrado = true;
         }
      }
   }

   return encontrado?k:-1;
}



#endif