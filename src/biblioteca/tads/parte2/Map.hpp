
#ifndef _TMAP_TAD_
#define _TMAP_TAD_

#include <iostream>
#include "Array.hpp"

using namespace std;

template<typename K, typename V>
struct Map {
    Array<K> keys;
    Array<V> values;
    int len = 0;
    int size = 0;
    int pos=0;
};


template<typename K, typename V>
Map<K, V> map() {
    Map<K, V> m;
    m.keys = array<K>();  
    m.values = array<V>(); 
    return m;
}


template<typename K, typename V>
V* mapGet(Map<K,V> m, K k) {
    V* v = NULL;
    for (int i = 0; i < m.len; i++) {
        if (*arrayGet(m.keys, i) == k) {
            v = arrayGet(m.values, i);
            break;
        }
    }
    return v;
}


template<typename K, typename V>
V* mapPut(Map<K, V>& m, K k, V v) {
      
    for (int i = 0; i < m.len; i++) {
        if (*arrayGet(m.keys, i) == k) {
            *arrayGet(m.values, i) = v; 
            return arrayGet(m.values, i);
        }
    }

    arrayAdd<K>(m.keys, k);
    arrayAdd<V>(m.values, v);
    
    m.len++;  
    m.size = m.keys.size;

    return arrayGet(m.values, m.len - 1); 
}

template<typename K,typename V>
bool mapContains(Map<K,V> m,K k)
{  for(int i=0;i<m.len;i++){
    if(*arrayGet(m.keys,i) == k){
        return true;
    }
} 
   return false;
}

template<typename K,typename V>
V mapRemove(Map<K,V>& m,K k)
{   
   V v;
   if(mapContains(m,k)){
    int pos;
    for(int i=0;i<m.len;i++){
        if(*arrayGet(m.keys,i)==k){
            pos=i;
            break;
        }
    }
    v=*arrayGet(m.values,pos);
    arrayRemove(m.keys,pos);
    arrayRemove(m.values,pos);
    m.len--;
   }
   return v;
}

template<typename K,typename V>
void mapRemoveAll(Map<K,V>& m)
{
   arrayRemoveAll(m.keys);
   arrayRemoveAll(m.values);
   m.len=0;
   m.size=10;

}

template<typename K,typename V>
int mapSize(Map<K,V> m)
{
   return m.len;
}

template<typename K,typename V>
bool mapHasNext(Map<K,V> m)
{  
   return m.pos<m.len;
}

template<typename K,typename V>
K mapNextKey(Map<K,V>& m)
{   
    K ret;
    if(mapHasNext(m)){
    ret=*arrayGet(m.keys,m.pos);
    m.pos++;
   return ret;
}
   m.pos=0;
   ret=*arrayGet(m.keys,m.pos);
   m.pos++;
   return ret;
}

template<typename K,typename V>
V* mapNextValue(Map<K,V>& m)
{
    V* ret;
    if(mapHasNext(m)){
    ret=arrayGet(m.values,m.pos);
    m.pos++;
   return ret;
}
   m.pos=0;
   ret=arrayGet(m.values,m.pos);
   m.pos++;
   return ret;
}

template<typename K,typename V>
void mapReset(Map<K,V>& m)
{
    m.pos=0;
}

template<typename K,typename V>
V* mapDiscover(Map<K,V>& m,K k,V v)
{   if(mapContains(m,k)){
    return mapGet(m,k);
}
    arrayAdd<K>(m.keys, k);
    arrayAdd<V>(m.values, v);
    m.len++;  
    m.size = m.keys.size;

    return arrayGet(m.values, m.len - 1); 
}


template<typename K,typename V>
void mapSortByKeys(Map<K,V>& m,int cmpKK(K,K))
{
 bool ordenar = true;
    while (ordenar)
    {
        bool ordeno = false;
        for (int i = 0; i < m.len - 1; i++)
        {
            for (int j = 0; j < m.len - 1; j++)
            {
                K kActual = *arrayGet(m.keys,j);
                K kSiguiente = *arrayGet(m.keys,j+1);
                V vActual = *arrayGet(m.values,j);
                V vSiguiente = *arrayGet(m.values,j+1);

                if (cmpKK(kActual, kSiguiente) > 0)
                {
                    *arrayGet(m.keys,j)=kSiguiente;
                    *arrayGet(m.keys,j+1)=kActual;
                    *arrayGet(m.values,j)=vSiguiente;
                    *arrayGet(m.values,j+1)=vActual;
                    ordeno = true;
                }
            }
        }
        if (!ordeno)
        {
            ordenar = false;
        }
    }
}

template<typename K,typename V>
void mapSortByValues(Map<K,V>& m,int cmpVV(V,V))
{
 bool ordenar = true;
    while (ordenar)
    {
        bool ordeno = false;
        for (int i = 0; i < m.len - 1; i++)
        {
            for (int j = 0; j < m.len - 1; j++)
            {
                K kActual = *arrayGet(m.keys,j);
                K kSiguiente = *arrayGet(m.keys,j+1);
                V vActual = *arrayGet(m.values,j);
                V vSiguiente = *arrayGet(m.values,j+1);

                if (cmpVV(vActual, vSiguiente) > 0)
                {
                    *arrayGet(m.keys,j)=kSiguiente;
                    *arrayGet(m.keys,j+1)=kActual;
                    *arrayGet(m.values,j)=vSiguiente;
                    *arrayGet(m.values,j+1)=vActual;
                    ordeno = true;
                }
            }
        }
        if (!ordeno)
        {
            ordenar = false;
        }
    }
}

#endif
