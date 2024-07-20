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

Coll<RCuento>cuentosCargar(){
    Coll<RCuento> coll;
    FILE* f=fopen("CUENTOS.dat","r+b");
    Cuento c=read<Cuento>(f);
    while(!feof(f)){
        RCuento rC=rCuento(c,0,0,0,0,0);
        collAdd<RCuento>(coll,rC,rCuentoToString);
        c=read<Cuento>(f);
    }

    fclose(f);
    return coll;
}

Coll<RRelator>relatoresCargar(){
       Coll<RRelator> coll;
    FILE* f=fopen("RELATORES.dat","r+b");
    Relator r=read<Relator>(f);
    while(!feof(f)){
        RRelator rR=rRelator(r,0);
        collAdd<RRelator>(coll,rR,rRelatorToString);
        r=read<Relator>(f);
    }

    fclose(f);
    return coll;
}

int cmpIdCuento(RCuento c,int id){
return c.c.idCuento-id;
}

int cmpIdRRelator(RRelator rRel,int idRel){
    return rRel.r.idRelator-idRel;
}

void contarReproducciones(Reproduccion rep,Coll<RCuento> & coll,Coll<RRelator> & collRRel){
    int posRCuento=collFind<RCuento>(coll,rep.idCuento,cmpIdCuento,rCuentoFromString);
    RCuento rCuento=collGetAt<RCuento>(coll,posRCuento,rCuentoFromString);
    int duracion=rCuento.c.duracion;
    double minRep=rep.minutos*1.0;
    double completado=minRep/duracion*100.0;
    if(completado>75){
        int posRRel=collFind<RRelator>(collRRel,rCuento.c.idRelator,cmpIdRRelator,rRelatorFromString);
        RRelator rRel=collGetAt<RRelator>(collRRel,posRRel,rRelatorFromString);
        rRel.parcial75++;
        collSetAt<RRelator>(collRRel,rRel,posRRel,rRelatorToString);
        rCuento.parcial75++;

    }else if(completado>50){
        rCuento.parcial50++;
    }else if(completado>25){
        rCuento.parcial25++;
    }else{
        rCuento.parcial0++;
    }
    collSetAt<RCuento>(coll,rCuento,posRCuento,rCuentoToString);

}


int cmpCuento(RCuento rC1,RCuento rC2){
    return rC2.parcial75-rC1.parcial75;

}
void ordenarCuentos(Coll<RCuento> & coll){
    collSort<RCuento>(coll,cmpCuento,rCuentoFromString,rCuentoToString);

    }

void mostrarResultadosCuentos(Coll<RCuento> coll){
    for(int i=0;i<collSize<RCuento>(coll);i++){
        RCuento rCuento=collGetAt<RCuento>(coll,i,rCuentoFromString);
        cout<<"TITULO: "<<rCuento.c.titulo<<endl;
        cout<<"Reproducciones (75-100)% : "<<rCuento.parcial75<<endl;
        cout<<"Reproducciones (50-75)% : "<<rCuento.parcial50<<endl;
        cout<<"Reproducciones (25-50)% : "<<rCuento.parcial25<<endl;
        cout<<"Reproducciones <25% : "<<rCuento.parcial0<<endl;
        cout<<replicate('*',100)<<endl;
    }
    cout<<replicate('*',100)<<endl;

}

int cmpRRelator(RRelator rRel1,RRelator rRel2){
    return rRel2.parcial75-rRel1.parcial75;
}
void mostrarResultadosRelatores(Coll<RRelator> coll){
    collSort<RRelator>(coll,cmpRRelator,rRelatorFromString,rRelatorToString);

    for(int i=0;i<collSize<RRelator>(coll) && i<10;i++){
        RRelator rRel=collGetAt<RRelator>(coll,i,rRelatorFromString);
        cout<<"RELATOR "<<rRel.r.nombre<<endl; 
    }
    cout<<replicate('*',100)<<endl;

}


int main()
{

    Coll<RCuento> collRCuentos=cuentosCargar();
    Coll<RRelator> collRRelatores=relatoresCargar();
    FILE* f=fopen("REPRODUCCIONES.dat","r+b");
    Reproduccion r=read<Reproduccion>(f);
    while(!feof(f)){
        contarReproducciones(r,collRCuentos,collRRelatores);
        r=read<Reproduccion>(f);
    }
        ordenarCuentos(collRCuentos);
        mostrarResultadosCuentos(collRCuentos);
        mostrarResultadosRelatores(collRRelatores);

   return 0;
}

#endif