#ifndef _TFILES_T_
#define _TFILES_T_

#include <iostream>
#include <stdio.h>

template<typename T> void write(FILE* f, T t)
{
fseek(f,0,SEEK_CUR);
T nuevoT = t;
fwrite(&t,sizeof(t),1,f);

}

template<typename T> T read(FILE* f)
{
 fseek(f,0,SEEK_CUR);

   T t ;
   fread(&t,sizeof(t),1,f);
   return t;
}

template<typename T> void seek(FILE* f, int n)
{
   fseek(f,sizeof(T)*n,SEEK_SET);
}

template<typename T> int fileSize(FILE* f)
{
   fseek(f,0,SEEK_END);
   int totales=ftell(f);
   
   return totales;
}

template<typename T> int filePos(FILE* f)
{  
   int byteActual=ftell(f);
   int pos=byteActual/sizeof(T);
   return pos+1;
}

#endif
