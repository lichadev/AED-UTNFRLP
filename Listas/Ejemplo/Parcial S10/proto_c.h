#ifndef proto_c
#define proto_c
typedef struct paquete_item{
  int codigoAduanero;
  int dni_Destinario;
 int fechaIngreso[3]; // [0] = dia [1] = mes [2] = año
  char lugarOrigen[20];
  char despachante[20];
  char destino[30];
  char destinario[20];
  int pesoPaquete; // esto mucho la verdad no lo entendi asi que lo tomo como un int
  float porcentajeImpuesto; 
}paquete_item;

typedef struct Nodo {
  paquete_item paquete;
  struct Nodo *siguiente;
}Nodo;

typedef struct Lista{
  Nodo *cabeza;
}Lista;

typedef struct Cola{
  Nodo *primero;
  Nodo *ultimo;
}Cola;

/*Funcion main*/
void usandoCola(Cola *cola, paquete_item *paquete);

/*Funcion struct paquete_item*/
void paqueteCreator(paquete_item *paquete);
void paqueteAsignator(Nodo *nodo, paquete_item *paqueteAsignable);

/*Funciones Nodo*/
Nodo* CreateNodo(paquete_item *paquete);
void DestroyNode(Nodo *nodo);

/*Funciones para Lista Enlazada*/
Lista* CreateLista();
Nodo *CreateNodoLista(paquete_item *paquete);
void DestroyLista(Lista *lista);
void AñadirNodoFinal(Lista *lista, paquete_item);
void AñadirNodoInicio(Lista *lista, paquete_item);
void BorrarUltimo(Lista *lista);
void BorrarPrimero(Lista *lista);
paquete_item BuscarListaPaquete(Lista *lista, int DNI_destinatario);

/*Funciones para Cola*/
void Encolar(Cola *cola, paquete_item paquete);
Cola* CrearCola();
void DestroyCola(Cola *cola);
void Desencolar(Cola *cola);
paquete_item Consultar(Cola *cola);
#endif