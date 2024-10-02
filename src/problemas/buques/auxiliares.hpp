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


struct Fecha{};
int fechaComparar(Fecha f1,Fecha f2){
int ret;
return ret;
}

struct Buque
{
   int idBuque;
   char nombre[50];
   int darsena;
   int grua; 
   int cantContainers;
   Fecha fecha; // llegada o salida
   int cteFlotacion;
   char oriODest[100];
};

struct Container
{
   int idContainer;
   int peso;
   int longitud; 
   int idBuque;
};

struct RBuque{
Buque b;
List<Container> containers;
bool estable;
int pesoTotal;
char actividad;//carga(C) / Descarga(D)
char status;//Arribo (A)/ partida(P)
};






#endif