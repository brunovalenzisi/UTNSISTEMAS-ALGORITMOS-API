#ifndef _TTOKENS_T_
#define _TTOKENS_T_

#include <iostream>
#include <stdio.h>
#include "strings.hpp"
using namespace std;

int tokenCount(string s, char sep)
{
   int count = 1;
   for (int i = 0; i < length(s); i++)
   {
      if (s[i] == sep)
      {
         count++;
      }
   }
   return (count == 1 && length(s) == 0) ? 0 : count;
}

void addToken(string &s, char sep, string t)
{
   if (s == "")
   {
      s += t;
   }
   else
   {
      s += sep + t;
   }
}

string getTokenAt(string s, char sep, int i)
{
   string salida = "";
   if (i == 0)
   {
      int posI = 0;
      int posF = indexOfN(s, sep, i + 1);
      salida += substring(s, posI, posF);
   }
   else
   {
      int posI = indexOfN(s, sep, i) + 1;
      int posF = indexOfN(s, sep, i + 1);
      salida += substring(s, posI, posF);
   }
   return salida;
}

void removeTokenAt(string &s, char sep, int i)
{
   if (i == 0)
   {
      int posI = 0;
      int posF = indexOfN(s,sep,i+1);
      int longitud = length(substring(s,posI,posF));
      cout<<"longitud: "<<longitud<<endl;
      for(i=0;i<=longitud;i++){
         s=removeAt(s,0);
      }
     
   }else{
      int posI = indexOfN(s, sep, i) ;
      int posF = indexOfN(s, sep, i+1);
      int longitud = length(substring(s,posI,posF));
      for(i=0;i<longitud;i++){
         s=removeAt(s,posI);
      }
   }
   
}

void setTokenAt(string &s, char sep, string t, int i)
   {string copy=s; 
    int rep=charCount(s,sep);
    s="";
   for(int j =0;j<=rep;j++){
      if (j!=i){
         string token=getTokenAt(copy,sep,j);
         addToken(s,sep,token);
      }
      else{
         addToken(s,sep,t);
      }
   }
  
}

int findToken(string s, char sep, string t)
{  int rep=charCount(s,sep);
   for(int i=0;i<rep;i++){
      string n=getTokenAt(s,sep,i);
      if(n==t){
         return i;
      }
   }
   return -1;
}

#endif
