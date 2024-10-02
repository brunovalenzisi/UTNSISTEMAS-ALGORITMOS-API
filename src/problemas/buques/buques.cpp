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

Array<Container> cargarContainers(){
Array<Container> containers;
FILE* f=fopen("CONTAINERS.dat","r+b");
Container c=read<Container>(f);
while(!feof(f)){
arrayAdd<Container>(containers,c);
c=read<Container>(f);
}
return containers;
};

void asignarContainers(RBuque &rB, Array<Container> &containers){

}

int calcularPesoTotal(RBuque rB){
int pesoTotal;
return pesoTotal;
}
char calcularStatus(Fecha f){
char status;
return status;
}

void mostrarEncabezado(Fecha f){


}
void mostrarBuque(RBuque rB){

}


// NO ESTA BIEN CONSIDERAR QUE ESTAN ORDENADO POR FECHA REHACER.

int main(){
Fecha fActual;
Array<Container> containers=cargarContainers();
FILE* f=fopen("BUQUES.dat","r+b");
Buque b=read<Buque>(f);
while(!feof(f)){
  fActual=b.fecha;
  mostrarEncabezado(fActual);
    RBuque rB;
  while(fechaComparar(b.fecha,fActual)==0){
    rB.b=b;
    asignarContainers(rB,containers);
    rB.pesoTotal=calcularPesoTotal(rB);
    rB.actividad=actividad(b.fecha);
    rB.status=calcularStatus(b.fecha);
    b=read<Buque>(f);
  }
  mostrarBuque(rB);
}
return 0;

}









#endif