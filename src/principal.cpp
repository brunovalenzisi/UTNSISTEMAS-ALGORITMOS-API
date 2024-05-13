
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

int main(){
string s = "John|Paul";
char sep = '|';
int i = 2;
removeTokenAt(s,sep,i);
cout << s << endl; // Salida: John|Paul|Ringo
i = 0;
removeTokenAt(s,sep,i);
cout << s << endl; // Salida: Paul|Ringo

}

#endif

   
   
