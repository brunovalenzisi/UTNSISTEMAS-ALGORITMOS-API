
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

 int cmpInt(int a , int b){
    return a-b;
 }

template<typename T>
 void mostrarLista(Node<T>* & p){
Node<int>* aux=new Node<int>();
aux=p;
while(aux->sig !=NULL){
cout<<aux->info<<endl;
aux=aux->sig;
}
if(aux->sig==NULL){
    cout<<aux->info<<endl;
}


 }
int main(){
Node<int>* p = NULL; 
add<int>(p,1); 
add<int>(p,2); 
add<int>(p,3); // p->{1,2,3} 
 
int e = remove<int,int>(p,3,cmpInt); // p->{1,3} 
cout << e << endl; // Salida: 2 
cout<<replicate('*',20)<<endl;
 

mostrarLista(p);


return 0;
}

#endif
