#include <stdlib.h>
#include <stdio.h>
#include <string.h>
/*Aquí llamo a las funciones*/

/*

Ejemplo 1: Empresa de servicios de limpieza

Se tiene un listado de servicios de lavandería con la siguiente información: servicio y
precio.

Todos los que acceden tienen un código de cliente, durante el día realiza el pedido
de por medio de una App: código de cliente, servicio y cantidad de prendas, llega a la
lavandería por medio de un delivery.

 Toda esta información se va apilando y los pedidos se
aceptan hasta las 15hs. Ahí en ese momento hay un cierre para realizar la planificación de
las tareas de la lavandería, en ese momento se desapila los pedidos y se genera una lista
de trabajo(entrega) con la siguiente información: código de cliente, servicio, cantidad de prendas y
monto a abonar.
Además sobre esta lista de trabajo se desea saber, ( se debe recorrer en forma
recursiva):
● Cantidad de cliente
● Cantidad de dinero recaudado

*/

/*
  Lista: información de la lavandería: Servicio y Precio

  Pila de pedidos: Código de cliente, servicio y cantidad de prendas
  
  Lista de entrega (se arma desapilando la de pedidos): Código de cliente, servicio, cantidad de prendas y
monto a abonar.

  Lista de entrega (Sacar cantidad de clientes y dinero recaudado) // Recursivamente


  Lista de Servicio = Nodo1

  Pila de pedidos = Nodo2

  Lista de entrega = Nodo3 
*/

/*Declaración de Listas*/

typedef struct Servicio_{
  char nombre[30];
  float precio;
}Servicio_;

typedef struct Pedidos_{
  int codigoCliente;
  char servicio[30];
  int cantidadPrendas;
}Pedidos_;

typedef struct Entrega_{
  int codigoCliente;
  char servicio[30];
  int cantidadPrendas;
  int montoAbonar;
}Entrega_;

typedef struct Nodo1{
  Servicio_ servicio;    
  struct Nodo1 *siguiente;
}Nodo1;

typedef struct Nodo2{
  Pedidos_ pedidosInfo;
  struct Nodo2 *siguiente;
}Nodo2;

typedef struct Nodo3{
  Entrega_ entregaInfo;
  struct Nodo3 *siguiente;
}Nodo3;

typedef struct PilaPedidos{
  Nodo2 *raiz;
}PilaPedidos;

typedef struct ListaServicio {
  Nodo1 *cabeza;
}ListaServicio;

typedef struct ListaEntrega {
  Nodo3 *cabeza;
}ListaEntrega;

/*Funciones*/

/*Registros->Nodo->Lista/Pila*/

/*Implementando Funciones Registro*/

// Crear Nodo1
Servicio_ servicioCreador(){ // voy a devolver un registro cargado
  
  Servicio_ servicio;

  printf("Ingrese nombre del servicio:");
  gets(servicio.nombre);

  fflush(stdin);

  printf("Ingrese precio del servicio:");
  scanf("%f", &servicio.precio);

  return servicio;
}

// Crear Nodo2
Pedidos_ pedidosCreador(){
  Pedidos_ pedido;

  printf("Ingrese el codigo del cliente:");
  scanf("%i", &pedido.codigoCliente);

  printf("Ingrese la cantidad de prendas:");
  scanf("%i", &pedido.cantidadPrendas);

  fflush(stdin);

  printf("Ingrese el nombre del pedido:");
  gets(pedido.servicio);

  fflush(stdin);

  return pedido;
}


// Crear Nodo3
Entrega_ asignarPedido(Pedidos_ *pedido, int *cantidadRecuadada){
  Entrega_ entrega;

  entrega.codigoCliente = pedido->codigoCliente;
  entrega.cantidadPrendas = pedido->cantidadPrendas;
  strcpy(entrega.servicio, pedido->servicio);
  
  printf("Ingrese el monto a abonar:");
  scanf("%i", &entrega.montoAbonar);

  *cantidadRecuadada = *cantidadRecuadada + entrega.montoAbonar;

  return entrega;
}

/*Implementando Funciones Nodo*/
Nodo1* CrearNodo1(){
  Nodo1 *nodoNuevo = malloc(sizeof(Nodo1)); 
  nodoNuevo->servicio = servicioCreador();
  nodoNuevo->siguiente = NULL;

  return nodoNuevo;
}
Nodo2* CrearNodo2(){
  Nodo2 *nodoNuevo = malloc(sizeof(Nodo2)); 
  nodoNuevo->pedidosInfo = pedidosCreador();
  nodoNuevo->siguiente = NULL;

  return nodoNuevo;
}
Nodo3* CrearNodo3(Pedidos_ *pedido, int *cantidadRecuadada){
  Nodo3 *nodoNuevo = malloc(sizeof(Nodo3)); 
  nodoNuevo->entregaInfo = asignarPedido(pedido, cantidadRecuadada);
  nodoNuevo->siguiente = NULL;

  return nodoNuevo;
}

/*Crear Listas/Pilas Vacias*/

ListaServicio* CrearLista(){ // Crea una lista vacia
  ListaServicio* lista = malloc(sizeof(ListaServicio));
  lista->cabeza = NULL;
  return lista;
}
ListaEntrega* CrearListaEntregas(){ // Crea una lista vacia
  ListaEntrega* lista = malloc(sizeof(ListaEntrega));
  lista->cabeza = NULL;
  return lista;
}
PilaPedidos *CrearPila(){ // Crea una pila vacia
  PilaPedidos *pila = malloc(sizeof(PilaPedidos));
  pila->raiz = NULL;
  return pila;
}

/*Implementando Lista de Servicios*/
// Se inserta al final de Lista servicio
void CrearServicio(ListaServicio *lista){
  Nodo1 *nodoNuevo = CrearNodo1();
  if(lista->cabeza == NULL){
    lista->cabeza = nodoNuevo;
  } else {
    Nodo1 *recorrer = lista->cabeza; // crear nodo para recorrer lista hasta el final

    while(recorrer->siguiente != NULL){
      recorrer = recorrer->siguiente;
    }

    recorrer->siguiente = nodoNuevo;
  }
}

/*Pila de pedido*/
void Apilar(PilaPedidos *pila){
  Nodo2 *nodoNuevo = CrearNodo2();
  if(pila->raiz == NULL){
    pila->raiz = nodoNuevo;
  } else {
    nodoNuevo->siguiente = pila->raiz; // crear nodo para recorrer lista hasta el final
    pila->raiz = nodoNuevo;
  }
}

// Luego se usa para la Lista de Entrega
Pedidos_ Desapilar(PilaPedidos *pila){
  if(pila->raiz != NULL){
    Nodo2 *borrar = pila->raiz;
    pila->raiz = pila->raiz->siguiente;
    return borrar->pedidosInfo;
    free(borrar);
  }
}

/*Lista de entrega*/
void AñadirEntrega(ListaEntrega *lista, Pedidos_ *pedidos, int *cantidadClientes, int *cantidadRecaudada){
  Nodo3 *nodoNuevo = CrearNodo3(pedidos, cantidadRecaudada);
  if(lista->cabeza == NULL){
    lista->cabeza = nodoNuevo;
  } else {
    Nodo3 *recorrer = lista->cabeza; // crear nodo para recorrer lista hasta el final

    while(recorrer->siguiente != NULL){
      recorrer = recorrer->siguiente;
    }

    recorrer->siguiente = nodoNuevo;
  }
  *cantidadClientes++;
}

/*Además sobre esta lista de trabajo se desea saber, ( se debe recorrer en forma
recursiva):
● Cantidad de cliente
● Cantidad de dinero recaudado
*/

/*
  & = *
*/

void recorrerRecursivo(ListaEntrega *lista_entregas, PilaPedidos *pila, int *cantidadClientes, int *cantidadRecaudada){
  // vacio a la pila
  Pedidos_ pedidos = Desapilar(pila); // -1
  AñadirEntrega(lista_entregas, &pedidos, cantidadClientes, cantidadRecaudada);
  
  // Llamo recursivo
  if(pila->raiz != NULL){ // != 0
    recorrerRecursivo(lista_entregas, pila, cantidadClientes, cantidadRecaudada);
  }
  // No se cumple si pila->raiz == NULL
}


void DestruirListaServicio(ListaServicio *lista){
  lista->cabeza = NULL;
  free(lista);
}

void DestruirListaEntrega(ListaEntrega *lista){
  lista->cabeza = NULL;
  free(lista);
}

void DestruirPila(PilaPedidos *pila){
  pila->raiz = NULL;
  free(pila);
}

int main(){
  ListaServicio *lista_servicio = CrearLista();
  PilaPedidos *pila_pedidos = CrearPila();
  ListaEntrega *lista_entregas = CrearListaEntregas();
  int flag = 1;

  /*Cargamos los servicios*/
  while(flag){
    fflush(stdin);
    CrearServicio(lista_servicio);
    printf("Queres seguir insertando bro?");
    scanf("%i", &flag);
  }

  flag = 1;
  /*Cargamos los pedidos*/
  while(flag){
    fflush(stdin);
    Apilar(pila_pedidos);
    printf("Son las 15:00 bro?");
    scanf("%i", &flag);
  }

  /*Llamo a la recursiva*/
  int cantidadRecaudada = 0; // Creo unos acumuladores
  int cantidadClientes = 0;
  printf("Lista de Entregas:\n");

  recorrerRecursivo(lista_entregas, pila_pedidos, &cantidadClientes, &cantidadRecaudada);

  printf("Cantidad Recaudad: %i", cantidadRecaudada);
  printf("Cantidad Clientes: %i", cantidadClientes);

  DestruirListaServicio(lista_servicio);
  DestruirPila(pila_pedidos);
  DestruirListaEntrega(lista_entregas);
}