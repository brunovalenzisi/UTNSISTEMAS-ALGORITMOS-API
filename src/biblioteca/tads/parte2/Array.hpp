#ifndef _TARR_TAD_
#define _TARR_TAD_

#include <iostream>
#include <stdlib.h>
#include "../../funciones/arrays.hpp"

using namespace std;


template<typename T>
struct Array
{
   T* arr=new T[10];
   int len;
   int size;
};

template<typename T>
void redimensionar(Array<T>& a)
{
   T* newArr = new T[a.size + 10];
   for (int i = 0; i < a.len; i++) {
      newArr[i] = a.arr[i];
   }
   delete a.arr;  // Liberar la memoria del arreglo antiguo
   a.arr = newArr;
   a.size += 10;
}






template<typename T>
Array<T> array()
{
   Array<T> ret;
   ret.len=0;
   ret.size=10;
   return ret;
}

template<typename T>
int arrayAdd(Array<T>& a, T t)
{
   if (a.len == a.size) {
      redimensionar(a);
   }
   a.arr[a.len] = t;
   a.len++;
   
   return a.len - 1;
}

template<typename T>
T* arrayGet(Array<T> a,int p)
{
   T* ret=&a.arr[p];
   return ret;
}

template<typename T>
void arraySet(Array<T>& a,int p,T t)
{
a.arr[p]=t;
}

template<typename T>
void arrayInsert(Array<T>& a,T t,int p)
{
insert(a.arr,a.len,t,p);

}

template<typename T>
int arraySize(Array<T> a)
{
   return a.len;
   
}

template<typename T>
T arrayRemove(Array<T>& a,int p)
{
   T t=remove(a.arr,a.len,p);
   return t;
}

template<typename T>
void arrayRemoveAll(Array<T>& a)
{
   T* newArr=new T[10];
   delete a.arr;
   a.arr=newArr;
   a.len=0;
   a.size=10;
}

template<typename T,typename K>
int arrayFind(Array<T> a,K k,int cmpTK(T,K))
{
   return find<T,K>(a.arr,a.len,k,cmpTK);
}

template<typename T>
int arrayOrderedInsert(Array<T>& a,T t,int cmpTT(T,T))
{  
   return orderedInsert<T>(a.arr,a.len,t,cmpTT);
}

template<typename T>
T* arrayDiscover(Array<T>& a,T t,int cmpTT(T,T))
{  
   int pos=find<T>(a.arr,a.len,t,cmpTT);
   if (pos<0){
      add<T>(a.arr,a.len,t);
      T* puntero= &a.arr[a.len-1];
      return puntero;
   }else{
   T* puntero= &a.arr[pos];

   return puntero;

   }

}


template<typename T>
void arraySort(Array<T>& a,int cmpTT(T,T))
{
   sort<T>(a.arr,a.len,cmpTT);
}

#endif
