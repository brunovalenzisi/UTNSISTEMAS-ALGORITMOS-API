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
Coll<RCiudad> ciudadSubir(){
        Coll<RCiudad> col;
        FILE* f = fopen("CIUDADES.dat","r+b");
        Ciudad c = read<Ciudad>(f);
        while(!feof(f)){
         RCiudad rC=rCiudad(c,0);
          collAdd<RCiudad>(col,rC,rCiudadToString);
          c=read<Ciudad>(f);
        }
        fclose(f);
        return col;
    };


Coll<RVuelo> vueloSubir(){ 
Coll<RVuelo> col;
FILE* f = fopen("VUELOS.dat","r+b");
Vuelo vuelo = read<Vuelo>(f);
while(!feof(f)){
RVuelo rV= rVuelo(vuelo,0);
collAdd<RVuelo>(col,rV,rVueloToString);
vuelo=read<Vuelo>(f);
}
fclose(f);
return col;
}
int cmpVuelo(RVuelo vuelo,int destino){
   return vuelo.v.idVue-destino;

}

int cmpDestino(RCiudad ciudad,int destino){
return ciudad.c.idCiu-destino;

}
void procesarPunto1(Reserva r,Coll<RVuelo> collVue,Coll<RCiudad>& collCiu)
{     
     int vPos = collFind<RVuelo,int>(collVue,r.idVue,cmpVuelo,rVueloFromString);
      RVuelo vuelo = collGetAt<RVuelo>(collVue,vPos,rVueloFromString);
      int cPos = collFind<RCiudad,int>(collCiu,vuelo.v.idDes,cmpDestino,rCiudadFromString);
      RCiudad ciudad = collGetAt<RCiudad>(collCiu,cPos,rCiudadFromString);
      ciudad.cant++;
      collSetAt<RCiudad>(collCiu,ciudad,cPos,rCiudadToString);
}

void procesarPunto2(Reserva r,Coll<RVuelo>& cVue)
{
int vPos = collFind<RVuelo,int>(cVue,r.idVue,cmpVuelo,rVueloFromString);
RVuelo vuelo = collGetAt<RVuelo>(cVue,vPos,rVueloFromString);
if(vuelo.v.cap>=r.cant){
   vuelo.v.cap-=r.cant;
}
else{vuelo.cant+=r.cant;
};
collSetAt<RVuelo>(cVue,vuelo,vPos,rVueloToString);

}

int cmpCliente(RCliente cliente,int idCliente){
return cliente.idCli-idCliente;
}
void procesarPunto3(Reserva r,Coll<RVuelo> cVue,Coll<RCiudad> cCiu,Coll<RCliente>& cCli)
{
      int vPos = collFind<RVuelo,int>(cVue,r.idVue,cmpVuelo,rVueloFromString);
      RVuelo vuelo = collGetAt<RVuelo>(cVue,vPos,rVueloFromString);
     if(vuelo.v.cap>=r.cant){
      int cOriPos = collFind<RCiudad,int>(cCiu,vuelo.v.idOri,cmpDestino,rCiudadFromString);
      int cDesPos = collFind<RCiudad,int>(cCiu,vuelo.v.idDes,cmpDestino,rCiudadFromString);
      RCiudad ciudadOri = collGetAt<RCiudad>(cCiu,cOriPos,rCiudadFromString);
      RCiudad ciudadDes = collGetAt<RCiudad>(cCiu,cDesPos,rCiudadFromString);
      int posCliente=collFind<RCliente,int>(cCli,r.idCli,cmpCliente,rClienteFromString);
      RCliente cliente = collGetAt<RCliente>(cCli,posCliente,rClienteFromString);
      int puntos=abs(ciudadOri.c.millas-ciudadDes.c.millas)*r.cant;
      cliente.acum+=puntos;
      collSetAt<RCliente>(cCli,cliente,posCliente,rClienteToString);
      }

}


void descubrirCliente(Reserva r,Coll<RCliente> & coll ){
   int posCliente=collFind<RCliente>(coll,r.idCli,cmpCliente,rClienteFromString);
   if(posCliente<0){
      RCliente nuevoCliente=rCliente(r.idCli,0);
      collAdd<RCliente>(coll,nuevoCliente,rClienteToString);
   }

}

void resultadoPunto1(Coll<RCiudad> cCiu)
{
  cout<<cpad("CIUDADES PREFERIDAS",30,'-')<<endl;
 while(collHasNext(cCiu)){
 RCiudad  c=collNext<RCiudad>(cCiu,rCiudadFromString);
  cout<<rCiudadToDebug(c)<<endl;
  }
  cout<<cpad("FIN",30,'-')<<endl;
}

void resultadoPunto2(Coll<RVuelo> cVue)
{
 cout<<cpad("PLAZAS RECHAZADAS",30,'-')<<endl;
 while(collHasNext(cVue)){
 RVuelo  v=collNext<RVuelo>(cVue,rVueloFromString);
 bool lleno=v.v.cap==0;
  cout<<rVueloToDebug(v)<<" Full: "<<lleno<<endl;
  }
  cout<<cpad("FIN",30,'-')<<endl;
}

void resultadoPunto3(Coll<RCliente> cCli)
{
     cout<<cpad("MILLAS",30,'-')<<endl;
 while(collHasNext(cCli)){
 RCliente  c=collNext<RCliente>(cCli,rClienteFromString);
  cout<<rClienteToDebug(c)<<endl;
  }
  cout<<cpad("FIN",30,'-')<<endl;
}


int main()
{
   Coll<RCiudad> cCiu = ciudadSubir(); // 7
   Coll<RVuelo> cVue = vueloSubir();
   Coll<RCliente> cCli = coll<RCliente>();
   FILE* f = fopen("RESERVAS.dat","r+b");
   Reserva r = read<Reserva>(f);
   while( !feof(f) )
   {  
      descubrirCliente(r,cCli);
      procesarPunto1(r,cVue,cCiu);      // 1
      procesarPunto3(r,cVue,cCiu,cCli); // 3
      procesarPunto2(r,cVue);           // 2

      r = read<Reserva>(f);
   }

   resultadoPunto1(cCiu); // 5
   resultadoPunto2(cVue); // 4
   resultadoPunto3(cCli); // 6


   fclose(f);
   return 0;
}

#endif