#ifndef _TLIST_T_
#define _TLIST_T_

#include <iostream>
#include <stdio.h>

template <typename T>
struct Node
{
T info;
Node<T>* sig;
};

template <typename T>
Node<T>* add(Node<T>*& p,T e)
{  
Node<T>* n = new Node<T>();
n->info=e;
n->sig=NULL;
if(p!=NULL)
{
Node<T>* aux=p;
while(aux->sig !=NULL){
aux=aux->sig;
}
aux->sig=n;
}else{
p=n;
}

return n;
}

template <typename T>
Node<T>* addFirst(Node<T>*& p,T e)
{  
 Node<T>* n = new Node<T>();
    n->info = e;
    n->sig = p;
    p = n;
    return n;
}

template <typename T, typename K>
T remove(Node<T>*& p,K k,int cmpTK(T,K))
{  
   T ret;

   if(p->sig==NULL && cmpTK(p->info,k)==0){
   ret=p->info;
   p=NULL;
   return ret;
} 

if(p->sig !=NULL && cmpTK(p->info,k)==0){
   ret=p->info;
   p=p->sig;
   return ret;
}

   Node<T>* aux=p->sig;
   Node<T>* initNode=p;

   while(aux->sig!=NULL){
      if(cmpTK(aux->info,k)==0){
         initNode->sig=aux->sig;
         ret=aux->info;
         return ret;
      }
      initNode=aux;
      aux=aux->sig;
   }
   if(cmpTK(aux->info,k)==0){
   ret=aux->info;
   initNode->sig=NULL;
   return ret;
}  
   return ret;
}

template <typename T>
T removeFirst(Node<T>*& p)
{
   T t= p->info;
   if(p->sig!=NULL){
      t=p->info;
      p=p->sig;
   }
   else{
   p=NULL;
   } 
   
   return t;
}

template <typename T, typename K>
Node<T>* find(Node<T>* p,K k,int cmpTK(T,K))
{
   return NULL;
}

template <typename T>
Node<T>* orderedInsert(Node<T>*& p,T e,int cmpTT(T,T))
{
   return NULL;
}

template <typename T>
Node<T>* searchAndInsert(Node<T>*& p,T e,bool& enc,int cmpTT(T,T))
{
   return NULL;
}

template <typename T>
void sort(Node<T>*& p,int cmpTT(T,T))
{
}

template <typename T>
bool isEmpty(Node<T>* p)
{
   return true;
}

template <typename T>
void free(Node<T>*& p)
{
}

template <typename T>
Node<T>* push(Node<T>*& p,T e)
{
   return NULL;
}

template <typename T> T pop(Node<T>*& p)
{
   T t;
   return t;
}

template <typename T>
Node<T>* enqueue(Node<T>*& p,Node<T>*& q,T e)
{
   return NULL;
}

template <typename T>
Node<T>* enqueue(Node<T>*& q,T e)
{
   return NULL;
}

template <typename T>
T dequeue(Node<T>*& p, Node<T>*& q)
{
   T t;
   return t;
}

template <typename T>
T dequeue(Node<T>*& q)
{
   T t;
   return t;
}

#endif
