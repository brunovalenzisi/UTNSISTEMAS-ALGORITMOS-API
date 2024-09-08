
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

int cmpVV(string a, string b) {
return cmpString(a,b);
}




 
int main(){
Map<int,string> m = map<int,string>();
mapDiscover<int,string>(m,2,"Dos"); 
mapDiscover<int,string>(m,1,"Uno"); 
mapDiscover<int,string>(m,3,"Tres"); 
mapDiscover<int,string>(m,4,"Cuatro"); 
mapDiscover<int,string>(m,1,"Uno"); 
mapDiscover<int,string>(m,2,"Dos"); 
mapDiscover<int,string>(m,3,"Tres"); 
mapDiscover<int,string>(m,4,"Cuatro"); 
 
mapReset<int,string>(m); 
mapSortByValues<int,string>(m,cmpVV);
while( mapHasNext<int,string>(m) ) 
{ 
   string* s = mapNextValue<int,string>(m); 
   cout << *s << endl; 
}



return 0;
}




#endif
