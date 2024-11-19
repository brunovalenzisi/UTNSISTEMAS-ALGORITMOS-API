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
   int caja;
   char mov;  // 'E' => Entra, 'S' => Sale
   int hora;  // hhmm
};
struct Hora{
int horas;
int minutos;
};
Hora hora(int hora){
Hora h;
return h;
}

struct Caja{
    int caja;
    Queue<int> cola=queue<int>();
    int esperaTotal=0;
    int ocioTotal=0;
    int longMax=0;
    int clientes=0;
    int ultimaSalida=0700;
    int ultimaEntrada;
};
Caja caja(int id){
Caja c;
c.caja=id;
}

#endif