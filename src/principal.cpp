
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
 listAdd<int>(lst,3);
 listAdd<int>(lst,2);
 listAdd<int>(lst,7);
 listAdd<int>(lst,4);
 listAdd<int>(lst,1);


bool end=false;
cout<<"Sizze: "<< listSize(lst)<<endl;


cout<<*listNext<int>(lst,end)<<endl;
cout<<"Termino: "<<end<<endl;
cout<<*listNext<int>(lst,end)<<endl;
cout<<"Termino: "<<end<<endl;
cout<<*listNext<int>(lst,end)<<endl;
cout<<"Termino: "<<end<<endl;
cout<<*listNext<int>(lst,end)<<endl;
cout<<"Termino: "<<end<<endl;
cout<<*listNext<int>(lst,end)<<endl;
cout<<"Termino: "<<end<<endl;
cout<<*listNext<int>(lst,end)<<endl;
cout<<"Termino: "<<end<<endl;
cout<<*listNext<int>(lst,end)<<endl;
cout<<"Termino: "<<end<<endl;








//mostrarLista(q);

return 0;
}

#endif
