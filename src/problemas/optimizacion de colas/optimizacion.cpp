#ifndef _MAIN
#define _MAIN

#include <iostream>
#include "../../biblioteca/funciones/strings.hpp"
#include "../../biblioteca/funciones/tokens.hpp"
#include "../../biblioteca/funciones/files.hpp"
#include "../../biblioteca/tads/parte2/Array.hpp"
#include "../../biblioteca/tads/parte2/Map.hpp"
#include "../../biblioteca/tads/parte2/List.hpp"
#include "../../biblioteca/tads/parte2/Stack.hpp"
#include "../../biblioteca/tads/parte2/Queue.hpp"
#include "../../biblioteca/tads/parte1/Coll.hpp"
#include "../../biblioteca/tads/parte1/MultidimColl.hpp"
#include "./auxiliares.hpp"
using namespace std;


Caja* seleccionarCaja(Supermercado* s){
  Map<int,Caja> cajas=s->cajas;
   Caja* c=mapNextValue<int,Caja>(cajas);
   Caja* seleccionada=c;
  while(mapHasNext(cajas)){
   Queue<int> cola=c->cola; 
   if(queueSize(cola)==0){
    seleccionada=c;
    break;
   }else if(queueSize(cola)<queueSize(seleccionada->cola)){
    seleccionada=c;
   }
   c=mapNextValue<int,Caja>(cajas);
  }
  return seleccionada;
}


void procesarMovimiento(Mov m,Supermercado* s){
if(m.mov=='E'){
Caja* c=seleccionarCaja(s);

}
else{


}

}

    


int main(){
Map<int,Supermercado> supermercados;

Array<int> cantidadCajas;
arrayAdd<int>(cantidadCajas,3);
arrayAdd<int>(cantidadCajas,4);
arrayAdd<int>(cantidadCajas,7);
arrayAdd<int>(cantidadCajas,8);
arrayAdd<int>(cantidadCajas,10);

for (int i=0; i<arraySize<int>(cantidadCajas);i++){
int n =*arrayGet<int>(cantidadCajas,i);
Supermercado nuevoSup=supermercado(n);
mapPut<int,Supermercado>(supermercados,n,nuevoSup);
}

FILE* f = fopen("Mov.dat","r+b");
Mov m=read<Mov>(f);
while(!feof(f)){
Supermercado* s=mapNextValue<int,Supermercado>(supermercados);
while(mapHasNext(supermercados)){
procesarMovimiento(m,s);


s=mapNextValue<int,Supermercado>(supermercados);
}  



}

return 0;

}









#endif