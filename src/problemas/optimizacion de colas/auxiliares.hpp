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

struct Mov 
{ 
   int idCli; 
   char mov; // 'E' o 'S' 
   char hora[4]; // hhmm 
};



struct Caja{
int idCaja;
Queue<int> cola;
int longMax=0;
int esperaTotal=0;
int ocioTot=0;
char ultimaSalida[4];
char ultimaEntrada[4];
};


struct Supermercado{
int idSupermercado;
int  cantCajas;
Map<int,Caja> cajas=map<int,Caja>();
Map<int,int> clientes=map<int,int>();
int ocioTotal=0;
int esperaTotal=0;
};

Caja caja(int id,char apertura[4]){
Caja c;
c.idCaja=id;
strcpy(c.ultimaSalida,apertura);
strcpy(c.ultimaEntrada,"");
return c;
}


Supermercado supermercado(int id,int n ){
Supermercado s;
s.idSupermercado=id;
s.cantCajas=n;
for(int i=0;i<n;i++){
Caja c= caja(i,"1000");
mapPut<int,Caja>(s.cajas,n,c);
}
return s;
}


#endif