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
struct Tarea{
int fecha;
int horas;
char descripcionTarea[200];
};

struct REmpleado{
Empleado empleado;
Coll<Tarea> collTareas;
int horasProyecto;
};

struct RProyecto{
Proyecto proyecto;
Coll<REmpleado> collREmpleados;
};

#endif