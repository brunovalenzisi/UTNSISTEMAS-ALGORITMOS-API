
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
List<int> lst = list<int>();  
// agregamos elementos 
cout<<*listAdd<int>(lst,1)<<endl;
cout<<replicate('*',20)<<endl;
cout<<lst.iNode->info<<endl;
cout<<lst.fNode->info<<endl;
cout<<replicate('*',20)<<endl;

cout<<*listAdd<int>(lst,2)<<endl; 
cout<<replicate('*',20)<<endl;
cout<<lst.iNode->info<<endl;
cout<<lst.fNode->info<<endl;
cout<<replicate('*',20)<<endl;
cout<<*listAdd<int>(lst,3)<<endl; 
cout<<replicate('*',20)<<endl;
cout<<lst.iNode->info<<endl;
cout<<lst.fNode->info<<endl;
cout<<replicate('*',20)<<endl;

cout<<lst.size<<endl;

//mostrarLista(q);

return 0;
}

#endif
