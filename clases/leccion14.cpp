//estructura de datos: conjunto de datos
//estructuras dinamicas: de tamanio variable
//estructura estatica: tamanio  fijo

//NODO: es una estructura que contiene un puntero a otra estructura de su mismo tipo
//Los nodos me permiten tener ligada una estructura de datos no indexadas.(los arrays si son indexados)
// el tamanio de un puntero siempre es 4 bytes
struct Nodo{
int info;
Nodo* sig;
};


//Lista enlazada: es una lista de nodos enlazados.
//para iterar una estructura de nodos debo crear un puntero auxilirar para no perder la direccion del primer nodo(perderia la lista)



//PILA: stack: 
//LIFO last in first out. el ultimo elemento que entra es el primero que sale.
//son estructuras de datos restrictivas. me restrinjo en la manera de entrar y sacar datos.
//los metodos clave son push y pop.


//estructura COLA.
//FIFO first in first out.
//operaciones basicas: dequeue, enqueue