#ifndef _MAIN
#define _MAIN

#include <iostream>
#include "../../biblioteca/funciones/strings.hpp"
#include "../../biblioteca/funciones/tokens.hpp"
#include "../../biblioteca/funciones/files.hpp"
#include "../../biblioteca/tads/parte2/Array.hpp"
#include "../../biblioteca/tads/parte2/Map.hpp"
#include "../../biblioteca/tads/parte2/List.hpp"
#include "../../biblioteca/tads/parte2/Stack.hpp"
#include "../../biblioteca/tads/parte2/Queue.hpp"
#include "../../biblioteca/tads/parte1/Coll.hpp"
#include "../../biblioteca/tads/parte1/MultidimColl.hpp"
#include "./auxiliares.hpp"
using namespace std;

void cargarAlumnos(Map<int,RCurso> rCursos){
FILE* f =fopen("ALUMNOS.dat","r+b");
Alumno a=read<Alumno>(f);
while(!feof(f)){
    RAlumno rA;
    rA.a=a;
    RCurso* rC=mapGet<int,RCurso>(rCursos,a.idCur);
    mapPut<int,RAlumno>(rC->rAlumnos,a.idAlu,rA);
    a=read<Alumno>(f);
}
};

Map<int,RCurso> crearRcursos(){
Map<int,RCurso> rCursos;
FILE* f =fopen("CURSOS.dat","r+b");
Curso c =read<Curso>(f);
while(!feof(f)){
RCurso rC;
rC.c=c;
mapPut<int,RCurso>(rCursos,c.idCur,rC);
c=read<Curso>(f);
}
cargarAlumnos(rCursos);
return rCursos;
}



    


int main(){
    Map<int,RCurso> rCursos=crearRcursos();



return 0;

}


#endif