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

int calcularMinutos(int salida,int entrada){
    Hora sal=hora(salida);
    Hora ent=hora(entrada);
    return ((sal.horas*60+sal.minutos)-(ent.horas*60+ent.minutos));
}


void mostrarResultados(Map<int,Caja> cajas){
mapReset<int,Caja>(cajas);
while(mapHasNext<int,Caja>(cajas)){
Caja* caja=mapNextValue<int,Caja>(cajas);
cout<<replicate('*',20)<<endl;
cout<<"Caja numero: "<<caja->caja<<endl;
cout<<"Tiempo de espera promedio: "<<caja->esperaTotal/caja->clientes<<endl;
cout<<"Tiempo ocioso total: "<<caja->ocioTotal<<endl;
cout<<"Longitud maxima de caja: "<<caja->longMax<<endl;
}
}




int main(){
Map<int,Caja> cajas=map<int,Caja>();  

FILE* f=fopen("MOVIMIENTOS.dat","r+b");
Mov m=read<Mov>(f);

while(!feof(f)){

Caja newCaja=caja(m.caja);
Caja* caja=mapDiscover<int,Caja>(cajas,m.caja,newCaja);
if(m.mov=='E'){
if(queueIsEmpty<int>(caja->cola)){
caja->ocioTotal+=calcularMinutos(m.hora,caja->ultimaSalida);
}
queueEnqueue<int>(caja->cola,m.hora);
caja->clientes++;
if(queueSize<int>(caja->cola)>caja->longMax){caja->longMax=queueSize<int>(caja->cola);};
caja->ultimaEntrada=m.hora;
}

else{
int entradaEnCola=queueDequeue<int>(caja->cola);
caja->esperaTotal+=calcularMinutos(m.hora,entradaEnCola);
caja->ultimaSalida=m.hora;
}
m=read<Mov>(f);
}
mostrarResultados(cajas);




return 0;




}









#endif