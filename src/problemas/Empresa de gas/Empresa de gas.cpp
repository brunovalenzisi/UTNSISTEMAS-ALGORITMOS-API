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


Cliente buscarCliente(FILE* f,int pos){
Cliente c;
return c;
}

Consumo calcularConsumo(int lecturaAnterior, Medicion m){
Consumo c;
c.bimestre=m.bimestre;
c.m3Consumidos=m.lecturaActual-lecturaAnterior;
return c;
}

int actualizarConsumos(Cliente c, Consumo cons){
  Array<Consumo> consumos=decodeConsumo(c.consumos);
  int ret= calcularConsumoAnual(consumos,cons.m3Consumidos);
  arrayRemove<Consumo>(consumos,0);
  arrayAdd<Consumo>(consumos,cons);

}

    


int main(){
FILE* fClientes=fopen("CLIENTES.dat","r+b"); 
Map<int,List<Cliente>> categorias;
FILE* f=fopen("MEDICIONES.dat","r+b");
Medicion m=read<Medicion>(f);
while(!feof(f)){
int posCliente=busquedaBinariaCliente(fClientes,m.idCli);
Cliente c=buscarCliente(fClientes,posCliente);
Consumo cons=calcularConsumo(c.lecturaAnterior,m);
actualizarConsumos(c,cons);






}





return 0;

}









#endif