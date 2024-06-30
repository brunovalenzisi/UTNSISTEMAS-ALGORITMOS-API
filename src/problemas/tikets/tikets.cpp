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
    FILE* f=fopen("PRODUCTOS.dat","r+b");
    Producto producto=read<Producto>(f);
    while(!feof(f)){
    collAdd(coll,producto,productoToString);
    producto=read<Producto>(f);
    }
    Producto prod=collGetAt<Producto>(coll,0,productoFromString);
    fclose(f);
    return coll;
}
Coll<RRubro> subirRubros(){
    Coll<RRubro> coll;
    FILE* f=fopen("RUBROS.dat","r+b");
    Rubro rubro=read<Rubro>(f);
    while(!feof(f)){
    RRubro rRub= rRubro(rubro,0.0);
    collAdd<RRubro>(coll,rRub,rRubroToString);
    rubro=read<Rubro>(f);    
    }
    fclose(f);
    return coll;
}
 
int cmpIdProducto(Producto producto,int idProducto){
return idProducto-producto.idProd;
}
int cmpIdRProducto(RProducto rProducto,int idProducto){
return idProducto-rProducto.producto.idProd;
}

int cmpIdRubro(RRubro rRubro,int idRubroProducto){
    return rRubro.r.idRub-idRubroProducto; 
}

double aplicarDescuento(RProducto rProd,Coll<RRubro>& coll,int precio){
    int dto;
    double precioConDto;
    int idRubroProducto=rProd.producto.idRub;
    int posRubro=collFind<RRubro>(coll,idRubroProducto,cmpIdRubro,rRubroFromString);
  
    RRubro rRubroProducto=collGetAt(coll,posRubro,rRubroFromString);
    dto=rRubroProducto.r.promo;
    double descuentoUnitario=precio*dto/100.0;
    double dtoTotal=rProd.cantidad*descuentoUnitario;
    rRubroProducto.ahorro+=dtoTotal;
    collSetAt(coll,rRubroProducto,posRubro,rRubroToString);
    precioConDto = precio * (1 - dto / 100.0); 
    precioConDto = round(precioConDto * 100) / 100; 
    return precioConDto;
}



void mostrarTicket(Ticket t,Coll<RRubro> coll){ 
double total=0.0;
double ahorroTotal=0.0;
cout<<"Numero de ticket:" <<t.idTicket<<endl;
cout<<"Producto            Precio                    c/Dto.                    Cant.                    Total"<<endl;
for(int i=0;i<collSize<RProducto>(t.collProductos);i++){
    RProducto rProd =collGetAt<RProducto>(t.collProductos,i,rProductoFromString);
    double precioConDto=aplicarDescuento(rProd,coll,rProd.producto.precio);
    cout<<rProd.producto.descr;
    cout<<replicate(' ',13);
    cout<<rProd.producto.precio;
    cout<<replicate(' ',26-length(doubleToString(rProd.producto.precio))-1);
    cout<<precioConDto;
    cout<<replicate(' ',26-length(doubleToString(precioConDto))-1);
    cout<<rProd.cantidad;
    cout<<replicate(' ',24-length(doubleToString(rProd.cantidad))-1);
    cout<<rProd.cantidad*precioConDto<<endl;
    total+=rProd.cantidad*precioConDto;
}
    cout<<replicate(' ',93);
    cout<<"TOTAL: "<<total<<endl;
    cout<<"Ahorro por rubro:"<<endl;
    cout<<"Rubro:";
    cout<<replicate(' ',35);
    cout<<"Total:"<<endl;
    for(int i=0;i<collSize<RRubro>(coll);i++){
        RRubro rRubro=collGetAt<RRubro>(coll,i,rRubroFromString);
        cout<<rRubro.r.descr;
        cout<<replicate(' ',20);
        cout<<rRubro.ahorro<<endl;
        ahorroTotal+=rRubro.ahorro;
    }
    cout<<replicate(' ',33);
    cout<<"TOTAL: "<<ahorroTotal<<endl;
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
      int nTicket=collSize(collTikets)+1;
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
        int posRProducto=collFind<RProducto>(collRProductos,idProd,cmpIdRProducto,rProductoFromString);
        if(posRProducto<0){
        Producto prod=collGetAt<Producto>(collProductos,posProducto,productoFromString);
        RProducto rProd= rProducto(prod,cantidad);
        collAdd<RProducto>(collRProductos,rProd,rProductoToString);
        cout<< "Ingrese id de producto"<<endl;
        cin >> idProd;
        }
        else{
            RProducto rProd=collGetAt<RProducto>(collRProductos,posRProducto,rProductoFromString);
            rProd.cantidad+=cantidad;
            collSetAt<RProducto>(collRProductos,rProd,posRProducto,rProductoToString);
            cout<< "Ingrese id de producto"<<endl;
            cin >> idProd;
        }

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










