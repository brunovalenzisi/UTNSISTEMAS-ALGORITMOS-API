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


Coll<RProyecto> cargarRProyectos(){
 Coll<RProyecto> coll;

 return coll;   

}
Coll <REmpleado> cargarREmpleados(){
Coll<REmpleado> coll;
return coll;
};


int cmpIdProyecto(RProyecto rP,int idP){
return rP.proyecto.idProyecto-idP;
};

int cmpIdEmpleado(REmpleado rEmp,int idEmp){
    return rEmp.empleado.idEmpleado-idEmp;
};

REmpleado asignarTarea(Tarea t,REmpleado &rEmp){
collAdd(rEmp.collTareas,t,tareaToString);
rEmp.horasProyecto+=t.horas;
return rEmp;
}


void procesarHora(Hora h,Coll<RProyecto> &collRProyectos,Coll<REmpleado> &collREmp){
    int posRProyecto=collFind<RProyecto,int>(collRProyectos,h.idProyecto,cmpIdProyecto,rProyectoFromString);
    RProyecto rProyecto=collGetAt<RProyecto>(collRProyectos,posRProyecto,rProyectoFromString);
    int posREmpleado=collFind<REmpleado>(rProyecto.collREmpleados,h.idEmpleado,cmpIdEmpleado,rEmpleadoFromString);
    Tarea nuevaTarea= tarea(h.fecha,h.horas,h.tareas);
    if(posREmpleado>=0){
    REmpleado rEmpleado=collGetAt<REmpleado>(rProyecto.collREmpleados,posREmpleado,rEmpleadoFromString);
    rEmpleado=asignarTarea(nuevaTarea,rEmpleado);
    collSetAt<REmpleado>(rProyecto.collREmpleados,rEmpleado,posREmpleado,rEmpleadoToString);
    }
    else{
        posREmpleado=collFind<REmpleado,int>(collREmp,h.idEmpleado,cmpIdEmpleado,rEmpleadoFromString);
        REmpleado rEmpleado=collGetAt<REmpleado>(collREmp,posREmpleado,rEmpleadoFromString);
        rEmpleado=asignarTarea(nuevaTarea,rEmpleado);
        collSetAt<REmpleado>(rProyecto.collREmpleados,rEmpleado,posREmpleado,rEmpleadoToString);
    }
    rProyecto.proyecto.horasImputadas+=h.horas;
    collSetAt<RProyecto>(collRProyectos,rProyecto,posRProyecto,rProyectoToString);
};

void mostrarAsignacion(Coll<RProyecto> coll){


};


int main()
{

    Coll<RProyecto> collRProyectos= cargarRProyectos();
    Coll<REmpleado> collREmpleados= cargarREmpleados();
    FILE* f= fopen("HORAS.dat","r+b");
    Hora h = read<Hora>(f);
    while(!feof(f)){
        procesarHora(h,collRProyectos,collREmpleados);
        h=read<Hora>(f); 
    }
    mostrarAsignacion(collRProyectos);

   return 0;
}

#endif