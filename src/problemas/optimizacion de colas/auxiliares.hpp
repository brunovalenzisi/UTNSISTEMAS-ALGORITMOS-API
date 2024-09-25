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
using namespace std;

struct Mov 
{ 
   int idCli; 
   char mov; // 'E' o 'S' 
   int hora; // hhmm 
};



struct Caja{
Node<int>* cola;
int longMax;
int esperaTotal;
int ocioTot;
int ultimaSalida;
};


struct Supermercado{
int  cantCajas;
Map<int,Caja> cajas;
Map<int,int> clientes;
int ocioTotal;
int esperaTotal;
};

#endif