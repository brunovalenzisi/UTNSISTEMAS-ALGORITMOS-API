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


int calcularTiempoPromedio(int a, int b){
  return-a/b;
};


Caja procesarCaja(int caja, int hora){


  return {};
};


    void descubrirCaja(Mov m, Map<int,Caja> &map){
      int idCaja=m.caja;
      if(!mapContains(map,idCaja)){
        
        mapPut(map,idCaja,c);
      }
    }
void procesarPtoUno(Mov m, Map<int,Caja> map){
  Caja* c=mapGet<int,Caja>(map,m.caja);
  if(m.mov=='s'){
    c->esperaTotal+=m.hora-c->ultimaSalida;
    c->ultimaSalida=m.hora;
  }
}

int tiepoDeEsperaPromedio;

int main (){

FILE* f=fopen("MOVIMIENTOS.dat","r+b");
Mov m=read<Mov>(f);
  while(!feof(f)) {
Caja c = procesarCaja(m.caja, m.hora);
Map<int,Caja> map;  
descubrirCaja(m,map);
  procesarPtoUno(m,map);
  procesarPtoDos(m,map);
  procesarPtoTres(m,map);

}




return 0;





}


#endif