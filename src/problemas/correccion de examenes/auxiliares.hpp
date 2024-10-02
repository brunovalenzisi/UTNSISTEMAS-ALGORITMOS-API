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
#include "../../biblioteca/tads/parte2/Queue.hpp"
#include "../../biblioteca/tads/parte2/List.hpp"
#include "../../biblioteca/tads/parte2/Stack.hpp"
#include "../../biblioteca/tads/parte2/Map.hpp"
using namespace std;

struct Alumno
{
   int idAlu;
   int legajo;
   char nombre[50];
   int idCur;
};
struct RAlumno{
Alumno a;
int calificacion;
};

struct Curso
{
   int idCur; 
   char descr[10]; // K1027
   char turno; // 'M','T'... 
};

struct RCurso{
   Curso c;
   Map<int,RAlumno> rAlumnos;
};

struct Tema
{
   int idTema; 
   int idAfir;
   char tipoAfir;// 'T','P'
   char afir[250]; 
   char rta; // 'V', 'F'
};

struct Respuesta
{
   int idAlu; 
   char tipoAfir; // 'T' o 'P' 
   int idAfir; // 1 a 10
   char rta; // 'V' o 'F'  
   int idTema; // 1 a 5
};

struct TTema{
Map<int,Tema> temas;
};
int ttemaEvaluar(TTema t,List<Respuesta> lst){
   int nota;
   return nota;
}



#endif