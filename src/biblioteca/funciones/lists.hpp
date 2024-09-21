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
       if (p == NULL) {
        return NULL;
    }
   if(cmpTK(p->info,k)==0){
      return p;
   }
   while(p->sig!=NULL){
      if(cmpTK(p->info,k)==0){
         return p;
      }else{
         p=p->sig;
      }
}
   if(cmpTK(p->info,k)==0){
      return p;
   }
   return NULL;
}

template <typename T>
Node<T>* orderedInsert(Node<T>*& p,T e,int cmpTT(T,T))
{     
   Node<T>* aux=p;
   Node<T>* pL=new Node<T>();
   Node<T>* nNode=new Node<T>();
   nNode->info=e;

   if(p==NULL){
      p=new Node<T>();
      p->info=e;
      p->sig=NULL;
   return p;
   }
   if(p->sig==NULL){

   if(cmpTT(p->info,e)>0){
   nNode->sig=p;
   p=nNode;
   return p;
   }else{
      p->sig=nNode;
      nNode->sig=NULL;
      return nNode;
   }
   }
   else{
         if(cmpTT(aux->info,e)>=0){
           nNode->sig=p;
           p=nNode;                         
            return p;
         }
         else{
            while(aux->sig!=NULL){
               pL=aux;
               aux=aux->sig;
               if(cmpTT(aux->info,e)>=0){
                  pL->sig=nNode;
                  nNode->sig=aux;
                  return nNode;
               }
         }
         aux->sig=nNode;
         nNode->sig=NULL;
         return nNode;
      }
   }
}

template <typename T>
Node<T>* searchAndInsert(Node<T>*& p,T e,bool& enc,int cmpTT(T,T))
{  
   Node<T>* found=find<T,T>(p,e,cmpTT);
   if(found==NULL){
      enc=false;
      return orderedInsert(p,e,cmpTT);
   }else{
      enc=true;
      return found;
   }
}

template <typename T>
void sort(Node<T>*& head, int cmpTT(T, T)) {
    if (head == NULL || head->sig == NULL) {
        
        return;
    }

    bool ordenar = true;
    while (ordenar) {
        bool ordeno = false;
        Node<T>* current = head;
        Node<T>* prev = NULL;
        while (current != NULL && current->sig != NULL) {
            Node<T>* next = current->sig;
            if (cmpTT(current->info, next->info) > 0) {
                
                if (prev != NULL) {
                    prev->sig = next;
                } else {
                   
                    head = next;
                }
                current->sig = next->sig;
                next->sig = current;
                ordeno = true;
            }
            prev = current;
            current = current->sig;
        }

        if (!ordeno) {
            ordenar = false;
        }
    }
}

template <typename T>
bool isEmpty(Node<T>* p)
{ 
   return p==NULL;
}

template <typename T>
void free(Node<T>*& p)
{
   while (p != NULL) {
        Node<T>* temp = p;  
        p = p->sig;         
    }
    p = NULL;
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
