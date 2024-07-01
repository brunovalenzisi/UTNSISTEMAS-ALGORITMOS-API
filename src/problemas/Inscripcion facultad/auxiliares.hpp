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


struct Inscripcion
{
	int idAlu;
	int idCur;
	int fecha;
};

struct Curso
{
	int idCur;
	char turno;
	int cap;
	char materia[20];
};

struct Revision
{
	int idAlu;
	char materia[20];
};

struct Reasignacion
{
	int idAlu;
	int idCurReasig;
};

struct Materia
{
	char nombre[20];
	Coll<Curso> cursosDisponibles;
};

struct Alumno
{
	int idAlu;
	Coll<Materia> materiasRechazadas;
};

string inscripcionToString(Inscripcion x)
{
	char sep = 1;
	string sIdAlu=to_string(x.idAlu);
	string sIdCur=to_string(x.idCur);
	string sFecha=to_string(x.fecha);
	return sIdAlu+sep+sIdCur+sep+sFecha;
}

Inscripcion inscripcionFromString(string s)
{
	char sep = 1;
	Inscripcion x;
	string t0 = getTokenAt(s,sep,0);
	x.idAlu=stoi(t0);
	string t1 = getTokenAt(s,sep,1);
	x.idCur=stoi(t1);
	string t2 = getTokenAt(s,sep,2);
	x.fecha=stoi(t2);
	return x;
}

string inscripcionToDebug(Inscripcion x)
{
	stringstream sout;
	sout<< "[";
	sout << x.idAlu;
	sout << ",";
	sout << x.idCur;
	sout << ",";
	sout << x.fecha;
	sout<< "]";
	return sout.str();
}

string inscripcionToDebug(string mssg,Inscripcion x)
{
	stringstream sout;
	sout<< mssg<<":[";
	sout << x.idAlu;
	sout << ",";
	sout << x.idCur;
	sout << ",";
	sout << x.fecha;
	sout<< "]";
	return sout.str();
}

Inscripcion inscripcion(int idAlu,int idCur,int fecha)
{
	Inscripcion a;
	a.idAlu = idAlu;
	a.idCur = idCur;
	a.fecha = fecha;
	return a;
}

bool inscripcionEquals(Inscripcion a,Inscripcion b)
{
	if(a.idAlu!=b.idAlu) return false;
	if(a.idCur!=b.idCur) return false;
	if(a.fecha!=b.fecha) return false;
	return true;
}

string cursoToString(Curso x)
{
	char sep = 2;
	string sIdCur=to_string(x.idCur);
	string sTurno=string(1,x.turno);
	string sCap=to_string(x.cap);
	string sMateria=x.materia;
	return sIdCur+sep+sTurno+sep+sCap+sep+sMateria;
}

Curso cursoFromString(string s)
{
	char sep = 2;
	Curso x;
	string t0 = getTokenAt(s,sep,0);
	x.idCur=stoi(t0);
	string t1 = getTokenAt(s,sep,1);
	x.turno=(char)t1[0];
	string t2 = getTokenAt(s,sep,2);
	x.cap=stoi(t2);
	string t3 = getTokenAt(s,sep,3);
	strcpy(x.materia,t3.c_str());
	return x;
}

string cursoToDebug(Curso x)
{
	stringstream sout;
	sout<< "[";
	sout << x.idCur;
	sout << ",";
	sout << x.turno;
	sout << ",";
	sout << x.cap;
	sout << ",";
	sout << x.materia;
	sout<< "]";
	return sout.str();
}

string cursoToDebug(string mssg,Curso x)
{
	stringstream sout;
	sout<< mssg<<":[";
	sout << x.idCur;
	sout << ",";
	sout << x.turno;
	sout << ",";
	sout << x.cap;
	sout << ",";
	sout << x.materia;
	sout<< "]";
	return sout.str();
}

Curso curso(int idCur,char turno,int cap,string materia)
{
	Curso a;
	a.idCur = idCur;
	a.turno = turno;
	a.cap = cap;
	strcpy(a.materia,materia.c_str());
	return a;
}

bool cursoEquals(Curso a,Curso b)
{
	if(a.idCur!=b.idCur) return false;
	if(a.turno!=b.turno) return false;
	if(a.cap!=b.cap) return false;
	return true;
}

string revisionToString(Revision x)
{
	char sep = 3;
	string sIdAlu=to_string(x.idAlu);
	string sMateria=x.materia;
	return sIdAlu+sep+sMateria;
}

Revision revisionFromString(string s)
{
	char sep = 3;
	Revision x;
	string t0 = getTokenAt(s,sep,0);
	x.idAlu=stoi(t0);
	string t1 = getTokenAt(s,sep,1);
	strcpy(x.materia,t1.c_str());
	return x;
}

string revisionToDebug(Revision x)
{
	stringstream sout;
	sout<< "[";
	sout << x.idAlu;
	sout << ",";
	sout << x.materia;
	sout<< "]";
	return sout.str();
}

string revisionToDebug(string mssg,Revision x)
{
	stringstream sout;
	sout<< mssg<<":[";
	sout << x.idAlu;
	sout << ",";
	sout << x.materia;
	sout<< "]";
	return sout.str();
}

Revision revision(int idAlu,string materia)
{
	Revision a;
	a.idAlu = idAlu;
	strcpy(a.materia,materia.c_str());
	return a;
}

bool revisionEquals(Revision a,Revision b)
{
	if(a.idAlu!=b.idAlu) return false;
	return true;
}

string reasignacionToString(Reasignacion x)
{
	char sep = 4;
	string sIdAlu=to_string(x.idAlu);
	string sIdCurReasig=to_string(x.idCurReasig);
	return sIdAlu+sep+sIdCurReasig;
}

Reasignacion reasignacionFromString(string s)
{
	char sep = 4;
	Reasignacion x;
	string t0 = getTokenAt(s,sep,0);
	x.idAlu=stoi(t0);
	string t1 = getTokenAt(s,sep,1);
	x.idCurReasig=stoi(t1);
	return x;
}

string reasignacionToDebug(Reasignacion x)
{
	stringstream sout;
	sout<< "[";
	sout << x.idAlu;
	sout << ",";
	sout << x.idCurReasig;
	sout<< "]";
	return sout.str();
}

string reasignacionToDebug(string mssg,Reasignacion x)
{
	stringstream sout;
	sout<< mssg<<":[";
	sout << x.idAlu;
	sout << ",";
	sout << x.idCurReasig;
	sout<< "]";
	return sout.str();
}

Reasignacion reasignacion(int idAlu,int idCurReasig)
{
	Reasignacion a;
	a.idAlu = idAlu;
	a.idCurReasig = idCurReasig;
	return a;
}

bool reasignacionEquals(Reasignacion a,Reasignacion b)
{
	if(a.idAlu!=b.idAlu) return false;
	if(a.idCurReasig!=b.idCurReasig) return false;
	return true;
}

string materiaToString(Materia x)
{
	char sep = 5;
	string sNombre=x.nombre;
	string sCursosDisponibles=collToString<Curso>(x.cursosDisponibles);
	return sNombre+sep+sCursosDisponibles;
}

Materia materiaFromString(string s)
{
	char sep = 5;
	Materia x;
	string t0 = getTokenAt(s,sep,0);
	strcpy(x.nombre,t0.c_str());
	string t1 = getTokenAt(s,sep,1);
	x.cursosDisponibles=collFromString<Curso>(t1);
	return x;
}

string materiaToDebug(Materia x)
{
	stringstream sout;
	sout<< "[";
	sout << x.nombre;
	sout << ",";
	collReset<Curso>(x.cursosDisponibles);
	int n=collSize<Curso>(x.cursosDisponibles);
	sout << "{";
	for(int i=0; i<n; i++)
	{
		Curso q = collGetAt<Curso>(x.cursosDisponibles,i,cursoFromString);
		sout << cursoToDebug(q) << ((i<n-1)?",":"");
	}
	sout << "}";
	sout<< "]";
	return sout.str();
}

string materiaToDebug(string mssg,Materia x)
{
	stringstream sout;
	sout<< mssg<<":[";
	sout << x.nombre;
	sout << ",";
	collReset<Curso>(x.cursosDisponibles);
	int n=collSize<Curso>(x.cursosDisponibles);
	sout << "{";
	for(int i=0; i<n; i++)
	{
		Curso q = collGetAt<Curso>(x.cursosDisponibles,i,cursoFromString);
		sout << cursoToDebug(q) << ((i<n-1)?",":"");
	}
	sout << "}";
	sout<< "]";
	return sout.str();
}

Materia materia(string nombre,Coll<Curso> cursosDisponibles)
{
	Materia a;
	strcpy(a.nombre,nombre.c_str());
	a.cursosDisponibles = cursosDisponibles;
	return a;
}

bool materiaEquals(Materia a,Materia b)
{
	if(collToString<Curso>(a.cursosDisponibles)!=collToString<Curso>(b.cursosDisponibles)) return false;
	return true;
}

string alumnoToString(Alumno x)
{
	char sep = 6;
	string sIdAlu=to_string(x.idAlu);
	string sMateriasRechazadas=collToString<Materia>(x.materiasRechazadas);
	return sIdAlu+sep+sMateriasRechazadas;
}

Alumno alumnoFromString(string s)
{
	char sep = 6;
	Alumno x;
	string t0 = getTokenAt(s,sep,0);
	x.idAlu=stoi(t0);
	string t1 = getTokenAt(s,sep,1);
	x.materiasRechazadas=collFromString<Materia>(t1);
	return x;
}

string alumnoToDebug(Alumno x)
{
	stringstream sout;
	sout<< "[";
	sout << x.idAlu;
	sout << ",";
	collReset<Materia>(x.materiasRechazadas);
	int n=collSize<Materia>(x.materiasRechazadas);
	sout << "{";
	for(int i=0; i<n; i++)
	{
		Materia q = collGetAt<Materia>(x.materiasRechazadas,i,materiaFromString);
		sout << materiaToDebug(q) << ((i<n-1)?",":"");
	}
	sout << "}";
	sout<< "]";
	return sout.str();
}

string alumnoToDebug(string mssg,Alumno x)
{
	stringstream sout;
	sout<< mssg<<":[";
	sout << x.idAlu;
	sout << ",";
	collReset<Materia>(x.materiasRechazadas);
	int n=collSize<Materia>(x.materiasRechazadas);
	sout << "{";
	for(int i=0; i<n; i++)
	{
		Materia q = collGetAt<Materia>(x.materiasRechazadas,i,materiaFromString);
		sout << materiaToDebug(q) << ((i<n-1)?",":"");
	}
	sout << "}";
	sout<< "]";
	return sout.str();
}

Alumno alumno(int idAlu,Coll<Materia> materiasRechazadas)
{
	Alumno a;
	a.idAlu = idAlu;
	a.materiasRechazadas = materiasRechazadas;
	return a;
}

bool alumnoEquals(Alumno a,Alumno b)
{
	if(a.idAlu!=b.idAlu) return false;
	if(collToString<Materia>(a.materiasRechazadas)!=collToString<Materia>(b.materiasRechazadas)) return false;
	return true;
}


#endif