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


Map<int,RPredio> generarRPredios(){
Map<int,RPredio> rPredios=map<int,RPredio>();
FILE* fPredios=fopen("PREDIOS.dat","r+b");
FILE* fCanchas=fopen("CANCHAS.dat","r+b");
Predio p=read<Predio>(fPredios);
while(!feof(fPredios)){
    RPredio rP=rPredio(p);
    mapPut<int,RPredio>(rPredios,p.idPredio,rP);
    p=read<Predio>(fPredios);
}

Cancha c=read<Cancha>(fCanchas);
while(!feof(fCanchas)){
RPredio* rPredio=mapGet<int,RPredio>(rPredios,c.idPredio);
RCancha rC=rCancha(c);
mapPut<int,RCancha>(rPredio->canchas,c.nroCancha,rC);
c=read<Cancha>(fCanchas);
};

mapReset<int,RPredio>(rPredios);
while(mapHasNext<int,RPredio>(rPredios)){
    RPredio* rP=mapNextValue<int,RPredio>(rPredios);
    for(int i=0;i<31;i++){
        Map<int,RCancha> rCanchas=rP->canchas;
        arraySet<Map<int,RCancha>>(rP->calendario,i,rCanchas);
    }
}

fclose(fPredios);
fclose(fCanchas);

return rPredios;

}

void enviarMensaje(string nroCelular,string mensaje);

void notificarTurno(Reserva r,int posTurno,int numeroCancha){
    string hora;
    if(r.turno=='M'){
        hora=intToString(10+posTurno);
    }else if(r.turno=='T'){
        hora=intToString(14+posTurno);
    }
    else if(r.turno=='N'){
        hora=intToString(18+posTurno);
    }
    string mensaje="su turno fue confirmado para el dia " + to_string(r.diaMes) + " en la cancha numero "+to_string(numeroCancha) + "a las "+hora+" Hs";
    enviarMensaje(r.celContacto,mensaje); 
}

void notificarTurno(Rechazo r){
    string motivo;
    if(r.motivoRechazo==1){
        motivo="cancha no disponible";
    }else{
        motivo="presio inexistente";
    }
    
    string mensaje="su turno fue Rechazado por "+ motivo;
    enviarMensaje(r.reserva.celContacto,mensaje);
}


int main(){
Map<int,RPredio> rPredios=generarRPredios();
Array<Rechazo> rechazos=array<Rechazo>();

FILE*f=fopen("RESERVAS.dat","r+b");
Reserva r=read<Reserva>(f);
while(!feof(f)){
    
    RPredio* rP=mapGet<int,RPredio>(rPredios,r.idPredio);
    if(rP==nullptr){
        Rechazo rech=rechazo(r,2);
        arrayAdd<Rechazo>(rechazos,rech);
        notificarTurno(rech);
    }
    else{
    
    Map<int,RCancha>* diaCalendario=arrayGet<Map<int,RCancha>>(rP->calendario,r.diaMes-1);
    mapReset<int,RCancha>(*diaCalendario);
    
    bool reservado=false;
    while(!reservado && mapHasNext<int,RCancha>){
        RCancha* rC=mapNextValue<int,RCancha>(*diaCalendario);
        if(r.turno=='M'){
        if(arraySize<Reserva>(rC->turnosManiana)<4){
            reservado=true;
            int nroTurno=arrayAdd<Reserva>(rC->turnosManiana,r);
            notificarTurno(r,nroTurno,rC->c.nroCancha);
        }
        }
        else if(r.turno=='T'){
            if(arraySize<Reserva>(rC->turnosTarde)<4){
            reservado=true;
            int nroTurno=arrayAdd<Reserva>(rC->turnosTarde,r);
            notificarTurno(r,nroTurno,rC->c.nroCancha);
        }
        }
        else if(r.turno=='N'){
            if(arraySize<Reserva>(rC->turnosNoche)<4){
            reservado=true;
            int nroTurno=arrayAdd<Reserva>(rC->turnosNoche,r);
            notificarTurno(r,nroTurno,rC->c.nroCancha);
        }
        }
    }
    if(reservado==false){
        Rechazo rech=rechazo(r,1);
        arrayAdd<Rechazo>(rechazos,rech);
        notificarTurno(rech); 
    }

        
    }
    


    r=read<Reserva>(f);
}









fclose(f);

return 0;




}









#endif