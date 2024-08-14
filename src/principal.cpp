
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



int main(){
   string a[10]; // array 
int len = 0;  // longitud 
 
add<string>(a,len,"John"); 
add<string>(a,len,"Paul"); 
add<string>(a,len,"George"); 
add<string>(a,len,"Ringo"); 
 
// recorro y muestro 
for(int i=0; i<len; i++) 
{cout << a[i] << endl; 
}
   return 0;
}



#endif
