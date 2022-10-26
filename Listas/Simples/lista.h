#ifndef stackTDA
#define stackTDA

typedef struct{
  int key;
  char keyManName[30];
}Key;

typedef struct {
  // aca se cambia que lleva el nodo
  Key keyExample;
  Lista *nodo_siguiente;
}Lista;

void CrearLlavero(Key *keyExample);
void IncializarLista(Lista *nodo_raiz);
void AñadirNodo(Lista *nodo_actual);
void RecorrerLista(Lista *nodo_actual);
void BuscarLlavero(Lista *nodo_actual);
void BorrarUltimo(Lista *nodo_actual);


#endif