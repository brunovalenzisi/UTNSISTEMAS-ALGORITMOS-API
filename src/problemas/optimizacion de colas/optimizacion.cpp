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
  Caja* seleccionada=NULL;
  while(mapHasNext(cajas)){
   Caja* c=mapNextValue<int,Caja>(cajas);
   Queue cola=c->cola; 
   if(queueSize(cola)==0){
    seleccionada=c;
   }else if(queueSize(cola)<queueSize(seleccionada->cola)){
    seleccionada=c;
   }
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
while(mapHasNext(supermercados)){
Supermercado* s=mapNextValue<int,Supermercado>(supermercados);
procesarMovimiento(m,s);


}  



}

return 0;

}









#endif