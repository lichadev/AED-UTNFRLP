#include <stdio.h>
#include <stdlib.h>

typedef struct Nodo{
  int cosa;
  struct Nodo *siguiente;
}Nodo;

typedef struct Cola{
  Nodo *primero;
  Nodo *ultimo;
}Cola;

void DestruirNodo(Nodo *nodo);
void DestruirCola(Cola *cola);
Nodo* CrearNodo(int dato);
Cola* CrearCola();
void Encolar(Cola *cola, int dato);
void Desencolar(Cola *cola);
int Consultar(Cola *cola);

int main(){
  Cola colaMain;
  return 0;
}

/*
  Creo el nodo y le asigno el dato.
*/
Nodo* CrearNodo(int dato){
  Nodo *nodo = malloc(sizeof(Nodo));
  nodo->siguiente = NULL;
  nodo->cosa = dato;
  return nodo;
}
/*
  Destruyo el nodo y hago NULL todo lo que el contiene
  para que no suceda ningun memory leak.
*/
void DestruirNodo(Nodo *nodo){
  nodo->cosa = NULL;
  nodo->siguiente = NULL;
  free(nodo);
}
/*
  Creo cola y seteo su primero y ultimo a NULL
*/
Cola* CrearCola(){
  Cola *cola = malloc(sizeof(Cola));
  cola->primero = NULL;
  cola->ultimo = NULL;
  return cola;
}
/*
  Para encolar verifico si el primero no existe, si sucede el nodo nuevo es el primero y el ultimo de la cola.
  Caso contrario, el siguiente del ultimo sera el nuevo nodo y el ultimo sera el nodo.
*/
void Encolar(Cola *cola, int dato){
  Nodo *nodo = CrearNodo(dato);

  if(cola->primero == NULL){
    cola->primero = nodo;
    cola->ultimo = nodo;
  } else {
    cola->ultimo->siguiente = nodo;
    cola->ultimo = nodo;
  }
}
void Desencolar(Cola *cola){
  if(cola->primero){
    Nodo *nodoBorrado = cola->primero;
    cola->primero = cola->primero->siguiente;
    DestruirNodo(nodoBorrado);
    if(cola->primero == NULL){
      cola->ultimo = NULL;
    }
  }
}
int Consultar(Cola *cola){
  if(cola->primero){
    return cola->primero->cosa;
  } else {
    return NULL;
  }
}
void DestruirCola(Cola *cola){
  while(cola->primero){
    Desencolar(cola);
  }
  free(cola);
}
