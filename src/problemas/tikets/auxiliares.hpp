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

struct Producto
{
	int idProd;
	char descr[20];
	double precio;
	int idRub;
};

struct RProducto
{
	Producto producto;
	int cantidad;
};

struct Rubro
{
	int idRub;
	char descr[20];
	double promo;
};

struct RRubro
{
	Rubro r;
	double ahorro;
};

struct Ticket
{
	int idTicket;
	int idCliente;
	Coll<RProducto> collProductos;
};

string productoToString(Producto x)
{
	char sep = 1;
	string sIdProd=to_string(x.idProd);
	string sDescr=x.descr;
	string sPrecio=to_string(x.precio);
	string sIdRub=to_string(x.idRub);
	return sIdProd+sep+sDescr+sep+sPrecio+sep+sIdRub;
}

Producto productoFromString(string s)
{
	char sep = 1;
	Producto x;
	string t0 = getTokenAt(s,sep,0);
	x.idProd=stoi(t0);
	string t1 = getTokenAt(s,sep,1);
	strcpy(x.descr,t1.c_str());
	string t2 = getTokenAt(s,sep,2);
	x.precio=stod(t2);
	string t3 = getTokenAt(s,sep,3);
	x.idRub=stoi(t3);
	return x;
}

string productoToDebug(Producto x)
{
	stringstream sout;
	sout<< "[";
	sout << x.idProd;
	sout << ",";
	sout << x.descr;
	sout << ",";
	sout << x.precio;
	sout << ",";
	sout << x.idRub;
	sout<< "]";
	return sout.str();
}

string productoToDebug(string mssg,Producto x)
{
	stringstream sout;
	sout<< mssg<<":[";
	sout << x.idProd;
	sout << ",";
	sout << x.descr;
	sout << ",";
	sout << x.precio;
	sout << ",";
	sout << x.idRub;
	sout<< "]";
	return sout.str();
}

Producto producto(int idProd,string descr,double precio,int idRub)
{
	Producto a;
	a.idProd = idProd;
	strcpy(a.descr,descr.c_str());
	a.precio = precio;
	a.idRub = idRub;
	return a;
}

bool productoEquals(Producto a,Producto b)
{
	if(a.idProd!=b.idProd) return false;
	if(a.precio!=b.precio) return false;
	if(a.idRub!=b.idRub) return false;
	return true;
}

string rProductoToString(RProducto x)
{
	char sep = 2;
	string sProducto=productoToString(x.producto);
	string sCantidad=to_string(x.cantidad);
	return sProducto+sep+sCantidad;
}

RProducto rProductoFromString(string s)
{
	char sep = 2;
	RProducto x;
	string t0 = getTokenAt(s,sep,0);
	x.producto=productoFromString(t0);
	string t1 = getTokenAt(s,sep,1);
	x.cantidad=stoi(t1);
	return x;
}

string rProductoToDebug(RProducto x)
{
	stringstream sout;
	sout<< "[";
	sout << productoToDebug(x.producto);
	sout << ",";
	sout << x.cantidad;
	sout<< "]";
	return sout.str();
}

string rProductoToDebug(string mssg,RProducto x)
{
	stringstream sout;
	sout<< mssg<<":[";
	sout << productoToDebug(x.producto);
	sout << ",";
	sout << x.cantidad;
	sout<< "]";
	return sout.str();
}

RProducto rProducto(Producto producto,int cantidad)
{
	RProducto a;
	a.producto = producto;
	a.cantidad = cantidad;
	return a;
}

bool rProductoEquals(RProducto a,RProducto b)
{
	if(!productoEquals(a.producto,b.producto)) return false;
	if(a.cantidad!=b.cantidad) return false;
	return true;
}

string rubroToString(Rubro x)
{
	char sep = 3;
	string sIdRub=to_string(x.idRub);
	string sDescr=x.descr;
	string sPromo=to_string(x.promo);
	return sIdRub+sep+sDescr+sep+sPromo;
}

Rubro rubroFromString(string s)
{
	char sep = 3;
	Rubro x;
	string t0 = getTokenAt(s,sep,0);
	x.idRub=stoi(t0);
	string t1 = getTokenAt(s,sep,1);
	strcpy(x.descr,t1.c_str());
	string t2 = getTokenAt(s,sep,2);
	x.promo=stod(t2);
	return x;
}

string rubroToDebug(Rubro x)
{
	stringstream sout;
	sout<< "[";
	sout << x.idRub;
	sout << ",";
	sout << x.descr;
	sout << ",";
	sout << x.promo;
	sout<< "]";
	return sout.str();
}

string rubroToDebug(string mssg,Rubro x)
{
	stringstream sout;
	sout<< mssg<<":[";
	sout << x.idRub;
	sout << ",";
	sout << x.descr;
	sout << ",";
	sout << x.promo;
	sout<< "]";
	return sout.str();
}

Rubro rubro(int idRub,string descr,double promo)
{
	Rubro a;
	a.idRub = idRub;
	strcpy(a.descr,descr.c_str());
	a.promo = promo;
	return a;
}

bool rubroEquals(Rubro a,Rubro b)
{
	if(a.idRub!=b.idRub) return false;
	if(a.promo!=b.promo) return false;
	return true;
}

string rRubroToString(RRubro x)
{
	char sep = 4;
	string sR=rubroToString(x.r);
	string sAhorro=to_string(x.ahorro);
	return sR+sep+sAhorro;
}

RRubro rRubroFromString(string s)
{
	char sep = 4;
	RRubro x;
	string t0 = getTokenAt(s,sep,0);
	x.r=rubroFromString(t0);
	string t1 = getTokenAt(s,sep,1);
	x.ahorro=stod(t1);
	return x;
}

string rRubroToDebug(RRubro x)
{
	stringstream sout;
	sout<< "[";
	sout << rubroToDebug(x.r);
	sout << ",";
	sout << x.ahorro;
	sout<< "]";
	return sout.str();
}

string rRubroToDebug(string mssg,RRubro x)
{
	stringstream sout;
	sout<< mssg<<":[";
	sout << rubroToDebug(x.r);
	sout << ",";
	sout << x.ahorro;
	sout<< "]";
	return sout.str();
}

RRubro rRubro(Rubro r,double ahorro)
{
	RRubro b;
	b.r = r;
	b.ahorro = ahorro;
	return b;
}

bool rRubroEquals(RRubro a,RRubro b)
{
	if(!rubroEquals(a.r,b.r)) return false;
	if(a.ahorro!=b.ahorro) return false;
	return true;
}

string ticketToString(Ticket x)
{
	char sep = 5;
	string sIdTicket=to_string(x.idTicket);
	string sIdCliente=to_string(x.idCliente);
	string sCollProductos=collToString<RProducto>(x.collProductos);
	return sIdTicket+sep+sIdCliente+sep+sCollProductos;
}

Ticket ticketFromString(string s)
{
	char sep = 5;
	Ticket x;
	string t0 = getTokenAt(s,sep,0);
	x.idTicket=stoi(t0);
	string t1 = getTokenAt(s,sep,1);
	x.idCliente=stoi(t1);
	string t2 = getTokenAt(s,sep,2);
	x.collProductos=collFromString<RProducto>(t2);
	return x;
}

string ticketToDebug(Ticket x)
{
	stringstream sout;
	sout<< "[";
	sout << x.idTicket;
	sout << ",";
	sout << x.idCliente;
	sout << ",";
	collReset<RProducto>(x.collProductos);
	int n=collSize<RProducto>(x.collProductos);
	sout << "{";
	for(int i=0; i<n; i++)
	{
		RProducto q = collGetAt<RProducto>(x.collProductos,i,rProductoFromString);
		sout << rProductoToDebug(q) << ((i<n-1)?",":"");
	}
	sout << "}";
	sout<< "]";
	return sout.str();
}

string ticketToDebug(string mssg,Ticket x)
{
	stringstream sout;
	sout<< mssg<<":[";
	sout << x.idTicket;
	sout << ",";
	sout << x.idCliente;
	sout << ",";
	collReset<RProducto>(x.collProductos);
	int n=collSize<RProducto>(x.collProductos);
	sout << "{";
	for(int i=0; i<n; i++)
	{
		RProducto q = collGetAt<RProducto>(x.collProductos,i,rProductoFromString);
		sout << rProductoToDebug(q) << ((i<n-1)?",":"");
	}
	sout << "}";
	sout<< "]";
	return sout.str();
}

Ticket ticket(int idTicket,int idCliente,Coll<RProducto> collProductos)
{
	Ticket a;
	a.idTicket = idTicket;
	a.idCliente = idCliente;
	a.collProductos = collProductos;
	return a;
}

bool ticketEquals(Ticket a,Ticket b)
{
	if(a.idTicket!=b.idTicket) return false;
	if(a.idCliente!=b.idCliente) return false;
	if(collToString<RProducto>(a.collProductos)!=collToString<RProducto>(b.collProductos)) return false;
	return true;
}

#endif