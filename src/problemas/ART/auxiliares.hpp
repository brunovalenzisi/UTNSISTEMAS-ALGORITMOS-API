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


struct Fecha
{
	int dia;
	int anio;
	int mes;
};

struct Empresa
{
	int idEmpresa;
	char razonSocial[20];
	char cantTrabAsegurados;
};

struct EmpleadoAccidentado
{
	int legajo;
	int diasDeLicencia;
};

struct REmpresa
{
	Empresa empresa;
	Coll<EmpleadoAccidentado> collEmp;
	double porcentaje;
	int cantAccidentes;
};

struct Accidente
{
	int idEmpresa;
	int legajo;
	Fecha fecha;
	int cantDiasLicencia;
};

string fechaToString(Fecha x)
{
	char sep = 1;
	string sDia=to_string(x.dia);
	string sAnio=to_string(x.anio);
	string sMes=to_string(x.mes);
	return sDia+sep+sAnio+sep+sMes;
}

Fecha fechaFromString(string s)
{
	char sep = 1;
	Fecha x;
	string t0 = getTokenAt(s,sep,0);
	x.dia=stoi(t0);
	string t1 = getTokenAt(s,sep,1);
	x.anio=stoi(t1);
	string t2 = getTokenAt(s,sep,2);
	x.mes=stoi(t2);
	return x;
}

string fechaToDebug(Fecha x)
{
	stringstream sout;
	sout<< "[";
	sout << x.dia;
	sout << ",";
	sout << x.anio;
	sout << ",";
	sout << x.mes;
	sout<< "]";
	return sout.str();
}

string fechaToDebug(string mssg,Fecha x)
{
	stringstream sout;
	sout<< mssg<<":[";
	sout << x.dia;
	sout << ",";
	sout << x.anio;
	sout << ",";
	sout << x.mes;
	sout<< "]";
	return sout.str();
}

Fecha fecha(int dia,int anio,int mes)
{
	Fecha b;
	b.dia = dia;
	b.anio = anio;
	b.mes = mes;
	return b;
}

bool fechaEquals(Fecha a,Fecha b)
{
	if(a.dia!=b.dia) return false;
	if(a.anio!=b.anio) return false;
	if(a.mes!=b.mes) return false;
	return true;
}

string empresaToString(Empresa x)
{
	char sep = 2;
	string sIdEmpresa=to_string(x.idEmpresa);
	string sRazonSocial=x.razonSocial;
	string sCantTrabAsegurados=string(1,x.cantTrabAsegurados);
	return sIdEmpresa+sep+sRazonSocial+sep+sCantTrabAsegurados;
}

Empresa empresaFromString(string s)
{
	char sep = 2;
	Empresa x;
	string t0 = getTokenAt(s,sep,0);
	x.idEmpresa=stoi(t0);
	string t1 = getTokenAt(s,sep,1);
	strcpy(x.razonSocial,t1.c_str());
	string t2 = getTokenAt(s,sep,2);
	x.cantTrabAsegurados=(char)t2[0];
	return x;
}

string empresaToDebug(Empresa x)
{
	stringstream sout;
	sout<< "[";
	sout << x.idEmpresa;
	sout << ",";
	sout << x.razonSocial;
	sout << ",";
	sout << x.cantTrabAsegurados;
	sout<< "]";
	return sout.str();
}

string empresaToDebug(string mssg,Empresa x)
{
	stringstream sout;
	sout<< mssg<<":[";
	sout << x.idEmpresa;
	sout << ",";
	sout << x.razonSocial;
	sout << ",";
	sout << x.cantTrabAsegurados;
	sout<< "]";
	return sout.str();
}

Empresa empresa(int idEmpresa,string razonSocial,char cantTrabAsegurados)
{
	Empresa a;
	a.idEmpresa = idEmpresa;
	strcpy(a.razonSocial,razonSocial.c_str());
	a.cantTrabAsegurados = cantTrabAsegurados;
	return a;
}

bool empresaEquals(Empresa a,Empresa b)
{
	if(a.idEmpresa!=b.idEmpresa) return false;
	if(a.cantTrabAsegurados!=b.cantTrabAsegurados) return false;
	return true;
}

string empleadoAccidentadoToString(EmpleadoAccidentado x)
{
	char sep = 3;
	string sLegajo=to_string(x.legajo);
	string sDiasDeLicencia=to_string(x.diasDeLicencia);
	return sLegajo+sep+sDiasDeLicencia;
}

EmpleadoAccidentado empleadoAccidentadoFromString(string s)
{
	char sep = 3;
	EmpleadoAccidentado x;
	string t0 = getTokenAt(s,sep,0);
	x.legajo=stoi(t0);
	string t1 = getTokenAt(s,sep,1);
	x.diasDeLicencia=stoi(t1);
	return x;
}

string empleadoAccidentadoToDebug(EmpleadoAccidentado x)
{
	stringstream sout;
	sout<< "[";
	sout << x.legajo;
	sout << ",";
	sout << x.diasDeLicencia;
	sout<< "]";
	return sout.str();
}

string empleadoAccidentadoToDebug(string mssg,EmpleadoAccidentado x)
{
	stringstream sout;
	sout<< mssg<<":[";
	sout << x.legajo;
	sout << ",";
	sout << x.diasDeLicencia;
	sout<< "]";
	return sout.str();
}

EmpleadoAccidentado empleadoAccidentado(int legajo,int diasDeLicencia)
{
	EmpleadoAccidentado a;
	a.legajo = legajo;
	a.diasDeLicencia = diasDeLicencia;
	return a;
}

bool empleadoAccidentadoEquals(EmpleadoAccidentado a,EmpleadoAccidentado b)
{
	if(a.legajo!=b.legajo) return false;
	if(a.diasDeLicencia!=b.diasDeLicencia) return false;
	return true;
}

string rEmpresaToString(REmpresa x)
{
	char sep = 4;
	string sEmpresa=empresaToString(x.empresa);
	string sCollEmp=collToString<EmpleadoAccidentado>(x.collEmp);
	string sPorcentaje=to_string(x.porcentaje);
	string sCantAccidentes=to_string(x.cantAccidentes);
	return sEmpresa+sep+sCollEmp+sep+sPorcentaje+sep+sCantAccidentes;
}

REmpresa rEmpresaFromString(string s)
{
	char sep = 4;
	REmpresa x;
	string t0 = getTokenAt(s,sep,0);
	x.empresa=empresaFromString(t0);
	string t1 = getTokenAt(s,sep,1);
	x.collEmp=collFromString<EmpleadoAccidentado>(t1);
	string t2 = getTokenAt(s,sep,2);
	x.porcentaje=stod(t2);
	string t3 = getTokenAt(s,sep,3);
	x.cantAccidentes=stoi(t3);
	return x;
}

string rEmpresaToDebug(REmpresa x)
{
	stringstream sout;
	sout<< "[";
	sout << empresaToDebug(x.empresa);
	sout << ",";
	collReset<EmpleadoAccidentado>(x.collEmp);
	int n=collSize<EmpleadoAccidentado>(x.collEmp);
	sout << "{";
	for(int i=0; i<n; i++)
	{
		EmpleadoAccidentado q = collGetAt<EmpleadoAccidentado>(x.collEmp,i,empleadoAccidentadoFromString);
		sout << empleadoAccidentadoToDebug(q) << ((i<n-1)?",":"");
	}
	sout << "}";
	sout << ",";
	sout << x.porcentaje;
	sout << ",";
	sout << x.cantAccidentes;
	sout<< "]";
	return sout.str();
}

string rEmpresaToDebug(string mssg,REmpresa x)
{
	stringstream sout;
	sout<< mssg<<":[";
	sout << empresaToDebug(x.empresa);
	sout << ",";
	collReset<EmpleadoAccidentado>(x.collEmp);
	int n=collSize<EmpleadoAccidentado>(x.collEmp);
	sout << "{";
	for(int i=0; i<n; i++)
	{
		EmpleadoAccidentado q = collGetAt<EmpleadoAccidentado>(x.collEmp,i,empleadoAccidentadoFromString);
		sout << empleadoAccidentadoToDebug(q) << ((i<n-1)?",":"");
	}
	sout << "}";
	sout << ",";
	sout << x.porcentaje;
	sout << ",";
	sout << x.cantAccidentes;
	sout<< "]";
	return sout.str();
}

REmpresa rEmpresa(Empresa empresa,Coll<EmpleadoAccidentado> collEmp,double porcentaje,int cantAccidentes)
{
	REmpresa a;
	a.empresa = empresa;
	a.collEmp = collEmp;
	a.porcentaje = porcentaje;
	a.cantAccidentes = cantAccidentes;
	return a;
}

bool rEmpresaEquals(REmpresa a,REmpresa b)
{
	if(!empresaEquals(a.empresa,b.empresa)) return false;
	if(collToString<EmpleadoAccidentado>(a.collEmp)!=collToString<EmpleadoAccidentado>(b.collEmp)) return false;
	if(a.porcentaje!=b.porcentaje) return false;
	if(a.cantAccidentes!=b.cantAccidentes) return false;
	return true;
}

string accidenteToString(Accidente x)
{
	char sep = 5;
	string sIdEmpresa=to_string(x.idEmpresa);
	string sLegajo=to_string(x.legajo);
	string sFecha=fechaToString(x.fecha);
	string sCantDiasLicencia=to_string(x.cantDiasLicencia);
	return sIdEmpresa+sep+sLegajo+sep+sFecha+sep+sCantDiasLicencia;
}

Accidente accidenteFromString(string s)
{
	char sep = 5;
	Accidente x;
	string t0 = getTokenAt(s,sep,0);
	x.idEmpresa=stoi(t0);
	string t1 = getTokenAt(s,sep,1);
	x.legajo=stoi(t1);
	string t2 = getTokenAt(s,sep,2);
	x.fecha=fechaFromString(t2);
	string t3 = getTokenAt(s,sep,3);
	x.cantDiasLicencia=stoi(t3);
	return x;
}

string accidenteToDebug(Accidente x)
{
	stringstream sout;
	sout<< "[";
	sout << x.idEmpresa;
	sout << ",";
	sout << x.legajo;
	sout << ",";
	sout << fechaToDebug(x.fecha);
	sout << ",";
	sout << x.cantDiasLicencia;
	sout<< "]";
	return sout.str();
}

string accidenteToDebug(string mssg,Accidente x)
{
	stringstream sout;
	sout<< mssg<<":[";
	sout << x.idEmpresa;
	sout << ",";
	sout << x.legajo;
	sout << ",";
	sout << fechaToDebug(x.fecha);
	sout << ",";
	sout << x.cantDiasLicencia;
	sout<< "]";
	return sout.str();
}

Accidente accidente(int idEmpresa,int legajo,Fecha fecha,int cantDiasLicencia)
{
	Accidente a;
	a.idEmpresa = idEmpresa;
	a.legajo = legajo;
	a.fecha = fecha;
	a.cantDiasLicencia = cantDiasLicencia;
	return a;
}

bool accidenteEquals(Accidente a,Accidente b)
{
	if(a.idEmpresa!=b.idEmpresa) return false;
	if(a.legajo!=b.legajo) return false;
	if(!fechaEquals(a.fecha,b.fecha)) return false;
	if(a.cantDiasLicencia!=b.cantDiasLicencia) return false;
	return true;
}

#endif