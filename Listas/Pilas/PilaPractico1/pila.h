#define Pila struct _Pila
#define P_Pila struct _Pila *

struct _Pila
{
    int *valores;
    int postope;
};

void InicializarPila(P_Pila p, uint16 TAM);
void Apilar(P_Pila p, int dato);
int desapilar(P_Pila p);
int tope(P_Pila p);
int pilavacia(P_Pila p);
void Leer (P_Pila p);
void Mostrar(P_Pila p);