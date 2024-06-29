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

Coll<Producto> subirProducto(){
    Coll<Producto> coll;
    return coll;
}
Coll<RRubro> subirRubros(){
    Coll<RRubro> coll;
   return coll;
}

int cmpIdProducto(Producto producto,int idProducto){
return idProducto-producto.idProd;
}

int cmpIdRubro(RRubro rRubro,int idRubroProducto){
    return rRubro.r.idRub-idRubroProducto; 
}

double aplicarDescuento(RProducto rProd,Coll<RRubro>coll,int precio){
    int dto;
    int precioConDto;
    int idRubroProducto=rProd.producto.idRub;
    int posRubro=collFind<RRubro>(coll,idRubroProducto,cmpIdRubro,rRubroFromString);
    RRubro rRubroProducto=collGetAt(coll,posRubro,rRubroFromString);
    dto=rRubroProducto.r.promo;
    precioConDto = precio * (1 - dto / 100.0); 
    precioConDto = round(precioConDto * 100) / 100; //revisar
    
}



void mostrarTicket(Ticket t,Coll<RRubro> coll){ 
double total=0.0;
cout<<"Numero de ticket:" <<t.idTicket<<endl;
cout<<"Producto           Precio                    c/Dto.                    Cant.                    Total"<<endl;
for(int i=0;i<collSize<RProducto>(t.collProductos);i++){
    RProducto rProd =collGetAt<RProducto>(t.collProductos,i,rProductoFromString);
    double precioConDto=aplicarDescuento(rProd,coll,rProd.producto.precio);
    cout<<rProd.producto.descr;
    cout<<replicate(' ',5);
    cout<<rProd.producto.precio;
    cout<<replicate(' ',20-digitCount(rProd.producto.precio));
    cout<<precioConDto;
    cout<<replicate(' ',20-digitCount(precioConDto));
    cout<<rProd.cantidad;
    cout<<replicate(' ',20-digitCount(rProd.cantidad));
    cout<<rProd.cantidad*precioConDto<<endl;
    cout<<replicate(' ',73-digitCount(rProd.cantidad*precioConDto));
}
    cout<<"TOTAL: "<<total<<endl;
    cout<<"Ahorro por rubro:";
}


int main(){
   Coll<Ticket> collTikets;
   Coll<Producto> collProductos= subirProducto();
   Coll<RRubro>collrRubros=subirRubros();



   int idCli;
   cout << "Ingrese id de cliente"<<endl;
   cin >> idCli;

   while (idCli != 0)
   {

      Coll<RProducto> collRProductos;
      int nTicket=collSize<Ticket>(collTikets)+1;
      int idProd;
      cout << "ingrese id de producto"<<endl;
      cin >> idProd;

      while (idProd != 0)
       { 
        int cantidad;
        cout<<"ingrese cantidad"<<endl;
        cin>>cantidad;
        int posProducto=collFind<Producto>(collProductos,idProd,cmpIdProducto,productoFromString);
        if(posProducto<0){
            cout<<"XXXXXXXXX Producto no encontrado, intente nuevamente XXXXXXXXX"<<endl;
            cout<< "Ingrese id de producto"<<endl;
            cin >> idProd;
        }
        else{
        Producto prod=collGetAt<Producto>(collProductos,posProducto,productoFromString);
        RProducto rProd= rProducto(prod,cantidad);
        collAdd<RProducto>(collRProductos,rProd,rProductoToString);
        cout<< "Ingrese id de producto"<<endl;
        cin >> idProd;

        }
      }

      Ticket t = ticket(nTicket,idCli,collRProductos);
      collAdd<Ticket>(collTikets,t,ticketToString);
      mostrarTicket(t,collrRubros);
      cout << "Ingrese id Cliente"<<endl;
      cin >> idCli;
   }

   return 0;
}

#endif










