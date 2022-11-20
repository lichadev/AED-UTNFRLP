#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "proto_c.h"

/*Implementando funciones para main*/
void usandoCola(Cola *depositos_nuevos, paquete_item *paquete){
  char flag = 'a';
  if(flag == 'a'){
    Encolar(depositos_nuevos, *paquete);
    fflush(stdin);
    printf("Ingrese A si quiere continuar o B si quiere salir: ");
    scanf("%c", &flag);
    //usandoCola(depositos_nuevos, paquete);
  }
}

/*Implementando funciones para Paquete*/
void paqueteCreator(paquete_item *paquete){

  printf("Bienvenido al sistema de carga de paquetes!\n");

  printf("Ingrese el Codigo Aduanero del paquete:");
  scanf("%i", &paquete->codigoAduanero);
  
  printf("Ingrese el DNI del destinario:");
  scanf("%i", &paquete->dni_Destinario);

  printf("Ingrese el peso del paquete:");
  scanf("%i", &paquete->pesoPaquete);

  printf("Ingrese el porcentaje impuesto al paquete:");
  scanf("%f", &paquete->porcentajeImpuesto);

  printf("Ingrese el año en que se ingreso este paquete:");
  scanf("%i", &paquete->fechaIngreso[2]);

  printf("Ingrese el mes en que se ingreso este paquete:");
  scanf("%i", &paquete->fechaIngreso[1]);

  printf("Ingrese el dia en que se ingreso este paquete:");
  scanf("%i", &paquete->fechaIngreso[0]);

  fflush(stdin);
  
  printf("Ingrese el lugar de origen:");
  fgets(paquete->lugarOrigen, 20, stdin);

  printf("Ingrese el despachante:");
  fgets(paquete->despachante, 20, stdin);

  printf("Ingrese el destino:");
  fgets(paquete->destino, 30, stdin);

  printf("Ingrese el destinario:");
  fgets(paquete->destinario, 20, stdin);

}
void paqueteAsignator(Nodo *nodo, paquete_item *paqueteAsignable){
  nodo->paquete.codigoAduanero = paqueteAsignable->codigoAduanero;
  nodo->paquete.dni_Destinario = paqueteAsignable->dni_Destinario;
  nodo->paquete.pesoPaquete = paqueteAsignable->pesoPaquete;
  nodo->paquete.porcentajeImpuesto = paqueteAsignable->porcentajeImpuesto;
  for(int i=0; i<3; i++)
    nodo->paquete.fechaIngreso[i] = paqueteAsignable->fechaIngreso[i];
  strcpy(nodo->paquete.destino, paqueteAsignable->destino);
  strcpy(nodo->paquete.despachante, paqueteAsignable->despachante);
  strcpy(nodo->paquete.lugarOrigen, paqueteAsignable->lugarOrigen);
  strcpy(nodo->paquete.destinario, paqueteAsignable->destinario);
}


/*Implementando funciones para Nodo*/
Nodo* CreateNodo(paquete_item *paquete){
  Nodo *nodo = malloc(sizeof(Nodo));
  nodo->siguiente = NULL;
  paqueteCreator(&nodo->paquete);
  return nodo;
}
Nodo *CreateNodoLista(paquete_item *paquete){
  Nodo *nodo = malloc(sizeof(Nodo));
  nodo->siguiente = NULL;
  paqueteAsignator(nodo, paquete);
  return nodo;
}
void DestroyNode(Nodo *nodo){
  Nodo *borrar = nodo;
  nodo = nodo->siguiente;
  free(borrar);
}

/*Implementando funciones lista enlazada*/
void AñadirNodoFinal(Lista *lista, paquete_item paquete){
  Nodo* nodoNuevo = CreateNodoLista(&paquete);

  if(lista->cabeza == NULL){
    lista->cabeza=nodoNuevo;
    nodoNuevo->siguiente = NULL;
  } else {
    Nodo* recorrer = lista->cabeza;

    while(recorrer->siguiente != NULL){
      recorrer = recorrer->siguiente;
    }

    recorrer->siguiente = nodoNuevo;
  }
}
void AñadirNodoInicio (Lista *lista, paquete_item paquete_item){
  Nodo* nodoNuevo = CreateNodo(&paquete_item);
  if(lista->cabeza == NULL){
    lista->cabeza=nodoNuevo;
    nodoNuevo->siguiente = NULL;
  } else {
    nodoNuevo->siguiente = lista->cabeza;
    lista->cabeza = nodoNuevo;
  }
}
Lista* CrearLista(){
  Lista* lista = malloc(sizeof(Lista));
  lista->cabeza = NULL;
  return lista;
}
void DestroyLista(Lista *lista){
  while(lista->cabeza != NULL){
    BorrarUltimo(lista);
  }
  free(lista);
}
void BorrarUltimo(Lista *lista){
  if(lista->cabeza){
    Nodo *borrar = lista->cabeza;
    Nodo *recorrer = lista->cabeza;
    while(recorrer->siguiente->siguiente != NULL){
      recorrer = recorrer->siguiente;
    }
    borrar = recorrer->siguiente;
    borrar->siguiente = NULL;
    free(borrar);
  }
}
paquete_item BorrarPrimero(Lista *lista){
  if(lista->cabeza){
    Nodo *borrar = lista->cabeza;
    lista->cabeza = lista->cabeza->siguiente;
    return borrar->paquete;
    free(borrar);
  }
}
paquete_item BuscarListaPaquete(Lista *lista, int DNI_destinatario){
  Nodo *recorrer = lista->cabeza;
  Nodo *borrar = NULL;
  bool paqueteEncontrado = false;

  /*Busco si el siguiente es distinto de NULL y si el paquete no fue encontrado*/

  while(recorrer->siguiente != NULL){
    if(paqueteEncontrado == false){
      /*si el siguiente tiene el paquete puedo borrarlo con más facilidad.*/

      if(recorrer->siguiente->paquete.dni_Destinario == DNI_destinatario) {

        /*Debo verificar si tiene un nodo siguiente o si es el último*/

        if(recorrer->siguiente->siguiente != NULL){
          /*
            Si lo tiene apunto a el con borrar y hago que el recorrer siguiente 
            tenga ahora al siguiente del borrado. Esto para evitar romper la lista.
          */
          borrar = recorrer->siguiente;
          recorrer->siguiente = recorrer->siguiente->siguiente;
        } else {
          /*Si el siguiente del que voy a borrar es NULL, solo lo borro y listo*/
          borrar = recorrer->siguiente;
          recorrer->siguiente = NULL;
        }
        paqueteEncontrado = true;
      }
    }

    recorrer = recorrer->siguiente;
  }
  
  free(borrar);
  return recorrer->paquete;
}

/*Implementando funciones Cola*/
void Encolar(Cola *cola, paquete_item paquete){
  Nodo *nodoNuevo = CreateNodo(&paquete);

  if(cola->primero == NULL){
    cola->primero = nodoNuevo;
    cola->ultimo = nodoNuevo;
  } else {
    cola->ultimo->siguiente = nodoNuevo;
    cola->ultimo = nodoNuevo;
  }
}
Cola* CrearCola(){
  Cola *cola = malloc(sizeof(Cola));
  cola->primero = NULL;
  cola->ultimo = NULL;
  return cola;
}
void Desencolar(Cola *cola){
  if(cola->primero){
    Nodo *borrar = cola->primero;
    cola->primero = cola->primero->siguiente;
    free(borrar);

    if(cola->primero == NULL){
      cola->ultimo = NULL;
    }
  }
}
void DestroyCola(Cola *cola){
  while(cola->primero != NULL){
    Desencolar(cola);
  }
  free(cola);
}
paquete_item Consultar(Cola *cola){
  if(cola->primero != NULL) {
    return cola->primero->paquete;
  } 
}

/*Implementando funciones Pila*/
void Apilar(Pila *pila, paquete_item *paquete){
  Nodo *nuevoNodo = CreateNodoLista(paquete);
  Nodo *recorrer = pila->raiz;
  if(pila->raiz != NULL){
    while(recorrer->siguiente != NULL){
      recorrer = recorrer->siguiente;
    }
    recorrer->siguiente = nuevoNodo;
  } else {
    recorrer = nuevoNodo;
  }
}
paquete_item Desapilar(Pila *pila){
  if(pila->raiz != NULL){
    Nodo *recorrer = pila->raiz;

    while(recorrer->siguiente->siguiente != NULL){
      recorrer = recorrer->siguiente;
    }
    Nodo *borrar = recorrer->siguiente;
    paquete_item toReturn = borrar->paquete;
    borrar->siguiente = NULL;
    
    free(borrar);
    return toReturn;
  } 
}
Pila* CreatePila(){
  Pila* pila = malloc(sizeof(Pila));
  pila->raiz = NULL;
  return pila;
}
void DestroyPila(Pila *pila){
  while(pila->raiz != NULL){
    paquete_item paquete_returned = Desapilar(pila);
  }
}