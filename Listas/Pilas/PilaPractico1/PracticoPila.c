#include "pila.c"
// Funciones contenidas por la pila:
  // InicializarPila
  // Apilar
  // Desapilar
  // Mostrar
  // Leer
  // Tope
  // PilaVacia

int main(){

  int selectedExercise;
  printf("Ingrese que ejercicio quiere ver(1-9):");
  scanf("%i", &selectedExercise);

  switch(selectedExercise){

  case 1:
    printf("Cargar desde teclado una pila DADA y pasar a la pila DISTINTOS todos aquellos elementos disntintos al valor 8.\n");

    Pila Dada, Distintos;
    InicializarPila(&Dada);
    InicializarPila(&Distintos);

    while(Tope(&Dada) != TamanoPila){
      Leer(&Dada);
      if (Desapilar(&Dada) != 8){
        Apilar(&Distintos, 8);
      }
    }

    printf("---Pila Dada---\n");
    Mostrar(&Dada);
    printf("---Pila distintos a 8---\n");
    Mostrar(&Distintos);

    Liberar(&Dada);
    Liberar(&Distintos);

    break;

  case 2:
    printf("Cargar desde teclado la pila Origen e Inicializar en vacio la pila DESTINO. Pasar los elementos de la pila ORIGEN a la pila DESTINO, pero dejandolos en el mismo orden.\n");
    Pila Origen, Destino, Auxiliar;

    InicializarPila(&Destino); // pila en 0
    InicializarPila(&Origen);
    InicializarPila(&Auxiliar);

    while(Tope(&Origen) != TamanoPila)
      Leer(&Origen); // cargo origen

    while(Tope(&Auxiliar) != TamanoPila)
      Apilar(&Auxiliar, Despilar(&Origen)); // Origen Tope -> Inicio de Auxiliar

    while(Tope(&Destino) != TamanoPila)
      Apilar(&Destino, Desapilar(&Auxiliar)); // Tope de Auxiliar (Inicio de Origen) -> Incio de Destino

    Mostrar(&Origen);
    printf("---PIla Destino---\n");
    Mostrar(&Destino);

    Liberar(&Destino);
    Liberar(&Origen);
    Liberar(&Auxiliar);

  case 3:
    printf("Cargar desde el teclado la pila DADA. Invertir la pila de manera que DADA contenga los elementos cargados originalmente en ella, pero en orden inverso.");
    Pila Dada, Auxiliar;

    InicializarPila(&Dada);
    InicializarPila(&Auxiliar);

    while(Tope(&Dada) != TamanoPila){
      Leer(&Dada);
    }
    while(Tope(&Auxiliar) != TamanoPila)
      Apilar(&Auxiliar, Desapilar(&Dada));

    printf("---Pila Dada---\n");
    Mostrar(&Dada);

    Dada = Auxiliar;

    printf("---Pila Dada Invertida---\n");
    Mostrar(&Dada);

    Liberar(&Dada);
    Liberar(&Auxiliar);

case 4:
  printf("Pasar el primer elemento (tope) de la pila DADA a su ultima posicion (base), dejando los restantes elementos en el mismo orden.");



  default:
    break;
  }
  return 0;
}