
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
int cmpInt(int a,int b){

    return (a > b) ? 1 : ((a < b) ? -1 : 0);
}

int main(){
Coll <int>coleccion=coll<int>();
collAdd<int>(coleccion,5,intToString);
collAdd<int>(coleccion,6,intToString);
collAdd<int>(coleccion,7,intToString);
cout<<collSize<int>(coleccion)<<endl;
cout<<coleccion.datos<<endl;
collRemoveAt(coleccion,1);
cout<<coleccion.datos<<endl;
collRemoveAll(coleccion);
cout<<coleccion.datos<<endl;
collAdd<int>(coleccion,5,intToString);
collAdd<int>(coleccion,6,intToString);
collAdd<int>(coleccion,7,intToString);
cout<<coleccion.datos<<endl;
collSetAt<int>(coleccion,0,1,intToString);
cout<<coleccion.datos<<endl;
collSetAt<int>(coleccion,0,0,intToString);
cout<<coleccion.datos<<endl;
collAdd<int>(coleccion,5,intToString);
collAdd<int>(coleccion,6,intToString);
collAdd<int>(coleccion,7,intToString);
cout<<coleccion.datos<<endl;
cout<<collGetAt<int>(coleccion,3,stringToInt)<<endl;

cout<<collFind<int>(coleccion,0,cmpInt,stringToInt)<<endl;

return 0;

}

#endif

   
   
