#ifndef stackTDA
#define stackTDA

#define Pila struct Stack
#define P_Pila struct Stack*

struct Stack{
    int *valores;
    int postope;
};


void InicializarPila(P_Pila p);
void Apilar(P_Pila p, int dato);
int Desapilar(P_Pila p);
int Tope(P_Pila p);
int PilaVacia(P_Pila p);
void Leer (P_Pila p);
void Mostrar(P_Pila p);

#endif