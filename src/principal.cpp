
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
Stack<int> s =stack<int>();
stackPush<int>(s,1);
stackPush<int>(s,2);
stackPush<int>(s,3);
stackPush<int>(s,4);

cout<<"size: "<<stackSize<int>(s)<<endl;

cout<<stackPop<int>(s)<<endl;
cout<<stackPop<int>(s)<<endl;
cout<<stackPop<int>(s)<<endl;
cout<<stackPop<int>(s)<<endl;
cout<<"esta vacia: "<<stackIsEmpty<int>(s)<<endl;

cout<<"size: "<<stackSize<int>(s)<<endl;








//mostrarLista(q);

return 0;
}

#endif
