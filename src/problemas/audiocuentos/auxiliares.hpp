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


struct Reproduccion
{
	int idUsuario;
	int idCuento;
	int fecha;
	int minutos;
};

struct Cuento
{
	int idCuento;
	int idRelator;
	int idAutor;
	char titulo[50];
	int duracion;
};

struct Relator
{
	int idRelator;
	char nombre[50];
};

struct RCuento
{
	Cuento c;
	int repComp;
	int parcial75;
	int parcial50;
	int parcial25;
	int parcial0;
};

struct RRelator
{
	Relator r;
	int parcial75;
};

string reproduccionToString(Reproduccion x)
{
	char sep = 1;
	string sIdUsuario=to_string(x.idUsuario);
	string sIdCuento=to_string(x.idCuento);
	string sFecha=to_string(x.fecha);
	string sMinutos=to_string(x.minutos);
	return sIdUsuario+sep+sIdCuento+sep+sFecha+sep+sMinutos;
}

Reproduccion reproduccionFromString(string s)
{
	char sep = 1;
	Reproduccion x;
	string t0 = getTokenAt(s,sep,0);
	x.idUsuario=stoi(t0);
	string t1 = getTokenAt(s,sep,1);
	x.idCuento=stoi(t1);
	string t2 = getTokenAt(s,sep,2);
	x.fecha=stoi(t2);
	string t3 = getTokenAt(s,sep,3);
	x.minutos=stoi(t3);
	return x;
}

string reproduccionToDebug(Reproduccion x)
{
	stringstream sout;
	sout<< "[";
	sout << x.idUsuario;
	sout << ",";
	sout << x.idCuento;
	sout << ",";
	sout << x.fecha;
	sout << ",";
	sout << x.minutos;
	sout<< "]";
	return sout.str();
}

string reproduccionToDebug(string mssg,Reproduccion x)
{
	stringstream sout;
	sout<< mssg<<":[";
	sout << x.idUsuario;
	sout << ",";
	sout << x.idCuento;
	sout << ",";
	sout << x.fecha;
	sout << ",";
	sout << x.minutos;
	sout<< "]";
	return sout.str();
}

Reproduccion reproduccion(int idUsuario,int idCuento,int fecha,int minutos)
{
	Reproduccion a;
	a.idUsuario = idUsuario;
	a.idCuento = idCuento;
	a.fecha = fecha;
	a.minutos = minutos;
	return a;
}

bool reproduccionEquals(Reproduccion a,Reproduccion b)
{
	if(a.idUsuario!=b.idUsuario) return false;
	if(a.idCuento!=b.idCuento) return false;
	if(a.fecha!=b.fecha) return false;
	if(a.minutos!=b.minutos) return false;
	return true;
}

string cuentoToString(Cuento x)
{
	char sep = 2;
	string sIdCuento=to_string(x.idCuento);
	string sIdRelator=to_string(x.idRelator);
	string sIdAutor=to_string(x.idAutor);
	string sTitulo=x.titulo;
	string sDuracion=to_string(x.duracion);
	return sIdCuento+sep+sIdRelator+sep+sIdAutor+sep+sTitulo+sep+sDuracion;
}

Cuento cuentoFromString(string s)
{
	char sep = 2;
	Cuento x;
	string t0 = getTokenAt(s,sep,0);
	x.idCuento=stoi(t0);
	string t1 = getTokenAt(s,sep,1);
	x.idRelator=stoi(t1);
	string t2 = getTokenAt(s,sep,2);
	x.idAutor=stoi(t2);
	string t3 = getTokenAt(s,sep,3);
	strcpy(x.titulo,t3.c_str());
	string t4 = getTokenAt(s,sep,4);
	x.duracion=stoi(t4);
	return x;
}

string cuentoToDebug(Cuento x)
{
	stringstream sout;
	sout<< "[";
	sout << x.idCuento;
	sout << ",";
	sout << x.idRelator;
	sout << ",";
	sout << x.idAutor;
	sout << ",";
	sout << x.titulo;
	sout << ",";
	sout << x.duracion;
	sout<< "]";
	return sout.str();
}

string cuentoToDebug(string mssg,Cuento x)
{
	stringstream sout;
	sout<< mssg<<":[";
	sout << x.idCuento;
	sout << ",";
	sout << x.idRelator;
	sout << ",";
	sout << x.idAutor;
	sout << ",";
	sout << x.titulo;
	sout << ",";
	sout << x.duracion;
	sout<< "]";
	return sout.str();
}

Cuento cuento(int idCuento,int idRelator,int idAutor,string titulo,int duracion)
{
	Cuento a;
	a.idCuento = idCuento;
	a.idRelator = idRelator;
	a.idAutor = idAutor;
	strcpy(a.titulo,titulo.c_str());
	a.duracion = duracion;
	return a;
}

bool cuentoEquals(Cuento a,Cuento b)
{
	if(a.idCuento!=b.idCuento) return false;
	if(a.idRelator!=b.idRelator) return false;
	if(a.idAutor!=b.idAutor) return false;
	if(a.duracion!=b.duracion) return false;
	return true;
}

string relatorToString(Relator x)
{
	char sep = 3;
	string sIdRelator=to_string(x.idRelator);
	string sNombre=x.nombre;
	return sIdRelator+sep+sNombre;
}

Relator relatorFromString(string s)
{
	char sep = 3;
	Relator x;
	string t0 = getTokenAt(s,sep,0);
	x.idRelator=stoi(t0);
	string t1 = getTokenAt(s,sep,1);
	strcpy(x.nombre,t1.c_str());
	return x;
}

string relatorToDebug(Relator x)
{
	stringstream sout;
	sout<< "[";
	sout << x.idRelator;
	sout << ",";
	sout << x.nombre;
	sout<< "]";
	return sout.str();
}

string relatorToDebug(string mssg,Relator x)
{
	stringstream sout;
	sout<< mssg<<":[";
	sout << x.idRelator;
	sout << ",";
	sout << x.nombre;
	sout<< "]";
	return sout.str();
}

Relator relator(int idRelator,string nombre)
{
	Relator a;
	a.idRelator = idRelator;
	strcpy(a.nombre,nombre.c_str());
	return a;
}

bool relatorEquals(Relator a,Relator b)
{
	if(a.idRelator!=b.idRelator) return false;
	return true;
}

string rCuentoToString(RCuento x)
{
	char sep = 4;
	string sC=cuentoToString(x.c);
	string sRepComp=to_string(x.repComp);
	string sParcial75=to_string(x.parcial75);
	string sParcial50=to_string(x.parcial50);
	string sParcial25=to_string(x.parcial25);
	string sParcial0=to_string(x.parcial0);
	return sC+sep+sRepComp+sep+sParcial75+sep+sParcial50+sep+sParcial25+sep+sParcial0;
}

RCuento rCuentoFromString(string s)
{
	char sep = 4;
	RCuento x;
	string t0 = getTokenAt(s,sep,0);
	x.c=cuentoFromString(t0);
	string t1 = getTokenAt(s,sep,1);
	x.repComp=stoi(t1);
	string t2 = getTokenAt(s,sep,2);
	x.parcial75=stoi(t2);
	string t3 = getTokenAt(s,sep,3);
	x.parcial50=stoi(t3);
	string t4 = getTokenAt(s,sep,4);
	x.parcial25=stoi(t4);
	string t5 = getTokenAt(s,sep,5);
	x.parcial0=stoi(t5);
	return x;
}

string rCuentoToDebug(RCuento x)
{
	stringstream sout;
	sout<< "[";
	sout << cuentoToDebug(x.c);
	sout << ",";
	sout << x.repComp;
	sout << ",";
	sout << x.parcial75;
	sout << ",";
	sout << x.parcial50;
	sout << ",";
	sout << x.parcial25;
	sout << ",";
	sout << x.parcial0;
	sout<< "]";
	return sout.str();
}

string rCuentoToDebug(string mssg,RCuento x)
{
	stringstream sout;
	sout<< mssg<<":[";
	sout << cuentoToDebug(x.c);
	sout << ",";
	sout << x.repComp;
	sout << ",";
	sout << x.parcial75;
	sout << ",";
	sout << x.parcial50;
	sout << ",";
	sout << x.parcial25;
	sout << ",";
	sout << x.parcial0;
	sout<< "]";
	return sout.str();
}

RCuento rCuento(Cuento c,int repComp,int parcial75,int parcial50,int parcial25,int parcial0)
{
	RCuento a;
	a.c = c;
	a.repComp = repComp;
	a.parcial75 = parcial75;
	a.parcial50 = parcial50;
	a.parcial25 = parcial25;
	a.parcial0 = parcial0;
	return a;
}

bool rCuentoEquals(RCuento a,RCuento b)
{
	if(!cuentoEquals(a.c,b.c)) return false;
	if(a.repComp!=b.repComp) return false;
	if(a.parcial75!=b.parcial75) return false;
	if(a.parcial50!=b.parcial50) return false;
	if(a.parcial25!=b.parcial25) return false;
	if(a.parcial0!=b.parcial0) return false;
	return true;
}

string rRelatorToString(RRelator x)
{
	char sep = 5;
	string sR=relatorToString(x.r);
	string sParcial75=to_string(x.parcial75);
	return sR+sep+sParcial75;
}

RRelator rRelatorFromString(string s)
{
	char sep = 5;
	RRelator x;
	string t0 = getTokenAt(s,sep,0);
	x.r=relatorFromString(t0);
	string t1 = getTokenAt(s,sep,1);
	x.parcial75=stoi(t1);
	return x;
}

string rRelatorToDebug(RRelator x)
{
	stringstream sout;
	sout<< "[";
	sout << relatorToDebug(x.r);
	sout << ",";
	sout << x.parcial75;
	sout<< "]";
	return sout.str();
}

string rRelatorToDebug(string mssg,RRelator x)
{
	stringstream sout;
	sout<< mssg<<":[";
	sout << relatorToDebug(x.r);
	sout << ",";
	sout << x.parcial75;
	sout<< "]";
	return sout.str();
}

RRelator rRelator(Relator r,int parcial75)
{
	RRelator a;
	a.r = r;
	a.parcial75 = parcial75;
	return a;
}

bool rRelatorEquals(RRelator a,RRelator b)
{
	if(!relatorEquals(a.r,b.r)) return false;
	if(a.parcial75!=b.parcial75) return false;
	return true;
}




#endif