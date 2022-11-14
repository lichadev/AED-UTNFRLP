#ifndef stackTDA
#define stackTDA

typedef struct Key{
  int key;
  char keyManName[30];
}Key;

typedef struct Nodo{
  // aca se cambia que lleva el nodo
  Key keyExample;
  struct Nodo *nodo_siguiente;
}Nodo;


typedef struct Lista{
  Nodo* cabeza;
}Lista;

void AñadirNodoInicio(Lista *lista, int key, char* keyMan);
void AñadirNodoFinal(Lista *lista, int key, char* keyMan);
void RecorrerLista(Nodo *nodo_actual);
void EliminarPrimero(Lista *lista);
void EliminarUltimo(Lista *lista);


#endif