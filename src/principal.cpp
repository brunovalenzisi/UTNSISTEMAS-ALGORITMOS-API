
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
Node<int>* q = NULL; 
enqueue<int>(q,1); // {1}<-q 
cout<<q->info<<endl;
enqueue<int>(q,2); // {1,2}<-q 
cout<<q->info<<endl;
enqueue<int>(q,3); // {1,2,3}<-q 
cout<<q->info<<endl;
cout<<q->sig->info<<endl;

 
int e = dequeue<int>(q); // {2,3}<-q 
cout << e << endl; // Salida: 1

//mostrarLista(q);

return 0;
}

#endif
