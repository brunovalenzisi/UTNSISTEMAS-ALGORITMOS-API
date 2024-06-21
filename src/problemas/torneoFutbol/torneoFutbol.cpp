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
#include "../auxiliares.hpp"
using namespace std;

    
    Coll<Estadio> colEstadios=Coll<Estadio>();
    Coll<Equipo> equiposCargar(){
        Coll<Equipo> col;
        FILE* f = fopen("EQUIPOS.dat","r+b");
        Equipo e = read<Equipo>(f);
        while(!feof(f)){
          collAdd(col,e,equipoToString);
          e=read<Equipo>(f);
        }
        fclose(f);
        return col;
    };
    int cmpEquipoId( Equipo eq,int idEq){
      return eq.idEq-idEq;
    }
void actualizarPuntos(int id,int ptos,Coll<Equipo>& coll){
  int pos=collFind<Equipo,int>(coll,id,cmpEquipoId,equipoFromString);
  Equipo equipoActual = collGetAt(coll,pos,equipoFromString);
  equipoActual.puntos+=ptos;
  collSetAt(coll,equipoActual,pos,equipoToString);
}

    void procesarPto1(Resultado r,Coll<Equipo>& coll){
      int eq1Ptos= r.codRes>0?3:r.codRes<0?0:1;
      int eq2Ptos= r.codRes>0?0:r.codRes<0?3:1;
      actualizarPuntos(r.idEq1,eq1Ptos,coll);
      actualizarPuntos(r.idEq2,eq2Ptos,coll);
    }

  int cmpPtosEquipo(Equipo e1,Equipo e2){
    return e2.puntos-e1.puntos;
  }  
void mostrarResultado1(Coll<Equipo> coll){
  collReset(coll);
  cout<<cpad("TABLA DE RESULTADOS",30,'-')<<endl;
  collSort<Equipo>(coll,cmpPtosEquipo,equipoFromString,equipoToString);
  Equipo e;

 while(collHasNext(coll)){
  e=collNext<Equipo>(coll,equipoFromString);
  cout<<equipoToDebug(e)<<endl;
  }
  cout<<cpad("FIN",30,'-')<<endl;
  
};
int cmpEstadio(Estadio e1,string e2){
  return cmpString(e1.nombre,e2);
}

void procesarPto2(Resultado r,Coll<Estadio>& collEst){
  string sEstadio=string(r.estadio);
  int pos=collFind<Estadio,string>(collEst,sEstadio,cmpEstadio,estadioFromString);
    if(pos>=0){
    Estadio estadio=collGetAt<Estadio>(collEst,pos,estadioFromString);
    estadio.nJugados++;
    if(r.codRes==0){estadio.nEmpatados++;} 
    collSetAt<Estadio>(collEst,estadio,pos,estadioToString);
  }
  else{
    Estadio nuevoEstadio = estadio(string(r.estadio), 1, r.codRes == 0 ? 1 : 0);
    collAdd<Estadio>(collEst,nuevoEstadio,estadioToString);
    
  }
  
};

void mostrarResultado2(Coll<Estadio> coll){
  cout<<cpad("TABLA DE ESTADIOS",30,'-')<<endl;
 while(collHasNext(coll)){
Estadio  e=collNext<Estadio>(coll,estadioFromString);
  cout<<estadioToDebug(e)<<endl;
  
  }
  cout<<cpad("FIN",30,'-')<<endl;
  
};

void actualizarArchivo(FILE* f,Coll<Equipo>& coll){
collReset(coll);
Equipo equipo=collNext<Equipo>(coll,equipoFromString);
while (collHasNext(coll)){
equipo=collNext<Equipo>(coll,equipoFromString);
write<Equipo>(f,equipo);
}
fclose(f);
}
void chequearNuevoArchivo(FILE* f){
cout<<"check"<<endl;
  Equipo equipo=read<Equipo>(f);
    cout<<equipoToDebug(equipo)<<endl;
  while (feof(f)){
    equipo=read<Equipo>(f);
    cout<<equipoToDebug(equipo)<<endl;
  }
}

int main(){
FILE * f = fopen("RESULTADOS.dat","r+b");   
FILE*fAct=fopen("EQUIPOSACT.dat","w+b");
Coll<Equipo> collEquipos = equiposCargar();
Coll<Estadio> collEstadios= coll<Estadio>();
Resultado r = read<Resultado>(f);

while(!feof(f)){
procesarPto1(r,collEquipos);
procesarPto2(r,collEstadios);
r = read<Resultado>(f);
}

actualizarArchivo(fAct,collEquipos);
mostrarResultado1(collEquipos);
mostrarResultado2(collEstadios);
//chequearNuevoArchivo(fAct);
fclose(f);
return 0;
}

#endif