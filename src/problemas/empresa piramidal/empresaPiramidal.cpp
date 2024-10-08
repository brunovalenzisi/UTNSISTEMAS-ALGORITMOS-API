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


void procezarVenta(Venta v,List<RSocio> l){
RSocio rC=*listFind<RSocio,int>(l,v.idSocio,cmpIdSocio);
if(rC.s.idSocioRef!=-1){
    Venta vA=venta(rC.s.idSocioRef,v.fecha,v.importe*0.3*0.3);
    rC.liquidacionActual+=v.importe*0.3-v.importe*0.3*0.3;
    procezarVenta(vA,l);
}else{
rC.liquidacionActual+=v.importe*0.3;
}
}


void mostrarSocios(List<RSocio> l){



}

int main(){
List<RSocio> rSocios=list<RSocio>();
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