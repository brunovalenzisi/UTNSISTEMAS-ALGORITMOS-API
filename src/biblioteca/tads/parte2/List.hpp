#ifndef _TLIST_TAD_
#define _TLIST_TAD_

#include <iostream>

#include "../../funciones/lists.hpp"

using namespace std;

template<typename T>
struct List
{
   Node<T>* iNode=NULL;
   Node<T>* fNode=NULL;
   Node<T>* cNode=NULL;

   int size;
   
};

template<typename T>
List<T> list()
{
   List<T> lst;
   lst.size=0;
   lst.cNode=new Node<T>;
   lst.cNode=NULL;
   return lst;
}


template<typename T>
T* listAdd(List<T>& lst, T e) {
   Node<T>* node; 
   node= add(lst.iNode, e);
   if(lst.size==0){
      lst.iNode=node;
      lst.fNode=node;
      lst.cNode=node;
   }else{
      lst.fNode=node;
   }
      lst.size++;
       return &(node->info); 
}

template<typename T>
T* listAddFirst(List<T>& lst,T e)
{           
      Node<T>* node; 
   node= addFirst(lst.iNode, e);
   if(lst.size==0){
      lst.iNode=node;
      lst.fNode=node;
      lst.cNode=node;
   }else{
      lst.iNode=node;
   }
      lst.size++;
       return &(node->info);
}

template<typename T,typename K>
T listRemove(List<T>& lst,K k,int cmpTK(T,K))
{
 T t = remove(lst.iNode, k, cmpTK); 
 if(&t==lst.cNode){
   if(lst.cNode==lst.fNode){
      lst.cNode=lst.iNode;
   }else{lst.cNode=lst.cNode->sig;}
 }

   
   if (lst.iNode == NULL) {
      lst.fNode = NULL; 
   } else {
      
      Node<T>* current = lst.iNode;
      while (current->sig != NULL) {
         current = current->sig;
      }
      lst.fNode = current; 
   }
   lst.size--;

   return t; 
}

template<typename T>
T listRemoveFirst(List<T>& lst)
{
   T removed = removeFirst(lst.iNode);
    if(&removed==lst.cNode){
   if(lst.cNode==lst.fNode){
      lst.cNode=lst.iNode;
   }else{lst.cNode=lst.cNode->sig;}
 }
    if(lst.iNode == NULL){
      lst.fNode=NULL;
    }
    lst.size--;
   return removed;
}

template<typename T,typename K>
T* listFind(List<T> lst,K k,int cmpTK(T,K))
{
   Node<T>* node = find<T,K>(lst.iNode,k,cmpTK);
 if (node != NULL) {
        return &(node->info);
    }
    return NULL;
}

template<typename T>
bool listIsEmpty(List<T> lst)
{
   return lst.size==0;
}

template<typename T>
int listSize(List<T> lst)
{
   return lst.size;
}

template<typename T>
void listFree(List<T>& lst)
{

free(lst.iNode);
lst.fNode = NULL;
}



template<typename T>
T* listDiscover(List<T>& lst,T t,int cmpTT(T,T))
{
   Node<T>* found=find<T,T>(lst.iNode,t,cmpTT);
   if(found==NULL){
      return listAdd<T>(lst,t);
   }
   else
   {
   return &found->info;
   }
}

template<typename T>
T* listOrderedInsert(List<T>& lst,T t,int cmpTT(T,T))
{
   Node<T>* nuevoNodo=orderedInsert<T>(lst.iNode,t,cmpTT);
   return &nuevoNodo->info;
}

template<typename T>
void listSort(List<T>& lst,int cmpTT(T,T))
{
sort<T>(lst.iNode,cmpTT);
}

template<typename T>
void listReset(List<T>& lst)
{
   lst.cNode=lst.iNode;
}

template<typename T>
bool listHasNext(List<T> lst)
{  
   return lst.cNode->sig!=NULL;
}

template<typename T>
T* listNext(List<T>& lst)
{
   T* t=NULL;
   if(!listIsEmpty<T>(lst)){
      t=&lst.cNode->info;
      if(lst.cNode==lst.fNode){
         lst.cNode=lst.iNode;
      }else{
         lst.cNode=lst.cNode->sig;
      }
   }
   
   return t;
}

template<typename T>
T* listNext(List<T>& lst,bool& endOfList)
{
   T* t=NULL;
   if(!listIsEmpty<T>(lst)){
      t=&lst.cNode->info;
      if(lst.cNode==lst.fNode){
         lst.cNode=lst.iNode;
         endOfList=true;
      }else{
         lst.cNode=lst.cNode->sig;
         endOfList=false;
      }
   }
   else{endOfList=true;}
   
   return t;
}

#endif