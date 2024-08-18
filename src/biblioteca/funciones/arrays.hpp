#ifndef _TARRAYS_T_
#define _TARRAYS_T_

#include <iostream>

template <typename T>
int add(T arr[],int& len,T e)
{
   arr[len]=e;
   len++;
   return len-1;
}

template <typename T>
void insert(T arr[],int& len,T e,int p)
{
for(int i=len;i>p;i--){
   arr[i]=arr[i-1];
}
arr[p]=e;
len++;

}

template <typename T>
T remove(T arr[],int& len,int p)
{
   T ret=arr[p];
   for(int i=p;i<len-1;i++){
      arr[i]=arr[i+1];
   }
   len--;

   return ret;
}

template <typename T, typename K>
int find(T arr[],int len,K k,int cmpTK(T,K))
{  
   for(int i=0;i<len;i++){
      if(cmpTK(arr[i],k)==0){
         return i;
      }
   }
   return -1;
}

template <typename T>
int orderedInsert(T arr[],int& len,T e,int cmpTT(T,T)){
   if(len>0){
   for(int i=0;i<len;i++){
   if(cmpTT(arr[i],e)>=1){
      insert(arr,len,e,i);
      return i ;
   }else if(cmpTT(arr[i],e)==0){
      insert<T>(arr,len,e,i+1);
      return i+1;
   }
}
insert<T>(arr,len,e,len);
   }
   else{
   insert<T>(arr,len,e,0);
   return 0;
   }
}

template <typename T>
void sort(T arr[],int len,int cmpTT(T,T))
{
 bool ordenar = true;
    while (ordenar)
    {
        bool ordeno = false;
        for (int i = 0; i < len - 1; i++)
        {
            for (int j = 0; j < len - 1; j++)
            {
                T tActual = arr[j];
                T tSiguiente = arr[j+1];
                if (cmpTT(tActual, tSiguiente) > 0)
                {
                    arr[j]=tSiguiente;
                    arr[j+1]=tActual;
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
