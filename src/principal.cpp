
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

int toMin(const std::string& hhmm) {
    // Aseguramos que el string tenga 4 dígitos rellenando con ceros si es necesario
    std::string paddedHhmm = std::string(4 - hhmm.length(), '0') + hhmm;

    // Extraemos las horas y los minutos
    int hours = std::stoi(paddedHhmm.substr(0, 2));
    int minutes = std::stoi(paddedHhmm.substr(2, 2));

    // Convertimos todo a minutos
    return (hours * 60) + minutes;
}
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

return 0;
}

#endif
