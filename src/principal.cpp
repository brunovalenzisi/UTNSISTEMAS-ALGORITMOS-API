
#ifndef _MAIN
#define _MAIN

#include <iostream>
#include "biblioteca/funciones/strings.hpp"
#include "biblioteca/funciones/tokens.hpp"
#include "biblioteca/funciones/files.hpp"
#include "biblioteca/tads/parte2/Array.hpp"
#include "biblioteca/tads/parte2/Map.hpp"
#include "biblioteca/tads/parte2/List.hpp"
#include "biblioteca/tads/parte2/Stack.hpp"
#include "biblioteca/tads/parte2/Queue.hpp"
#include "biblioteca/tads/parte1/Coll.hpp"
#include "biblioteca/tads/parte1/MultidimColl.hpp"
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
string fechaToString(Fecha f){
string salida="";
salida+=intToString(f.dia);
salida+='/';
salida+=intToString(f.mes);
salida+='/';
salida+=intToString(f.anio);

return salida;
}

int main(){
cout<<intToString(1991)<<endl;
cout<<"digitos: "<<digitCount(1)<<endl;
cout<<"digito: "<<getDigit(10,0)<<endl;
cout<<"digito: "<<getDigit(1991,1)<<endl;
cout<<"digito: "<<getDigit(1991,2)<<endl;
cout<<"digito: "<<getDigit(1991,3)<<endl;
FILE* f = fopen("test.test","w+b");
write<Fecha>(f,fecha(18,05,1991));
write<Fecha>(f,fecha(19,05,1991));
write<Fecha>(f,fecha(20,05,1991));
seek<Fecha>(f,0);
cout<<filePos<Fecha>(f)<<endl;
cout<<fechaToString(read<Fecha>(f));
return 0;
}

#endif

   
   
