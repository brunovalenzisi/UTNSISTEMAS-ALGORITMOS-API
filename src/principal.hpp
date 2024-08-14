#ifndef _MAINHPP
#define _MAINHPP
#include <iostream>
#include <iostream>
#include <sstream>
#include <string>
#include <string.h>
#include <stdlib.h>
#include "biblioteca/funciones/strings.hpp"
#include "biblioteca/funciones/tokens.hpp"
#include "biblioteca/tads/parte1/Coll.hpp"
using namespace std;

struct Registro
{
   string palabra;
   int pos;
};

struct SRegistro
{
   char palabra[20];
   int pos;
};

SRegistro sRegistro(string s,int pos){
   SRegistro sR;
   strcpy(sR.palabra,s.c_str());
   sR.pos=pos;
   return sR;
}

string sRegistroToString(SRegistro x)
{
	char sep = 2;
	string sPalabra=x.palabra;
	string sPos=to_string(x.pos);
	return sPalabra+sep+sPos;
}

SRegistro sRegistroFromString(string s)
{
	char sep = 2;
	SRegistro x;
	string t0 = getTokenAt(s,sep,0);
	strcpy(x.palabra,t0.c_str());
	string t1 = getTokenAt(s,sep,1);
	x.pos=stoi(t1);
	return x;
}

string sRegistroToDebug(SRegistro x)
{
	stringstream sout;
	sout<< "[";
	sout << x.palabra;
	sout << ",";
	sout << x.pos;
	sout<< "]";
	return sout.str();
}


string registroToString(Registro x)
{
   char sep = 1;
   string sPalabra=x.palabra;
   string sPos=to_string(x.pos);
   return sPalabra+sep+sPos;
}

Registro registroFromString(string s)
{
   char sep = 1;
   Registro x;
   string t0 = getTokenAt(s,sep,0);
   x.palabra=t0;
   string t1 = getTokenAt(s,sep,1);
   x.pos=stoi(t1);
   return x;
}

string registroToDebug(Registro x)
{
   stringstream sout;
   sout<< "[";
   sout << x.palabra;
   sout << ",";
   sout << x.pos;
   sout<< "]";
   return sout.str();
}

string registroToDebug(string mssg,Registro x)
{
   stringstream sout;
   sout<< mssg<<":[";
   sout << x.palabra;
   sout << ",";
   sout << x.pos;
   sout<< "]";
   return sout.str();
}

Registro registro(string palabra,int pos)
{
   Registro a;
   a.palabra = palabra;
   a.pos = pos;
   return a;
}

#endif
