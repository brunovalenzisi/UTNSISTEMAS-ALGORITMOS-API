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




Map<int,RInfraccion> cargarInfracciones(){
Map<int,RInfraccion> ret=map<int,RInfraccion>();

FILE* f=fopen("INFRACCIONES.dat","r+b");
Infraccion i=read<Infraccion>(f);
while(!feof(f)){
RInfraccion rI=rInfraccion(i);
mapPut<int,RInfraccion>(ret,i.idInfraccion,rI);
i=read<Infraccion>(f);
};
return ret;
};

void actualizarDeuda(Acta a,Map<int,RInfraccion>rInfracciones, Deuda* d){
RInfraccion  rI=*mapGet<int,RInfraccion>(rInfracciones,a.idInfraccion);
double penalidad=rI.i.penalidad;
double dto=rI.i.dtoPromo;
d->totalDeuda+=penalidad;
d->totalDescuento+=penalidad*dto;
d->netoAPagar+=penalidad*(1-dto);

}

void procesarInfraccion(Acta a, Map<string,Deuda> deudas,Map<int,RInfraccion> rInfracciones){
string patente=string(a.pat);
Fecha f=fecha(a.fecha);
RInfraccion * rI = mapGet<int,RInfraccion>(rInfracciones,a.idInfraccion);
if(*arrayGet<int>(rI->contador,f.dia)!=NULL){
*arrayGet<int>(rI->contador,f.dia)+=1;
}else{
arrayInsert<int>(rI->contador,1,f.dia);
};
  Deuda d=deuda();
  actualizarDeuda(a,rInfracciones, mapDiscover<string,Deuda>(deudas,patente,d));
};

void mostrarResultados(Map<string,Deuda> deudas,Map<int,RInfraccion> rInfracciones){
cout<<replicate('*',20)<<endl;
cout<<"Infracciones por dia"<<endl;
mapReset<int,RInfraccion>(rInfracciones);
while(mapHasNext<int,RInfraccion>(rInfracciones)){



}




};


int main(){

  Map<string, Deuda> deudas = map<string, Deuda>();
  Map<int,RInfraccion> rInfracciones=cargarInfracciones();

  FILE* f=fopen("ACTAS.dat","r+b");
  Acta a=read<Acta>(f);
  while(!feof(f)){
    procesarInfraccion(a,deudas,rInfracciones);
    a=read<Acta>(f);

  }
  mostrarResultados(deudas,rInfracciones);







return 0;




}









#endif