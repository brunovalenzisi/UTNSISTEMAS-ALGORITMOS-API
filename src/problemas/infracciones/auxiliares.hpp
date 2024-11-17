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





struct Acta
{
   int idInspector;
   char pat[10];
   int fecha; // aaaammdd
   int hora;  // hhmm
   int idInfraccion;
};

struct Infraccion
{
   int idInfraccion;
   char descr[100];
   double penalidad; // $
   int diasPromo;
   double dtoPromo; // ej: 0.20
};

struct RInfraccion
{
 Infraccion i;
 Array<int> contador=array<int>();
};


RInfraccion rInfraccion(Infraccion inf){
RInfraccion rI;
rI.i=inf;
};




struct Deuda{
double totalDeuda=0.0;
double totalDescuento=0.0;
double netoAPagar=0.0;
};

Deuda deuda(){
Deuda d;
return d;
};

struct Fecha{
   int dia;
   int mes;
   int anio;
};

Fecha fecha(int fInt){
Fecha f;
return f;
};





#endif