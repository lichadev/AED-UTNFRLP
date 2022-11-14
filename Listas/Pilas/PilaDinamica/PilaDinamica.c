#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
  int my_data;
  struct Node *next;
}Node;

typedef struct Stack{
  Node* top;
  int size;
}Stack;

Node* CreateNode(int dato);
void DestroyNode(Node *node);
void Push(Stack* pila, int dato);
int SizeStack(Stack *stack);
void Pop(Stack* pila);
int Top(Stack *pila);
Stack* CreateStack();

int main(){
  Stack *pila = CreateStack();
  Push(pila, 10);
  Push(pila, 20);
  Push(pila, 30);
  Push(pila, 40);
  Push(pila, 50);
  printf("Longitud: %d\n", SizeStack(pila));
  while(SizeStack(pila) != 0){
    printf("Tope Actual: %d\n", Top(pila));
    Pop(pila);
  }
}

Stack* CreateStack(){
  Stack *stack = malloc(sizeof(Stack));
  stack->top = NULL;
  stack->size = 0;
  return stack;
}
int SizeStack(Stack *stack){
  return stack->size;
}
void DestroyPila(Stack* stack){
  while(stack->top != NULL)
    Pop(stack);

  free(stack);
}
int Top(Stack *pila){
  if (pila == NULL) return 0;
  else return pila->top->my_data;
}
Node* CreateNode(int dato){
  Node *nuevoNodo = malloc(sizeof(Node));
  nuevoNodo->my_data = dato;
  nuevoNodo->next = NULL;
  return nuevoNodo;
}
void DestroyNode(Node *node){
  node->next = NULL;
  free(node);
}
void Push(Stack* pila, int dato){
  Node *nodo = CreateNode(dato);
  nodo->next = pila->top;
  pila->size++;
  pila->top = nodo;
}
void Pop(Stack* pila){
  if(pila->top != NULL){
    Node *delete = pila->top;
    pila->top = pila->top->next;
    pila->size--;
    DestroyNode(delete);
  }
}