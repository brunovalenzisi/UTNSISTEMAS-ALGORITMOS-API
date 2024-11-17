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



int toMin(const char hhmm[4]) {
    int hours = (hhmm[0] - '0') * 10 + (hhmm[1] - '0');
    int minutes = (hhmm[2] - '0') * 10 + (hhmm[3] - '0');
    return (hours * 60) + minutes;
}
int calcularTiempo(char salida[4],char entrada[4]){
 return toMin(salida)-toMin(entrada);  
}

void actualizarLongMax(Caja* c){
if(queueSize<int>(c->cola)>c->longMax){
  c->longMax=queueSize<int>(c->cola);
}
}
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

void mostrarResultados(Map<int,Supermercado> supermercados){
mapReset<int,Supermercado>(supermercados);
Supermercado* s=mapNextValue<int,Supermercado>(supermercados);
while(mapHasNext<int,Supermercado>(supermercados)){
  cout<<"Supermercado con "<<s->cantCajas<<" cajas"<<endl;
  cout<<"Ocio total: "<<s->ocioTotal<<endl;
  cout<<"Espera total: "<<s->esperaTotal<<endl;
  s=mapNextValue<int,Supermercado>(supermercados);

}
}


void procesarMovimiento(Mov m,Supermercado* s){
if(m.mov=='E'){
Caja* c=seleccionarCaja(s);
queueEnqueue(c->cola,m.idCli);
mapPut<int,int>(s->clientes,m.idCli,c->idCaja);
actualizarLongMax(c);
strcpy(c->ultimaEntrada,m.hora);
if(queueSize(c->cola)==0){
  c->ocioTot+=calcularTiempo(m.hora,c->ultimaSalida);
  s->ocioTotal+=calcularTiempo(m.hora,c->ultimaSalida);
}
}
else if(m.mov=='S'){
int* idCaja=mapGet<int,int>(s->clientes,m.idCli);
Caja* c= mapGet<int,Caja>(s->cajas,*idCaja);
queueDequeue<int>(c->cola);
c->esperaTotal+=calcularTiempo(m.hora,c->ultimaEntrada);
s->esperaTotal+=calcularTiempo(m.hora,c->ultimaEntrada);
strcpy(c->ultimaSalida,m.hora);
}

}


int main(){
Map<int,Supermercado> supermercados=map<int,Supermercado>();

Array<int> cantidadCajas = array<int>();
arrayAdd<int>(cantidadCajas,3);
arrayAdd<int>(cantidadCajas,4);
arrayAdd<int>(cantidadCajas,7);
arrayAdd<int>(cantidadCajas,8);
arrayAdd<int>(cantidadCajas,10);

for (int i=0; i<arraySize<int>(cantidadCajas);i++){
int n =*arrayGet<int>(cantidadCajas,i);
Supermercado nuevoSup=supermercado(i,n);
mapPut<int,Supermercado>(supermercados,n,nuevoSup);
cout<<nuevoSup.idSupermercado<<endl;
}

FILE* f = fopen("MOVIMIENTOS.dat","r+b");
Mov m=read<Mov>(f);
while(!feof(f)){
mapReset<int,Supermercado>(supermercados);
Supermercado* s=mapNextValue<int,Supermercado>(supermercados);
while(mapHasNext(supermercados)){
procesarMovimiento(m,s);
s=mapNextValue<int,Supermercado>(supermercados);
}
cout<<m.hora<<endl;
m=read<Mov>(f);
}
cout<<"termino"<<endl;
//mostrarResultados(supermercados);

return 0;

}









#endif