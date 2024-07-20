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

Coll<REmpresa> cargarREmpresas(){
Coll<REmpresa> coll;
FILE* f=fopen("EMPRESAS.dat","r+b");
Empresa emp=read<Empresa>(f);
while(!feof(f)){
    Coll<EmpleadoAccidentado> collEmpAcc;
    REmpresa rEmp=rEmpresa(emp,collEmpAcc,0.0,0);
    collAdd<REmpresa>(coll,rEmp,rEmpresaToString);
    emp=read<Empresa>(f);
}
    return coll;
}

int cmpIdREmpresa(REmpresa rEmp,int idREmpresa){
return(rEmp.empresa.idEmpresa-idREmpresa);
}

int cmpIdLegajo(EmpleadoAccidentado empAcc,int leg){
    return empAcc.legajo-leg;
};

void procesarAccidente(Accidente a,Coll<REmpresa> &coll){
int posREmpresa=collFind<REmpresa,int>(coll,a.idEmpresa,cmpIdREmpresa,rEmpresaFromString);
REmpresa rEmp=collGetAt<REmpresa>(coll,posREmpresa,rEmpresaFromString);
rEmp.cantAccidentes++;
int posEmpAcc=collFind<EmpleadoAccidentado,int>(rEmp.collEmp,a.legajo,cmpIdLegajo,empleadoAccidentadoFromString);
if(posEmpAcc<0){
    EmpleadoAccidentado empAcc=collGetAt<EmpleadoAccidentado>(rEmp.collEmp,posEmpAcc,empleadoAccidentadoFromString);
    empAcc.diasDeLicencia+=a.cantDiasLicencia;
    collSetAt<EmpleadoAccidentado>(rEmp.collEmp,empAcc,posEmpAcc,empleadoAccidentadoToString);
    collSetAt<REmpresa>(coll,rEmp,posREmpresa,rEmpresaToString);
}
else{
EmpleadoAccidentado empAcc=empleadoAccidentado(a.legajo,a.cantDiasLicencia);
collAdd<EmpleadoAccidentado>(rEmp.collEmp,empAcc,empleadoAccidentadoToString);
collSetAt<REmpresa>(coll,rEmp,posREmpresa,rEmpresaToString);
}
};

double porcentaje(int cantTrabajadores,int cantAccidentes){
double p;
    return p;
}

 int asignarPorcentajes(Coll<REmpresa> &coll){
int  posEmpMasAjustada=0;
double maxPor=0;
collReset(coll);
REmpresa rEmp=collNext<REmpresa>(coll,rEmpresaFromString);
while(collHasNext(coll)){
    rEmp.porcentaje=porcentaje(rEmp.empresa.cantTrabAsegurados,rEmp.cantAccidentes);
    collSetAt<REmpresa>(coll,rEmp,coll.pos,rEmpresaToString);
    if(rEmp.porcentaje>maxPor){
        maxPor=rEmp.porcentaje;
        posEmpMasAjustada=coll.pos;
    }
    rEmp=collNext<REmpresa>(coll,rEmpresaFromString);
}

return posEmpMasAjustada;
}
void mostrarporcentajes(Coll<REmpresa> &coll){
    collReset(coll);
    REmpresa rEmp=collNext<REmpresa>(coll,rEmpresaFromString);
    cout<<replicate('*',100)<<endl;
    cout<<"LISTADO DE PORCENTAJE DE REAJUSTE"<<endl;
    cout<<"Razon social              Porcentaje"<<endl;
    while(collHasNext(coll)){
        cout<<rEmp.empresa.razonSocial<<replicate(' ',15)<<rEmp.porcentaje<<endl;
        rEmp=collNext<REmpresa>(coll,rEmpresaFromString);
    }
cout<<replicate('*',100)<<endl;    
}

void mostrarAccidentados(Coll<REmpresa> collREmp,int pos){
    REmpresa rEmp=collGetAt<REmpresa>(collREmp,pos,rEmpresaFromString);
    Coll<EmpleadoAccidentado> collEmpAcc=rEmp.collEmp;
    collReset(collEmpAcc);
    cout<<replicate('*',100)<<endl;
    cout<<"Razon Social: "<<rEmp.empresa.razonSocial<<endl;
    cout<<"Legajo:                  Total de dias ausente"<<endl;
    while(collHasNext(collEmpAcc)){
    EmpleadoAccidentado empAcc=collNext<EmpleadoAccidentado>(collEmpAcc,empleadoAccidentadoFromString);
    cout<<empAcc.legajo<<replicate(' ',25)<<empAcc.diasDeLicencia<<endl;
    }
    cout<<replicate('*',100)<<endl;
}


int main()
{
    Coll<REmpresa> collREmpresas= cargarREmpresas();
    FILE* f = fopen("ACCIDENTE.DAT","r+b");
    Accidente a=read<Accidente>(f);

    while(!feof(f)){
        procesarAccidente(a,collREmpresas);
        a=read<Accidente>(f);
    }
        int posMasAccidentada =asignarPorcentajes(collREmpresas);
        mostrarporcentajes(collREmpresas);
        mostrarAccidentados(collREmpresas,posMasAccidentada);
   return 0;
}

#endif