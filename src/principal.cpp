
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
coleccion.datos="0|1|2";
cout<<collNext(coleccion,stringToInt)<<endl;
cout<<collNext(coleccion,stringToInt)<<endl;
cout<<collNext(coleccion,stringToInt)<<endl;
cout<<collNext(coleccion,stringToInt)<<endl;



return 0;

}

#endif

   
   
