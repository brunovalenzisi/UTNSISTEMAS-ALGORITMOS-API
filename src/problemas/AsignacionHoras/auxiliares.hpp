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

struct Proyecto
{
	int idProyecto;
	char descripcion[100];
	int fechaInicio;
	int horasAsignadas;
	int horasImputadas;
};

struct Hora
{
	int idEmpleado;
	int idProyecto;
	int fecha;
	int horas;
	char tareas[200];
};

struct Empleado
{
	int idEmpleado;
	char nombre[50];
};

struct Tarea
{
	int fecha;
	int horas;
	char descripcionTarea[200];
};

struct REmpleado
{
	Empleado empleado;
	Coll<Tarea> collTareas;
	int horasProyecto;
};

struct RProyecto
{
	Proyecto proyecto;
	Coll<REmpleado> collREmpleados;
};

string proyectoToString(Proyecto x)
{
	char sep = 1;
	string sIdProyecto=to_string(x.idProyecto);
	string sDescripcion=x.descripcion;
	string sFechaInicio=to_string(x.fechaInicio);
	string sHorasAsignadas=to_string(x.horasAsignadas);
	string sHorasImputadas=to_string(x.horasImputadas);
	return sIdProyecto+sep+sDescripcion+sep+sFechaInicio+sep+sHorasAsignadas+sep+sHorasImputadas;
}

Proyecto proyectoFromString(string s)
{
	char sep = 1;
	Proyecto x;
	string t0 = getTokenAt(s,sep,0);
	x.idProyecto=stoi(t0);
	string t1 = getTokenAt(s,sep,1);
	strcpy(x.descripcion,t1.c_str());
	string t2 = getTokenAt(s,sep,2);
	x.fechaInicio=stoi(t2);
	string t3 = getTokenAt(s,sep,3);
	x.horasAsignadas=stoi(t3);
	string t4 = getTokenAt(s,sep,4);
	x.horasImputadas=stoi(t4);
	return x;
}

string proyectoToDebug(Proyecto x)
{
	stringstream sout;
	sout<< "[";
	sout << x.idProyecto;
	sout << ",";
	sout << x.descripcion;
	sout << ",";
	sout << x.fechaInicio;
	sout << ",";
	sout << x.horasAsignadas;
	sout << ",";
	sout << x.horasImputadas;
	sout<< "]";
	return sout.str();
}

string proyectoToDebug(string mssg,Proyecto x)
{
	stringstream sout;
	sout<< mssg<<":[";
	sout << x.idProyecto;
	sout << ",";
	sout << x.descripcion;
	sout << ",";
	sout << x.fechaInicio;
	sout << ",";
	sout << x.horasAsignadas;
	sout << ",";
	sout << x.horasImputadas;
	sout<< "]";
	return sout.str();
}

Proyecto proyecto(int idProyecto,string descripcion,int fechaInicio,int horasAsignadas,int horasImputadas)
{
	Proyecto a;
	a.idProyecto = idProyecto;
	strcpy(a.descripcion,descripcion.c_str());
	a.fechaInicio = fechaInicio;
	a.horasAsignadas = horasAsignadas;
	a.horasImputadas = horasImputadas;
	return a;
}

bool proyectoEquals(Proyecto a,Proyecto b)
{
	if(a.idProyecto!=b.idProyecto) return false;
	if(a.fechaInicio!=b.fechaInicio) return false;
	if(a.horasAsignadas!=b.horasAsignadas) return false;
	if(a.horasImputadas!=b.horasImputadas) return false;
	return true;
}

string horaToString(Hora x)
{
	char sep = 2;
	string sIdEmpleado=to_string(x.idEmpleado);
	string sIdProyecto=to_string(x.idProyecto);
	string sFecha=to_string(x.fecha);
	string sHoras=to_string(x.horas);
	string sTareas=x.tareas;
	return sIdEmpleado+sep+sIdProyecto+sep+sFecha+sep+sHoras+sep+sTareas;
}

Hora horaFromString(string s)
{
	char sep = 2;
	Hora x;
	string t0 = getTokenAt(s,sep,0);
	x.idEmpleado=stoi(t0);
	string t1 = getTokenAt(s,sep,1);
	x.idProyecto=stoi(t1);
	string t2 = getTokenAt(s,sep,2);
	x.fecha=stoi(t2);
	string t3 = getTokenAt(s,sep,3);
	x.horas=stoi(t3);
	string t4 = getTokenAt(s,sep,4);
	strcpy(x.tareas,t4.c_str());
	return x;
}

string horaToDebug(Hora x)
{
	stringstream sout;
	sout<< "[";
	sout << x.idEmpleado;
	sout << ",";
	sout << x.idProyecto;
	sout << ",";
	sout << x.fecha;
	sout << ",";
	sout << x.horas;
	sout << ",";
	sout << x.tareas;
	sout<< "]";
	return sout.str();
}

string horaToDebug(string mssg,Hora x)
{
	stringstream sout;
	sout<< mssg<<":[";
	sout << x.idEmpleado;
	sout << ",";
	sout << x.idProyecto;
	sout << ",";
	sout << x.fecha;
	sout << ",";
	sout << x.horas;
	sout << ",";
	sout << x.tareas;
	sout<< "]";
	return sout.str();
}

Hora hora(int idEmpleado,int idProyecto,int fecha,int horas,string tareas)
{
	Hora a;
	a.idEmpleado = idEmpleado;
	a.idProyecto = idProyecto;
	a.fecha = fecha;
	a.horas = horas;
	strcpy(a.tareas,tareas.c_str());
	return a;
}

bool horaEquals(Hora a,Hora b)
{
	if(a.idEmpleado!=b.idEmpleado) return false;
	if(a.idProyecto!=b.idProyecto) return false;
	if(a.fecha!=b.fecha) return false;
	if(a.horas!=b.horas) return false;
	return true;
}

string empleadoToString(Empleado x)
{
	char sep = 3;
	string sIdEmpleado=to_string(x.idEmpleado);
	string sNombre=x.nombre;
	return sIdEmpleado+sep+sNombre;
}

Empleado empleadoFromString(string s)
{
	char sep = 3;
	Empleado x;
	string t0 = getTokenAt(s,sep,0);
	x.idEmpleado=stoi(t0);
	string t1 = getTokenAt(s,sep,1);
	strcpy(x.nombre,t1.c_str());
	return x;
}

string empleadoToDebug(Empleado x)
{
	stringstream sout;
	sout<< "[";
	sout << x.idEmpleado;
	sout << ",";
	sout << x.nombre;
	sout<< "]";
	return sout.str();
}

string empleadoToDebug(string mssg,Empleado x)
{
	stringstream sout;
	sout<< mssg<<":[";
	sout << x.idEmpleado;
	sout << ",";
	sout << x.nombre;
	sout<< "]";
	return sout.str();
}

Empleado empleado(int idEmpleado,string nombre)
{
	Empleado a;
	a.idEmpleado = idEmpleado;
	strcpy(a.nombre,nombre.c_str());
	return a;
}

bool empleadoEquals(Empleado a,Empleado b)
{
	if(a.idEmpleado!=b.idEmpleado) return false;
	return true;
}

string tareaToString(Tarea x)
{
	char sep = 4;
	string sFecha=to_string(x.fecha);
	string sHoras=to_string(x.horas);
	string sDescripcionTarea=x.descripcionTarea;
	return sFecha+sep+sHoras+sep+sDescripcionTarea;
}

Tarea tareaFromString(string s)
{
	char sep = 4;
	Tarea x;
	string t0 = getTokenAt(s,sep,0);
	x.fecha=stoi(t0);
	string t1 = getTokenAt(s,sep,1);
	x.horas=stoi(t1);
	string t2 = getTokenAt(s,sep,2);
	strcpy(x.descripcionTarea,t2.c_str());
	return x;
}

string tareaToDebug(Tarea x)
{
	stringstream sout;
	sout<< "[";
	sout << x.fecha;
	sout << ",";
	sout << x.horas;
	sout << ",";
	sout << x.descripcionTarea;
	sout<< "]";
	return sout.str();
}

string tareaToDebug(string mssg,Tarea x)
{
	stringstream sout;
	sout<< mssg<<":[";
	sout << x.fecha;
	sout << ",";
	sout << x.horas;
	sout << ",";
	sout << x.descripcionTarea;
	sout<< "]";
	return sout.str();
}

Tarea tarea(int fecha,int horas,string descripcionTarea)
{
	Tarea a;
	a.fecha = fecha;
	a.horas = horas;
	strcpy(a.descripcionTarea,descripcionTarea.c_str());
	return a;
}

bool tareaEquals(Tarea a,Tarea b)
{
	if(a.fecha!=b.fecha) return false;
	if(a.horas!=b.horas) return false;
	return true;
}

string rEmpleadoToString(REmpleado x)
{
	char sep = 5;
	string sEmpleado=empleadoToString(x.empleado);
	string sCollTareas=collToString<Tarea>(x.collTareas);
	string sHorasProyecto=to_string(x.horasProyecto);
	return sEmpleado+sep+sCollTareas+sep+sHorasProyecto;
}

REmpleado rEmpleadoFromString(string s)
{
	char sep = 5;
	REmpleado x;
	string t0 = getTokenAt(s,sep,0);
	x.empleado=empleadoFromString(t0);
	string t1 = getTokenAt(s,sep,1);
	x.collTareas=collFromString<Tarea>(t1);
	string t2 = getTokenAt(s,sep,2);
	x.horasProyecto=stoi(t2);
	return x;
}

string rEmpleadoToDebug(REmpleado x)
{
	stringstream sout;
	sout<< "[";
	sout << empleadoToDebug(x.empleado);
	sout << ",";
	collReset<Tarea>(x.collTareas);
	int n=collSize<Tarea>(x.collTareas);
	sout << "{";
	for(int i=0; i<n; i++)
	{
		Tarea q = collGetAt<Tarea>(x.collTareas,i,tareaFromString);
		sout << tareaToDebug(q) << ((i<n-1)?",":"");
	}
	sout << "}";
	sout << ",";
	sout << x.horasProyecto;
	sout<< "]";
	return sout.str();
}

string rEmpleadoToDebug(string mssg,REmpleado x)
{
	stringstream sout;
	sout<< mssg<<":[";
	sout << empleadoToDebug(x.empleado);
	sout << ",";
	collReset<Tarea>(x.collTareas);
	int n=collSize<Tarea>(x.collTareas);
	sout << "{";
	for(int i=0; i<n; i++)
	{
		Tarea q = collGetAt<Tarea>(x.collTareas,i,tareaFromString);
		sout << tareaToDebug(q) << ((i<n-1)?",":"");
	}
	sout << "}";
	sout << ",";
	sout << x.horasProyecto;
	sout<< "]";
	return sout.str();
}

REmpleado rEmpleado(Empleado empleado,Coll<Tarea> collTareas,int horasProyecto)
{
	REmpleado a;
	a.empleado = empleado;
	a.collTareas = collTareas;
	a.horasProyecto = horasProyecto;
	return a;
}

bool rEmpleadoEquals(REmpleado a,REmpleado b)
{
	if(!empleadoEquals(a.empleado,b.empleado)) return false;
	if(collToString<Tarea>(a.collTareas)!=collToString<Tarea>(b.collTareas)) return false;
	if(a.horasProyecto!=b.horasProyecto) return false;
	return true;
}

string rProyectoToString(RProyecto x)
{
	char sep = 6;
	string sProyecto=proyectoToString(x.proyecto);
	string sCollREmpleados=collToString<REmpleado>(x.collREmpleados);
	return sProyecto+sep+sCollREmpleados;
}

RProyecto rProyectoFromString(string s)
{
	char sep = 6;
	RProyecto x;
	string t0 = getTokenAt(s,sep,0);
	x.proyecto=proyectoFromString(t0);
	string t1 = getTokenAt(s,sep,1);
	x.collREmpleados=collFromString<REmpleado>(t1);
	return x;
}

string rProyectoToDebug(RProyecto x)
{
	stringstream sout;
	sout<< "[";
	sout << proyectoToDebug(x.proyecto);
	sout << ",";
	collReset<REmpleado>(x.collREmpleados);
	int n=collSize<REmpleado>(x.collREmpleados);
	sout << "{";
	for(int i=0; i<n; i++)
	{
		REmpleado q = collGetAt<REmpleado>(x.collREmpleados,i,rEmpleadoFromString);
		sout << rEmpleadoToDebug(q) << ((i<n-1)?",":"");
	}
	sout << "}";
	sout<< "]";
	return sout.str();
}

string rProyectoToDebug(string mssg,RProyecto x)
{
	stringstream sout;
	sout<< mssg<<":[";
	sout << proyectoToDebug(x.proyecto);
	sout << ",";
	collReset<REmpleado>(x.collREmpleados);
	int n=collSize<REmpleado>(x.collREmpleados);
	sout << "{";
	for(int i=0; i<n; i++)
	{
		REmpleado q = collGetAt<REmpleado>(x.collREmpleados,i,rEmpleadoFromString);
		sout << rEmpleadoToDebug(q) << ((i<n-1)?",":"");
	}
	sout << "}";
	sout<< "]";
	return sout.str();
}

RProyecto rProyecto(Proyecto proyecto,Coll<REmpleado> collREmpleados)
{
	RProyecto a;
	a.proyecto = proyecto;
	a.collREmpleados = collREmpleados;
	return a;
}

bool rProyectoEquals(RProyecto a,RProyecto b)
{
	if(!proyectoEquals(a.proyecto,b.proyecto)) return false;
	if(collToString<REmpleado>(a.collREmpleados)!=collToString<REmpleado>(b.collREmpleados)) return false;
	return true;
}

#endif