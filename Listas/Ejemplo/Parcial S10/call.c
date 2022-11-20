#include "functions.c"

/*
  Nota: No hace falta el stdbool.h pero si se lo sacan tenes que hacer cambios por integers.
  (lo hice con bool pq estoy acostumbrado a otro paradigma con mas datos primitivos que int,float,char,double)

  Lista ordenada por codigo interono.
    1) Codigo aduanero
    2) Fecha de ingreso a la aduana
    3) Lugar de origen [20]
    4) Despachante [20]
    5) Destino [30]
    6) Destinario [20]
    7) DNI del destinario
    8) Peso del paquete
    9) Impuesto

  Guardamos en una cola depósitos nuevos para ser agregados al listado principal.

  Comienza la antención al publico y cada ves que se presenta alguien a buscar un paquete,
  se busca en la lista por número de DNI y se el producto (removiendolo de la lista) y se
  cobra el impuesto correspondiente.

  Debe informarse lo recaudado por impuestos y recorrer el listado para remover y apilor
  los elementos que hace 20 dias llegaron y no fueron retirados
*/

/*MAIN*/

int main(){
  /*Voy añadiendo a la cola los nuevos depositos*/
  Cola *depositos_nuevos = CrearCola();
  paquete_item *paquete;
  
  fflush(stdin);
  usandoCola(depositos_nuevos, paquete);
   
  /*Saco de la cola y envio a la lista*/
  Lista *lista_depositos = CrearLista();

  while(depositos_nuevos->primero != NULL){
    paquete_item paquete_deposito_nuevo = Consultar(depositos_nuevos);
    AñadirNodoFinal(lista_depositos, paquete_deposito_nuevo);
    Desencolar(depositos_nuevos);
  }

  int flag = 1;
  while(flag == 1){
    printf("\nBusqueda de paquete\n");
    printf("Quiere continuar:");
    scanf("%i", &flag);

    int dni_destinario = 0;
    printf("Ingrese el DNI del destinario a buscar su paquete:");
    scanf("%i", &dni_destinario);

    paquete_item paquete_deposito = BuscarListaPaquete(lista_depositos, dni_destinario);
    
    printf("DNI DEL DESTINARIO: %i", paquete_deposito.dni_Destinario);
    printf("\nNombre del despachante: %s", paquete_deposito.despachante);
  }

  Pila *pila = CreatePila();
  /*TODO Añadir Precio por envio a los struct*/
  int precioPorEnvio = 1500;
  float recaudadoTotal = 0;

  while(lista_depositos->cabeza != NULL){
    paquete_item paquete = BorrarPrimero(lista_depositos);
    /*TODO Aca se podria consultar el tiempo que llevan en el deposito*/
    recaudadoTotal = precioPorEnvio * paquete.porcentajeImpuesto/100.0;
    Apilar(pila, &paquete);
  }

  

  return 0;
}
