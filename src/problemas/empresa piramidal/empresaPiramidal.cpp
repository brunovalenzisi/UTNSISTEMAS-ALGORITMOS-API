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

int cmpIdSocio(RSocio rS,int b){
return rS.s.idSocio-b;
}

int cmpRSocio(RSocio a, RSocio b){
return a.s.idSocio,b.s.idSocio;
}
List<RSocio> cargarSocios(){
List<RSocio> lst= list<RSocio>();
FILE*f =fopen("SOCIOS.dat","r+b");
Socio s=read<Socio>(f);
while(!feof(f)){
    RSocio rC=rSocio(s);
    listOrderedInsert<RSocio>(lst,rC,cmpRSocio);
    s=read<Socio>(f);
}
return lst; 
}


void procezarVenta(Venta v,List<RSocio> l){
RSocio rC=*listFind<RSocio,int>(l,v.idSocio,cmpIdSocio);
if(rC.s.idSocioRef!=-1){
    Venta vA=venta(rC.s.idSocioRef,v.fecha,v.importe*0.3*0.3);
    rC.liquidacionActual+=v.importe*0.3-v.importe*0.3*0.3;
    rC.s.liquidacionesAcumuladas+=v.importe*0.3-v.importe*0.3*0.3;
    rC.s.totalVentasAcumuladas+=v.importe;
    procezarVenta(vA,l);
}else{
rC.liquidacionActual+=v.importe*0.3;
rC.s.liquidacionesAcumuladas+=v.importe*0.3;
rC.s.totalVentasAcumuladas+=v.importe;
}
}


void mostrarSocios(List<RSocio> l){
listReset<RSocio>(l);
RSocio rC=*listNext<RSocio>(l);
while(listHasNext(l)){
cout<<"Socio Numero: "<<rC.s.idSocio<<endl;
cout<<"Nombre: "<<rC.s.nombre<<endl;
cout<<"Fecha de ingreso: "<<fechaMostrar(rC.s.fechaIngreso)<<endl;
cout<<"Liquidacion anterior: "<<rC.s.liquidacionAnterior<<endl;
cout<<"Liquidacion actual: "<<rC.liquidacionActual<<endl;
cout << "porcentaje de " << ((rC.liquidacionActual > rC.s.liquidacionAnterior) ? "aumento" : "decremento") << abs((rC.liquidacionActual-rC.s.liquidacionAnterior)/rC.s.liquidacionAnterior*100) << endl;
cout<<"Total Acumulado: "<<rC.s.liquidacionesAcumuladas<<endl;
}
}

int main(){
List<RSocio> rSocios=cargarSocios();
FILE* f=fopen("VENTAS.dat","r+b");
Venta v=read<Venta>(f);
while(!feof(f)){
    procezarVenta(v,rSocios);
    v=read<Venta>(f); 
}
mostrarSocios(rSocios);
return 0;

}









#endif