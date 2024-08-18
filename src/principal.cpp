
#ifndef _MAIN
#define _MAIN

#include <iostream>
#include "biblioteca/funciones/strings.hpp"
#include "biblioteca/funciones/tokens.hpp"
#include "biblioteca/funciones/arrays.hpp"
#include "biblioteca/funciones/files.hpp"
#include "biblioteca/tads/parte2/Array.hpp"
#include "biblioteca/tads/parte2/Map.hpp"
#include "biblioteca/tads/parte2/List.hpp"
#include "biblioteca/tads/parte2/Stack.hpp"
#include "biblioteca/tads/parte2/Queue.hpp"
#include "biblioteca/tads/parte1/Coll.hpp"
#include "biblioteca/tads/parte1/MultidimColl.hpp"
#include "principal.hpp"
using namespace std;





 int cmpInt(int a, int b){
return a-b;
 }

 
int main(){

Array<int> a = array<int>(); 
arrayAdd<int>(a,2); 
arrayAdd<int>(a,1); 
arrayAdd<int>(a,3); 
 
// ordeno 
arraySort<int>(a,cmpInt);
for(int i =0;i<arraySize(a);i++){
cout<<*(arrayGet<int>(a,i))<<endl;
}

}




#endif
