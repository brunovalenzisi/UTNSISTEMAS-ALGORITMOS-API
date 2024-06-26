#ifndef _MAINHPP
#define _MAINHPP
#include <iostream>
#include <iostream>
#include <sstream>
#include <string>
#include <string.h>
#include <stdlib.h>
#include "../../biblioteca/funciones/strings.hpp"
#include "../../biblioteca/funciones/tokens.hpp"
#include "../../biblioteca/tads/parte1/Coll.hpp"
using namespace std;

struct Ciudad
{
   int idCiu;
   char descr[20];
   int millas;
};

struct RCiudad
{
   Ciudad c;
   int cant=0;
};

struct Vuelo
{
   int idVue;
   int cap;
   int idOri;
   int idDes;
};

struct RVuelo
{
   Vuelo v;
   int cant;
};

struct RCliente
{
   int idCli;
   int acum;
};

struct Reserva
{
   int idCli;
   int idVue;
   int cant;
};

string ciudadToString(Ciudad x)
{
   char sep = 1;
   string sIdCiu=to_string(x.idCiu);
   string sDescr=x.descr;
   string sMillas=to_string(x.millas);
   return sIdCiu+sep+sDescr+sep+sMillas;
}

Ciudad ciudadFromString(string s)
{
   char sep = 1;
   Ciudad x;
   string t0 = getTokenAt(s,sep,0);
   x.idCiu=stoi(t0);
   string t1 = getTokenAt(s,sep,1);
   strcpy(x.descr,t1.c_str());
   string t2 = getTokenAt(s,sep,2);
   x.millas=stoi(t2);
   return x;
}

string ciudadToDebug(Ciudad x)
{
   stringstream sout;
   sout<< "[";
   sout << x.idCiu;
   sout << ",";
   sout << x.descr;
   sout << ",";
   sout << x.millas;
   sout<< "]";
   return sout.str();
}

string ciudadToDebug(string mssg,Ciudad x)
{
   stringstream sout;
   sout<< mssg<<":[";
   sout << x.idCiu;
   sout << ",";
   sout << x.descr;
   sout << ",";
   sout << x.millas;
   sout<< "]";
   return sout.str();
}

Ciudad ciudad(int idCiu,string descr,int millas)
{
   Ciudad a;
   a.idCiu = idCiu;
   strcpy(a.descr,descr.c_str());
   a.millas = millas;
   return a;
}

string rCiudadToString(RCiudad x)
{
   char sep = 2;
   string sC=ciudadToString(x.c);
   string sCant=to_string(x.cant);
   return sC+sep+sCant;
}

RCiudad rCiudadFromString(string s)
{
   char sep = 2;
   RCiudad x;
   string t0 = getTokenAt(s,sep,0);
   x.c=ciudadFromString(t0);
   string t1 = getTokenAt(s,sep,1);
   x.cant=stoi(t1);
   return x;
}

string rCiudadToDebug(RCiudad x)
{
   stringstream sout;
   sout<< "[";
   sout << ciudadToDebug(x.c);
   sout << ",";
   sout << x.cant;
   sout<< "]";
   return sout.str();
}

string rCiudadToDebug(string mssg,RCiudad x)
{
   stringstream sout;
   sout<< mssg<<":[";
   sout << ciudadToDebug(x.c);
   sout << ",";
   sout << x.cant;
   sout<< "]";
   return sout.str();
}

RCiudad rCiudad(Ciudad c,int cant)
{
   RCiudad a;
   a.c = c;
   a.cant = cant;
   return a;
}

string vueloToString(Vuelo x)
{
   char sep = 3;
   string sIdVue=to_string(x.idVue);
   string sCap=to_string(x.cap);
   string sIdOri=to_string(x.idOri);
   string sIdDes=to_string(x.idDes);
   return sIdVue+sep+sCap+sep+sIdOri+sep+sIdDes;
}

Vuelo vueloFromString(string s)
{
   char sep = 3;
   Vuelo x;
   string t0 = getTokenAt(s,sep,0);
   x.idVue=stoi(t0);
   string t1 = getTokenAt(s,sep,1);
   x.cap=stoi(t1);
   string t2 = getTokenAt(s,sep,2);
   x.idOri=stoi(t2);
   string t3 = getTokenAt(s,sep,3);
   x.idDes=stoi(t3);
   return x;
}

string vueloToDebug(Vuelo x)
{
   stringstream sout;
   sout<< "[";
   sout << x.idVue;
   sout << ",";
   sout << x.cap;
   sout << ",";
   sout << x.idOri;
   sout << ",";
   sout << x.idDes;
   sout<< "]";
   return sout.str();
}

string vueloToDebug(string mssg,Vuelo x)
{
   stringstream sout;
   sout<< mssg<<":[";
   sout << x.idVue;
   sout << ",";
   sout << x.cap;
   sout << ",";
   sout << x.idOri;
   sout << ",";
   sout << x.idDes;
   sout<< "]";
   return sout.str();
}

Vuelo vuelo(int idVue,int cap,int idOri,int idDes)
{
   Vuelo a;
   a.idVue = idVue;
   a.cap = cap;
   a.idOri = idOri;
   a.idDes = idDes;
   return a;
}

string rVueloToString(RVuelo x)
{
   char sep = 4;
   string sV=vueloToString(x.v);
   string sCant=to_string(x.cant);
   return sV+sep+sCant;
}

RVuelo rVueloFromString(string s)
{
   char sep = 4;
   RVuelo x;
   string t0 = getTokenAt(s,sep,0);
   x.v=vueloFromString(t0);
   string t1 = getTokenAt(s,sep,1);
   x.cant=stoi(t1);
   return x;
}

string rVueloToDebug(RVuelo x)
{
   stringstream sout;
   sout<< "[";
   sout << vueloToDebug(x.v);
   sout << ",";
   sout << x.cant;
   sout<< "]";
   return sout.str();
}

string rVueloToDebug(string mssg,RVuelo x)
{
   stringstream sout;
   sout<< mssg<<":[";
   sout << vueloToDebug(x.v);
   sout << ",";
   sout << x.cant;
   sout<< "]";
   return sout.str();
}

RVuelo rVuelo(Vuelo v,int cant)
{
   RVuelo a;
   a.v = v;
   a.cant = cant;
   return a;
}

string rClienteToString(RCliente x)
{
   char sep = 5;
   string sIdCli=to_string(x.idCli);
   string sAcum=to_string(x.acum);
   return sIdCli+sep+sAcum;
}

RCliente rClienteFromString(string s)
{
   char sep = 5;
   RCliente x;
   string t0 = getTokenAt(s,sep,0);
   x.idCli=stoi(t0);
   string t1 = getTokenAt(s,sep,1);
   x.acum=stoi(t1);
   return x;
}

string rClienteToDebug(RCliente x)
{
   stringstream sout;
   sout<< "[";
   sout << x.idCli;
   sout << ",";
   sout << x.acum;
   sout<< "]";
   return sout.str();
}

string rClienteToDebug(string mssg,RCliente x)
{
   stringstream sout;
   sout<< mssg<<":[";
   sout << x.idCli;
   sout << ",";
   sout << x.acum;
   sout<< "]";
   return sout.str();
}

RCliente rCliente(int idCli,int acum)
{
   RCliente b;
   b.idCli = idCli;
   b.acum = acum;
   return b;
}

string reservaToString(Reserva x)
{
   char sep = 6;
   string sIdCli=to_string(x.idCli);
   string sIdVue=to_string(x.idVue);
   string sCant=to_string(x.cant);
   return sIdCli+sep+sIdVue+sep+sCant;
}

Reserva reservaFromString(string s)
{
   char sep = 6;
   Reserva x;
   string t0 = getTokenAt(s,sep,0);
   x.idCli=stoi(t0);
   string t1 = getTokenAt(s,sep,1);
   x.idVue=stoi(t1);
   string t2 = getTokenAt(s,sep,2);
   x.cant=stoi(t2);
   return x;
}

string reservaToDebug(Reserva x)
{
   stringstream sout;
   sout<< "[";
   sout << x.idCli;
   sout << ",";
   sout << x.idVue;
   sout << ",";
   sout << x.cant;
   sout<< "]";
   return sout.str();
}

string reservaToDebug(string mssg,Reserva x)
{
   stringstream sout;
   sout<< mssg<<":[";
   sout << x.idCli;
   sout << ",";
   sout << x.idVue;
   sout << ",";
   sout << x.cant;
   sout<< "]";
   return sout.str();
}

Reserva reserva(int idCli,int idVue,int cant)
{
   Reserva a;
   a.idCli = idCli;
   a.idVue = idVue;
   a.cant = cant;
   return a;
}

#endif