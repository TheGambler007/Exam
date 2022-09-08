/* Escribir un programa que permita definir una estructura 
que contenga un entero.
Utilizando la estructura anterior definir una estructura
de datos para una Lista implementada como COLA.
Cargar la lista de forma manual.
Imprimir la lista.  */
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct {
     int Nro;} t_elemento;   //estructura para elementos

struct lista{      //Estructura para el Nodo de la Lista
  t_elemento dato;
  struct lista *sgte;
};
typedef struct lista t_lista;    //Tipo de dato nuevo
typedef t_lista *ptr_lista;    // Apuntador al Tipo de Dato nuevo

void insertar(t_elemento, ptr_lista *,  ptr_lista *);
void imprimir(t_lista *);

main(){
  t_lista *L=NULL,*F=NULL;   //Apuntador principal de la lista
  t_elemento E;
  char opc= ' ';
  do{
	 system("cls");
	 printf("\nDesea incluir un registro en la lista ? [s/n] : ");
	 opc=tolower(getch());
	 if(opc=='s'){
		printf("\n\nDigite un valor entero : ");
		scanf("%d",&E.Nro);
    	insertar(E,&L,&F);
		printf("\n\nElemento guardado . . .");
		getch();
	 }
  } while(opc!='n');
  
  system("cls");
  printf("\n\nImpresion de la Lista : \n");
  if(L==NULL){
	 printf("\nLa lista esta vacia . . ");  }
  else{
	 imprimir(L);  }
  printf("\n\nF I N ......\n\n");
  system("pause");
}
/* F U N C I O N E S */
void insertar(t_elemento X, ptr_lista *Q, ptr_lista *QF){
  t_lista *aux;
  aux=(t_lista *) malloc(sizeof(struct lista));
  aux->dato = X;
  aux->sgte=NULL;
  if((*Q)==NULL){
     (*Q)= aux;
	 (*QF) = aux;
  }
  else{
       
	 (*QF)->sgte = aux;
	 (*QF) = aux;
  }
}

void imprimir(t_lista *Q){
   while(Q!=NULL){
	 printf("\n%6d\n",Q->dato.Nro);
	 Q=Q->sgte;  }
}
