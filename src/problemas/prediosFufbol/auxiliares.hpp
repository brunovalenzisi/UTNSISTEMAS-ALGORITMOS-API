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

struct Predio
{
   int idPredio;
   char nombre[100];
   char direccion[100];
   int cantCanchas;
   int idBarrio;
};

struct Reserva
{
   int idReserva; 
   int idCliente; 
   int idPredio; 
   int diaMes; // 1 a 31
   char turno; // 'M,'T','N'
   char celContacto[50]; 
};
struct Cancha
{
   int idPredio; 
   int nroCancha;
   double precio;
   int flgCubierta;
   char obs[200];
};

struct RCancha{
Cancha c;
Array<int> turnosManiana=array<int>();
Array<int> turnosTarde=array<int>();
Array<int> turnosNoche=array<int>();
};


struct RPredio{
    Predio p;
    Map<int,Cancha> canchas=map<int,Cancha>();
    Array<Map<int,RCancha>> calendario=array<Map<int,RCancha>>();
};



RPredio rPredio(Predio p){
RPredio rP;
rP.p=p;
return rP;
};

RCancha rCancha(Cancha c){
   RCancha rC;
   rC.c=c;
   return rC;
};




#endif