#ifndef _MAINHPP
#define _MAINHPP
#include <iostream>
#include <iostream>
#include <sstream>
#include <string>
#include <string.h>
#include <stdlib.h>
#include "../../biblioteca/funciones/strings.hpp"
#include "../../biblioteca/funciones/tokens.hpp"
#include "../../biblioteca/tads/parte1/Coll.hpp"
#include "../../biblioteca/tads/parte2/Queue.hpp"
#include "../../biblioteca/tads/parte2/List.hpp"
#include "../../biblioteca/tads/parte2/Stack.hpp"
using namespace std;

struct Fecha{
int dia;
int mes;
int anio;
};

Fecha fecha(int dia, int mes, int anio){
Fecha f;
f.dia=dia;
f.mes=mes;
f.anio=anio;
return f;
}
string fechaMostrar(Fecha f){
   string fecha;
   fecha+=intToString(f.dia);
   fecha+="/";
   fecha+=intToString(f.mes);
   fecha+="/";
   fecha+=intToString(f.anio);
   fecha+=" ";
   return fecha;
}

struct Socio
{
   int idSocio;
   char nombre[50];
   int  idSocioRef;  // socio referente
   Fecha fechaIngreso;
   double totalVentasAcumuladas;
   double liquidacionAnterior;
   double liquidacionesAcumuladas;
};

struct RSocio{
Socio s;
double liquidacionActual;
};

struct Venta
{
   int idSocio;
   int idProducto;
   char observ[100];
   Fecha fecha; 
   double importe;
};

RSocio rSocio(Socio s){
RSocio rC;
rC.s=s;
double liquidacionActual=0;
return rC;
}


Venta venta(int id,Fecha f,double monto ){
Venta v;
v.idSocio=id;
v.importe=monto;
v.fecha=f;
}



#endif