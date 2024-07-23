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

double mtsPorcencuales(int idCons, int depto)
{
    double d;
    return d;
}

Coll<Departamento> cargarDtos(Consorcio cons)
{
    Coll<Departamento> coll;
    int cantDtos = cons.cantPisos * cons.dtosPorPiso;
    for (int i = 0; i < cantDtos; i++)
    {
        Departamento dto = departamento(i, mtsPorcencuales(cons.idCons, i));
        collAdd<Departamento>(coll, dto, departamentoToString);
    }

    return coll;
};

Coll<RConsorcio> cargarRConsorcios()
{

    Coll<RConsorcio> coll;
    FILE *f = fopen("CONSORCIOS.dat", "r+b");
    Consorcio cons = read<Consorcio>(f);
    while (!feof(f))
    {
        Coll<Departamento> collDto = cargarDtos(cons);
        RConsorcio rCons = rConsorcio(cons, 0.0, collDto);
        collAdd<RConsorcio>(coll, rCons, rConsorcioToString);
        cons = read<Consorcio>(f);
    }
    return coll;
}

int cmpIdCons(RConsorcio rCons,int idCons){
    return rCons.consorcio.idCons-idCons;
}

void procesarGasto(Gasto g, Coll<RConsorcio> &coll) {
    int posRCons = collFind<RConsorcio,int>(coll,g.idCons,cmpIdCons,rConsorcioFromString);
    RConsorcio rCons=collGetAt<RConsorcio>(coll,posRCons,rConsorcioFromString);
    rCons.gastosToales+=g.importe;
};


void imprimirRotulo(RConsorcio rCons){
cout<<"Consorcio Calle: "<<rCons.consorcio.direccion<<replicate(' ',10)<<"Gastos Totales: $"<<rCons.gastosToales<<endl;
cout<<"Departamento"<<replicate(' ',10)<<"Mts.2."<<replicate(' ',10)<<"Total a pagar ($)"<<endl;
};
void mostrarGastosPorCosorcio(Coll<RConsorcio> &coll) {
    collReset(coll);
    RConsorcio rCons=collNext<RConsorcio>(coll,rConsorcioFromString);
    while(collHasNext(coll)){
        imprimirRotulo(rCons);
        Coll<Departamento> collDtos=rCons.collDtos;
        collReset(collDtos);
        Departamento dto=collNext<Departamento>(collDtos,departamentoFromString);
        while(collHasNext(collDtos)){
            cout<<dto.id<<replicate(' ',10)<<dto.porcentaje<<replicate(' ',10)<<rCons.gastosToales*dto.porcentaje/100<<endl;
            dto=collNext<Departamento>(collDtos,departamentoFromString);
        }
        rCons=collNext<RConsorcio>(coll,rConsorcioFromString);
    }
};

int main()
{
    Coll<RConsorcio> collRConsorcios = cargarRConsorcios();
    
    FILE *f = fopen("GASTOS.dat", "r+b");
    Gasto g = read<Gasto>(f);
    while (!feof(f))
    {
        procesarGasto(g, collRConsorcios);
        g = read<Gasto>(f);
    }
    mostrarGastosPorCosorcio(collRConsorcios);
    return 0;
}

#endif