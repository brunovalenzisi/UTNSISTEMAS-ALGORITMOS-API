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

int cmpNombreMateria(Materia mat,char nombreMat[20]){
return mat.nombre-nombreMat;
}

Coll<Curso> cursosCargar(){
    Coll<Curso> coll;
    FILE* f=fopen("CURSOS.dat","r+b");
    Curso cur=read<Curso>(f);
    while(!feof(f)){
        collAdd<Curso>(coll,cur,cursoToString);
        cur=read<Curso>(f);
    }
    return coll;
};
Coll<Materia> materiasDescubrir(Coll<Curso> &collCur){
    Coll<Materia> coll;
    while(collHasNext(collCur)){
    Curso cur=collNext<Curso>(collCur,cursoFromString);
    int posMateria=collFind<Materia>(coll,cur.materia,cmpNombreMateria,materiaFromString);
    if(posMateria<0){
        Coll<Curso> collCursosVacia;
        collAdd<Curso>(collCursosVacia,cur,cursoToString);
        Materia nuevaMat=materia(cur.materia,collCursosVacia);
        collAdd<Materia>(coll,nuevaMat,materiaToString);
    }else{
        Materia matEncontrada = collGetAt<Materia>(coll,posMateria,materiaFromString);
        collAdd(matEncontrada.cursosDisponibles,cur,cursoToString);
    }
    }
    collReset(collCur);
    return coll;
};


int cmpIdCur(Curso cur,int idCur){
return cur.idCur-idCur;
}

int cmpIdAlu(Alumno alu,int idAlu){
return alu.idAlu-idAlu;
}

void inscribir(Inscripcion i,Coll<Curso> &collCur,Coll<Alumno> &collAlu,Coll<Materia> collMat){
    int posCurso=collFind<Curso>(collCur,i.idCur,cmpIdCur,cursoFromString);
    Curso cur=collGetAt<Curso>(collCur,posCurso,cursoFromString);
    if(cur.cap>0){
        cur.cap--;
        collSetAt<Curso>(collCur,cur,posCurso,cursoToString);
    }
    else{
        int posAlu=collFind<Alumno>(collAlu,i.idAlu,cmpIdAlu,alumnoFromString);
        Alumno alu=collGetAt<Alumno>(collAlu,posAlu,alumnoFromString);
        int posMateria=collFind<Materia>(collMat,cur.materia,cmpNombreMateria,materiaFromString);
        Materia mat=collGetAt<Materia>(collMat,posMateria,materiaFromString);
        collAdd<Materia>(alu.materiasRechazadas,mat,materiaToString);
        collSetAt<Alumno>(collAlu,alu,posAlu,alumnoToString);
    }

};

void actualizarCursosPorMateria(Coll<Curso> &collCur,Coll<Materia> &collMat){
    while(collHasNext(collMat)){
        Materia mat=collNext<Materia>(collMat,materiaFromString);
        while(collHasNext(collCur)){
            Curso cur=collNext<Curso>(collCur,cursoFromString);
            if(cur.materia==mat.nombre){
                if(cur.cap>0){
                    collAdd<Curso>(mat.cursosDisponibles,cur,cursoToString);
                }
            }
        }
        collReset(collCur);
    }
    collReset(collMat);
}

int main(){
    Coll<Curso> collCursos=cursosCargar();
    Coll<Materia> collMaterias = materiasDescubrir(collCursos);
//Aca hay bardo   
    Coll<Alumno> collAlumnos;
    FILE* f=fopen("INSCRIPCIONES.dat","w+b");
    Inscripcion ins=read<Inscripcion>(f);
    while(!feof(f)){
         
        inscribir(ins,collCursos,collAlumnos,collMaterias);
        actualizarCursosPorMateria(collCursos,collMaterias);
        


    }



    return 0;
}







#endif