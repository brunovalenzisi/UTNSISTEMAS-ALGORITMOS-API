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
   string hora; // hhmm 
};



struct Caja{
int idCaja;
Queue<int> cola;
int longMax=0;
int esperaTotal=0;
int ocioTot=0;
string ultimaSalida="1000";
string ultimaEntrada="";
};


struct Supermercado{
int  cantCajas;
Map<int,Caja> cajas;
Map<int,int> clientes;
int ocioTotal=0;
int esperaTotal=0;
};

Caja caja(int id){
Caja c;
c.idCaja=id;
return c;
}


Supermercado supermercado(int n){
Supermercado s;
s.cantCajas=n;
for(int i=0;i<n;i++){
Caja c= caja(i);
mapPut<int,Caja>(s.cajas,n,c);
}
return s;
}


#endif