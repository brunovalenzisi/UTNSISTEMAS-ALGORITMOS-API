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
   int hora; // hhmm 
};



struct Caja{
Queue<int> cola;
int longMax=0;
int esperaTotal=0;
int ocioTot=0;
int ultimaSalida=0;
};


struct Supermercado{
int  cantCajas;
Map<int,Caja> cajas;
Map<int,int> clientes;
int ocioTotal=0;
int esperaTotal=0;
};

Caja caja(){
Caja c;
return c;
}


Supermercado supermercado(int n){
Supermercado s;
s.cantCajas=n;
for(int i=0;i<n;i++){
Caja c= caja();
mapPut<int,Caja>(s.cajas,n,c);
}
return s;
}


#endif